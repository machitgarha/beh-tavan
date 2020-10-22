#ifndef BEH_TAVAN_TIME_MEASURE_HPP
#define BEH_TAVAN_TIME_MEASURE_HPP

#include <cstddef>
#include <chrono>
#include <stdexcept>

#include "functions/base.hpp"

namespace BehTavan::TimeMeasuring
{
    using namespace Functions;

    // Time units
    namespace TimeUnit
    {
        using Seconds = std::chrono::seconds;
        using Milliseconds = std::chrono::milliseconds;
        using Microseconds = std::chrono::microseconds;
        using Nanoseconds = std::chrono::nanoseconds;
    }

    using ExecutionTime = size_t;

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
}

#endif // BEH_TAVAN_TIME_MEASURE_HPP
