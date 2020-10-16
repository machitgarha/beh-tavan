#ifndef BEH_TAVAN_TIME_MEASURE_HPP
#define BEH_TAVAN_TIME_MEASURE_HPP

#include <cstddef>
#include <chrono>
#include <utility>

namespace BehTavan::TimeMeasuring
{
    using _TimePoint = std::chrono::high_resolution_clock::time_point;

    // Time units
    namespace TimeUnit
    {
        using Nanoseconds = std::chrono::nanoseconds;
        using Microseconds = std::chrono::microseconds;
        using Milliseconds = std::chrono::milliseconds;
        using Seconds = std::chrono::seconds;
    }

    /**
     * A function to measure execution time of a function.
     *
     * @param func The function gets executed.
     * @param args The arguments forwarded to the function.
     * @return How long the execution of the function took, in the specified unit.
     */
    template<typename TimeUnit, typename Function, typename... FunctionArgs>
    constexpr inline size_t measureFuncExecTime(Function func, FunctionArgs&&... args)
    {    
        _TimePoint t1 = std::chrono::high_resolution_clock::now();
        func(std::forward<FunctionArgs>(args)...);
        _TimePoint t2 = std::chrono::high_resolution_clock::now();

        return std::chrono::duration<TimeUnit>(t2 - t1).count();
    }
}

#endif // BEH_TAVAN_TIME_MEASURE_HPP
