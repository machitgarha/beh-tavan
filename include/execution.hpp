#ifndef BEH_TAVAN_EXECUTION_PROVIDER_HPP
#define BEH_TAVAN_EXECUTION_PROVIDER_HPP

#include <vector>

#include "time-measuring.hpp"
#include "power.hpp"

namespace BehTavan
{
    using ExecutionTime = TimeMeasuring::Time;
    using ExecutionTimeVector = std::vector<ExecutionTime>;

    /**
     * Execute all power functions and measures times taken for each one, and returns them.
     *
     * @param powerFuncsInfo Power functions information.
     * @param base The base of the power operation.
     * @param exponent The exponent of the power operation.
     * @return A list of times in the specified unit (via template argument), sorted by the
     * power functions info list given.
     */
    template<typename TimeUnit = TimeMeasuring::TimeUnit::Nanoseconds>
    ExecutionTimeVector execute(
        const PowerFunctionInfoVector &powerFuncsInfo,
        Base base,
        Exponent exponent
    );
}

#endif // BEH_TAVAN_EXECUTION_PROVIDER_HPP
