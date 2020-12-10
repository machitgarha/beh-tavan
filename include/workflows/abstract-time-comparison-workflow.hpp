#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"

#include <chrono>
#include <string>

#include "function-info.hpp"
#include "env.hpp"
#include "types.hpp"
#include "console-table/standard-console-table.hpp"

namespace BehTavan::Workflows
{
    /**
     * A workflow for comparing consumed times of same-prototyped functions.
     */
    template<typename ReturnType, typename ...ArgTypes>
    class AbstractTimeComparisonWorkflow
    {
    protected:
        // Types for the instantiated function information
        using CurFunctionInfo = FunctionInfo<ReturnType, ArgTypes...>;
        using CurFunctionInfoVector = FunctionInfoVector<ReturnType, ArgTypes...>;

        /**
         * Returns the functions information to be executed and measured.
         */
        virtual const CurFunctionInfoVector &getFunctionsInfo() const = 0;

        /**
         * A utility to measure execution time of functions.
         */
        class TimeMeasuring
        {
        public:
            class TimeUnit
            {
            public:
                using Seconds = std::chrono::seconds;
                using Milliseconds = std::chrono::milliseconds;
                using Microseconds = std::chrono::microseconds;
                using Nanoseconds = std::chrono::nanoseconds;

                /**
                 * Returns a printable human-readable full time unit, in singular and
                 * lowercase form.
                 */
                template<typename TUnit>
                static constexpr inline const char *getPrintableTimeUnit()
                {
                    if constexpr (std::is_same_v<TUnit, TimeUnit::Seconds>) {
                        return "second";
                    }
                    if constexpr (std::is_same_v<TUnit, TimeUnit::Milliseconds>) {
                        return "millisecond";
                    }
                    if constexpr (std::is_same_v<TUnit, TimeUnit::Microseconds>) {
                        return "microsecond";
                    }
                    if constexpr (std::is_same_v<TUnit, TimeUnit::Nanoseconds>) {
                        return "nanosecond";
                    }
                    throw new std::invalid_argument("Invalid time unit");
                }
            };

            using ExecutionTime = Types::UInt64;

            /*
             * A list of execution times. As the function information list is constant, so
             * its size is constant too, thus, it is more efficient to use arrays instead
             * of other containers (e.g. vectors).
             */
            using ExecutionTimeVector = std::vector<ExecutionTime>;

            /**
             * Returns execution times of a group of functions, for the given input.
             *
             * @param funcArgs The arguments to be forwarded to each function.
             * @return List of execution times of the functions, in the specified unit
             * (i.e. via template argument), sorted the same as input function list.
             */
            template<typename TimeUnit>
            ExecutionTimeVector getFuncExecTimeSet(
                const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo,
                const ArgTypes &&...funcArgs
            ) {
                // TODO: Maybe remove implementation to a CPP file and specialize it?

                if (funcsInfo.empty()) {
                    throw std::invalid_argument(
                        "Functions information must at least contain one function"
                    );
                }

                const size_t funcsInfoSize = funcsInfo.size();
                ExecutionTimeVector times(funcsInfoSize);

                /*
                 * To ensure all functions produce the same output, we must compare their
                 * outputs to be equal. However, comparing all consecutive output pairs is
                 * just enough.
                 *
                 * So, we need two variables for storing output of previous and current
                 * function. As the first element has no previous element, so we check not
                 * being the first one.
                 *
                 * Also, the default value of both variables is zero. Although the
                 * following this rule is always good (i.e. having default values always
                 * and preventing random values in random variables), but here is
                 * necessary to handle void functions. In this case, there is no output,
                 * and thus, no comparisons.
                 */
                bool isFirstFunction = true;

                // TODO: Move this comment to a better place.
                /*
                 * It is supposed that function's return value is DefaultConstructible and
                 * CopyConstructible, otherwise things should not work properly.
                 *
                 * The values of the following variable is non-sense, because in first loop
                 * iteration, both will be replaced by other values.
                 */
                ReturnValuePair outputs;

                ArgSetValuePair arguments = {
                    {funcArgs...},
                    {funcArgs...},
                };

                for (size_t i = 0; i < funcsInfoSize; i++) {
                    /*
                     * Handle void functions explicitly (zero-cost), as the arguments
                     * count differ with the non-void ones. The later have to get the
                     * output, but the former not.
                     *
                     * Also, by making the following peice of code a function, the code
                     * only gets duplicated. If you wonder why, try doing that.
                     */
                    if constexpr (std::is_void_v<ReturnType>) {
                        times[i] = this->getFuncExecTime<TimeUnit>(
                            funcsInfo[i].func,
                            arguments.current
                        );
                    } else {
                        times[i] = this->getFuncExecTime<TimeUnit>(
                            funcsInfo[i].func,
                            outputs.current,
                            arguments.current
                        );
                    }

                    // Ensure all outputs are equal
                    if (
                        !isFirstFunction &&
                        !this->doProduceSameResults(outputs, arguments)
                    ) {
                        using namespace std::string_literals;

                        throw std::runtime_error(
                            "Functions "s + funcsInfo[i - 1].name + "() and " +
                            funcsInfo[i].name + "() do not produce the same results"
                        );
                    }

                    isFirstFunction = false;

                    outputs.previous = std::move(outputs.current);
                    arguments.previous = std::move(arguments.current);

                    // Get a fresh arguments list
                    arguments.current = {funcArgs...};
                }

                return times;
            }

        protected:
            /**
             * A non-void type created from ReturnType.
             *
             * If function's return type is void, then a dummy bool type is used, othersise
             * the return type. It exists to make sure we do not try to create a variable
             * (or class member) with the type of void.
             */
            using NonVoidReturnType = std::conditional_t<
                std::is_void_v<ReturnType>, bool, std::remove_reference_t<ReturnType>
            >;

            /**
             * We need to remove references, because every ArgsTuple should not have any
             * references pointing to another ArgsTuple.
             */
            using ArgsTuple = std::tuple<std::remove_reference_t<ArgTypes>...>;

            /**
             * Container to compare two output values of two same-prototyped functions.
             *
             * Pointers are used instaed of references/bare-from, because of the
             * case of ReturnType being void.
             */
            struct ReturnValuePair
            {
                NonVoidReturnType previous;
                NonVoidReturnType current;
            };
            /**
             * Container to compare two input sets of two same-prototyped functions.
             */
            struct ArgSetValuePair
            {
                ArgsTuple previous;
                ArgsTuple current;
            };

            using TimePoint = std::chrono::high_resolution_clock::time_point;

            /**
             * Returns if two same-prototyped functions produce the same results or not.
             *
             * To check this condition, it is not enough to compare the outputs (if we
             * suppose comparing outputs is implemented). Alongside outputs, all inputs
             * that are being passed by reference/pointer may change. So, for this
             * particular purpose, all outputs and modifiable inputs must be considered,
             * and we call them all results.
             *
             * As the different functions have a vast range of prototypes, it is not
             * possible to write a general checker, and it must be done manually. This
             * is the function to be implemented to perform this operation.
             *
             * @param outputs The outputs of two functions. If functions' return type is
             * void, then outputs parameter consists of two unspecified dummy booleans.
             */
            virtual constexpr bool doProduceSameResults(
                const ReturnValuePair &outputs,
                const ArgSetValuePair &inputArguments
            ) = 0;

            /**
             * Returns the execution time of a function, for the given input.
             *
             * @param func The function getting executed.
             * @param funcOutput Carries the output of the function after its execution.
             * If the function is void (i.e. returns nothing), then the second overload
             * will be selected, that do not need this parameter.
             * @param funcArgs The arguments forwarded to the function.
             * @return How long the execution of the function took, in the specified unit.
             */
            template<typename TimeUnit>
            static constexpr inline ExecutionTime getFuncExecTime(
                const typename FunctionInfo<ReturnType, ArgTypes...>::FunctionType &func,
                NonVoidReturnType &funcOutput,
                ArgsTuple &funcArgs
            ) {
                TimePoint t1, t2;

                t1 = std::chrono::high_resolution_clock::now();
                funcOutput = std::apply(func, funcArgs);
                t2 = std::chrono::high_resolution_clock::now();

                return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
            }

            /*
             * The second overload, only for functions returning void. The reason of
             * creating it is obvious: void functions do not return anything, so passing
             * reference to get its return value is meaningless.
             *
             * This and the above version never confuses the compiler, because they differ
             * in the template parameters count. If you want to be sure, the most possible
             * confusion should be void function without parameters. In this case, the
             * following version will be chosen; because, if the first one is selected,
             * then two problems happen: first, we cannot have a reference to void, and
             * second, the function argument count mismatch, required 2, but got 1 (i.e.
             * only the function).
             *
             * Although compiler can select the proper version correctly from function
             * arguments, however, it is always good to pass template arguments explicitly.
             */
            template<typename TimeUnit>
            static constexpr inline ExecutionTime getFuncExecTime(
                const typename FunctionInfo<void, ArgTypes...>::FunctionType &func,
                ArgsTuple &funcArgs
            ) {
                TimePoint t1, t2;

                t1 = std::chrono::high_resolution_clock::now();
                std::apply(func, funcArgs);
                t2 = std::chrono::high_resolution_clock::now();

                return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
            }
        };

        /**
         * Console table specifically for representing execution time results.
         *
         * Obviously, what is going to be done is, we have one or more input set to pass
         * to some functions, measure its time and output the results.
         *
         * Here, we call the set of time results for each input set a record. In other
         * words, records are input-based rather than function-based.
         */
        class ResultConsoleTable: public StandardConsoleTable
        {
        protected:
            using This = ResultConsoleTable &;

        public:
            /**
             * Orientation of the table. Specifies the table output structure and flow.
             */
            const enum class Orientation
            {
                /**
                 * Each record lives in one row (also function titles).
                 */
                ROW_BASED,
                /**
                 * Each record lives in one column (also function titles).
                 */
                COLUMN_BASED,
            } orientation;

            const size_t funcsSize;

            ResultConsoleTable(
                const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo,
                Orientation orientation = Orientation::COLUMN_BASED
            ):
                orientation(orientation),
                funcsSize(funcsInfo.size())
            {
                this->addHeader(funcsInfo);
            }

            /**
             * Adds a record to the table.
             *
             * @param inputIdentifier The identifier for distinction between input sets.
             * It can be the input set itself, only the changing input, or a phrase
             * describing it.
             */
            This addRecord(
                const std::string &inputIdentifier,
                const std::vector<typename TimeMeasuring::ExecutionTime> &record
            ) {
                if (record.size() != this->funcsSize) {
                    throw std::invalid_argument(
                        "Record size does not match functions size"
                    );
                }

                std::vector<std::string> dataSet(this->funcsSize + 1);
                dataSet[0] = inputIdentifier;

                for (size_t i = 0; i < this->funcsSize; i++) {
                    dataSet[i + 1] = std::to_string(record[i]);
                }

                if (this->orientation == Orientation::ROW_BASED) {
                    this->addRow(dataSet);
                } else {
                    this->addColumn(dataSet);
                }

                return *this;
            }

        protected:
            // addRecord must be used instead
            using StandardConsoleTable::addRow;
            using StandardConsoleTable::addColumn;

            /**
             * Fills the table header.
             */
            This addHeader(
                const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo
            ) {
                // TODO: Get the top left cell data from input
                (*this)[0][0] = "";

                for (size_t i = 0; i < this->funcsSize; i++) {
                    if (this->orientation == Orientation::ROW_BASED) {
                        (*this)[0][i + 1] = funcsInfo[i].name;
                    } else {
                        (*this)[i + 1][0] = funcsInfo[i].name;
                    }
                }

                return *this;
            }
        };
    };
}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
