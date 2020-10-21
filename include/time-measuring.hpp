#ifndef BEH_TAVAN_TIME_MEASURE_HPP
#define BEH_TAVAN_TIME_MEASURE_HPP

#include <cstddef>
#include <chrono>
#include <utility>
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

    using Time = size_t;

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

    /**
     * A function to measure execution time of a function.
     *
     * @param func The function gets executed.
     * @param args The arguments forwarded to the function.
     * @return How long the execution of the function took, in the specified unit.
     */
    template<typename TimeUnit, typename ReturnType, typename ...ArgTypes>
    inline Time measureFuncExecTime(
        const typename FunctionInfo<ReturnType, ArgTypes...>::FunctionType &func,
        ReturnType &result,
        ArgTypes ...args
    ) {
        using _TimePoint = std::chrono::high_resolution_clock::time_point;

        _TimePoint t1 = std::chrono::high_resolution_clock::now();
        result = func(std::forward<ArgTypes>(args)...);
        _TimePoint t2 = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
    }
}

#endif // BEH_TAVAN_TIME_MEASURE_HPP
