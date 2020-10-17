#ifndef BEH_TAVAN_TIME_MEASURE_HPP
#define BEH_TAVAN_TIME_MEASURE_HPP

#include <cstddef>
#include <chrono>
#include <utility>

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

    /**
     * A function to measure execution time of a function.
     *
     * @param func The function gets executed.
     * @param args The arguments forwarded to the function.
     * @return How long the execution of the function took, in the specified unit.
     */
    template<
        typename TimeUnit,
        typename ReturnType,
        typename Function,
        typename... FunctionArgs
    > inline size_t measureFuncExecTime(
        ReturnType &result,
        Function func,
        FunctionArgs&&... args
    ) {
        using _TimePoint = std::chrono::high_resolution_clock::time_point;

        _TimePoint t1 = std::chrono::high_resolution_clock::now();
        result = func(std::forward<FunctionArgs>(args)...);
        _TimePoint t2 = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<TimeUnit>(t2 - t1).count();
    }
}

#endif // BEH_TAVAN_TIME_MEASURE_HPP
