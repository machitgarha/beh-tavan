#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"

// For children
#include "function-info.hpp"
#include "env.hpp"

#include "time-measuring.hpp"
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
         * Console table specifically for representing execution time results.
         */
        class ExecutionTimeResultConsoleTable: public StandardConsoleTable
        {
        public:
            /**
             * Constructor.
             *
             * Creates the table, and prepares the table header, based on the given input.
             *
             * @param firstColumnName The title of the changing values in the first column.
             * @param funcsInfo Information list of functions being worked on.
             */
            inline ExecutionTimeResultConsoleTable(
                const std::string &&firstColumnName,
                const FunctionInfoVector<
                    ReturnType,
                    ArgTypes...
                > &funcsInfo
            ): colCount(funcsInfo.size())
            {
                this->addHeader(std::move(firstColumnName), std::move(funcsInfo));
            }

            /**
             * Add a new row, consisting a new record.
             *
             * @param recordInputValue The first cell value, which is the variable input
             * changing between records.
             * @param execTimes Execution times of each function, sorted as the functions
             * information passed to the constructor.
             */
            template<typename Value>
            inline void addRow(
                Value recordInputValue,
                TimeMeasuring::ExecutionTimeVector &&execTimes
            ) {
                if (execTimes.size() != colCount) {
                    throw std::invalid_argument(
                        "Execution times count does not equal functions count"
                    );
                }

                // First cell
                (*this)[this->curRow][0] = recordInputValue;

                for (size_t i = 0; i < this->colCount; i++) {
                    (*this)[this->curRow][i + 1] = execTimes[i];
                }

                // Go to next row, for the next call
                this->curRow++;
            }

        protected:
            using StandardConsoleTable::addRow;

        private:
            /** Column count, based on the number of functions. */
            const size_t colCount;

            /** Current index row. First and second rows are for header. */
            size_t curRow = 2;

            /**
             * Fills the header of the given table, including the first two rows.
             */
            void addHeader(
                const std::string &&firstColumnName,
                const FunctionInfoVector<
                    ReturnType,
                    ArgTypes...
                > &&funcsInfo
            ) {
                // First row
                (*this)[0][0] = "Functions:";
                for (size_t i = 0; i < this->colCount; i++) {
                    (*this)[0][i + 1] = funcsInfo[i].name;
                }

                // Second row
                (*this)[1][0] = firstColumnName;
            }
        };
    };
}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
