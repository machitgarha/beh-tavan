#ifndef BEH_TAVAN_TIME_MEASURE_HPP
#define BEH_TAVAN_TIME_MEASURE_HPP

#include <cstddef>
#include <chrono>
#include <stdexcept>

#include "types.hpp"
#include "function-info.hpp"

namespace BehTavan::TimeMeasuring
{
    // Time units
    namespace TimeUnit
    {
        using Seconds = std::chrono::seconds;
        using Milliseconds = std::chrono::milliseconds;
        using Microseconds = std::chrono::microseconds;
        using Nanoseconds = std::chrono::nanoseconds;
    }

    using ExecutionTime = Types::UInt64;

    /**
     * Returns a printable human-readable full time unit, in singular and lowercase manner.
     */
    template<typename TUnit>
    constexpr inline const char *getPrintableTimeUnit()
    {
        if (std::is_same_v<TUnit, TimeUnit::Seconds>) {
            return "second";
        }
        if (std::is_same_v<TUnit, TimeUnit::Milliseconds>) {
            return "millisecond";
        }
        if (std::is_same_v<TUnit, TimeUnit::Microseconds>) {
            return "microsecond";
        }
        if (std::is_same_v<TUnit, TimeUnit::Nanoseconds>) {
            return "nanosecond";
        }
        throw new std::invalid_argument("Invalid time unit");
    }

    using _TimePoint = std::chrono::high_resolution_clock::time_point;

    /**
     * Returns the execution time of a function, for the given input.
     *
     * @param func The function getting executed.
     * @param funcOutput Carries the output of the function after its execution. If the
     * function is void (i.e. returns nothing), then the second overload will be selected,
     * that do not need this parameter.
     * @param funcArgs The arguments forwarded to the function.
     * @return How long the execution of the function took, in the specified unit.
     */
    template<typename TimeUnit, typename ReturnType, typename ...ArgTypes>
    inline ExecutionTime getFuncExecTime(
        const typename FunctionInfo<ReturnType, ArgTypes...>::FunctionType &func,
        ReturnType &funcOutput,
        ArgTypes &&...funcArgs
    ) {
        _TimePoint t1, t2;

        t1 = std::chrono::high_resolution_clock::now();
        funcOutput = func(std::forward<ArgTypes>(funcArgs)...);
        t2 = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
    }

    /*
     * The second overload, only for functions returning void. The reason of creating it
     * is obvious: void functions do not return anything, so passing a reference to get
     * its return value is meaningless.
     *
     * This and the above version never confuses the compiler, because they differ in the
     * template parameters count. If you want to be sure, the most possible confusion
     * should be void function without parameters. In this case, the following version will
     * be chosen; because, if the first one is selected, then two problems happen: first,
     * we cannot have a reference to void, and second, the function argument count
     * mismatch, required 2, but got 1 (i.e. only the function).
     *
     * Although compiler can select the proper version correctly from function arguments,
     * however, it is always good to pass template arguments explicitly.
     */
    template<typename TimeUnit, typename ...ArgTypes>
    inline ExecutionTime getFuncExecTime(
        const typename FunctionInfo<void, ArgTypes...>::FunctionType &func,
        ArgTypes &&...funcArgs
    ) {
        _TimePoint t1, t2;

        t1 = std::chrono::high_resolution_clock::now();
        func(std::forward<ArgTypes>(funcArgs)...);
        t2 = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
    }

    /*
     * A list of execution times. As the function information list is constant, so its size
     * is constant too, thus, it is more efficient to use arrays instead of other
     * containers (e.g. vectors).
     */
    using ExecutionTimeVector = std::vector<ExecutionTime>;

    /**
     * Returns execution times of a group of functions, for the given input.
     *
     * @param funcArgs The arguments to be forwarded to each function.
     * @return List of execution times of the functions, in the specified unit (i.e. via
     * template argument), sorted the same as input function list.
     */
    template<
        typename TimeUnit,
        typename ReturnType,
        typename ...ArgTypes
    > inline ExecutionTimeVector getFuncExecTimeSet(
        const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo,
        ArgTypes ...funcArgs
    ) {
        // TODO: Maybe remove implementation to a CPP file and specialize it?

        // Function type of each function
        using FunctionType = typename FunctionInfo<ReturnType, ArgTypes...>::FunctionType;

        const size_t funcsInfoSize = funcsInfo.size();
        ExecutionTimeVector times(funcsInfoSize);

        /*
         * To ensure all functions produce the same output, we must compare their outputs
         * to be equal. However, comparing all consecutive output pairs is just enough.
         *
         * So, we need two variables for storing output of previous and current function.
         * As the first element has no previous element, so we check not being the first
         * one.
         *
         * Also, the default value of both variables is zero. Although the following this
         * rule is always good (i.e. having default values always and preventing random
         * values in random variables), but here is necessary to handle void functions. In
         * this case, there is no output, and thus, no comparisons
         */
        ReturnType prevOutput = 0, curOutput = 0;
        bool isFirstElement = true;

        for (size_t i = 0; i < funcsInfoSize; i++) {
            /*
             * Handle void functions explicitly, as the arguments count differ with the
             * non-void ones. The later have to get the output, but the former not.
             *
             * And, it should be noted that, the cost of this if is zero at runtime; since
             * it gets evaluated at compile-time (i.e. it is constexpr). As a result,
             * putting it inside the for and outside of it does not matter.
             *
             * Also, by making the following peice of code a function, the code only gets
             * duplicated. If you wonder why, try doing that.
             */
            if constexpr (std::is_void_v<ReturnType>) {
                times[i] = getFuncExecTime<TimeUnit, ArgTypes...>(
                    funcsInfo[i].func, std::forward<ArgTypes>(funcArgs)...
                );
            } else {
                times[i] = getFuncExecTime<TimeUnit, ReturnType, ArgTypes...>(
                    funcsInfo[i].func, curOutput, std::forward<ArgTypes>(funcArgs)...
                );
            }

            // Ensure all outputs are equal
            if (!isFirstElement && prevOutput != curOutput) {
                throw std::runtime_error("Functions do not produce the same output");
            }

            isFirstElement = false;
            prevOutput = curOutput;
        }

        return times;
    }
}

#endif // BEH_TAVAN_TIME_MEASURE_HPP
