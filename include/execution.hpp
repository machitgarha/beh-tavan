#ifndef BEH_TAVAN_EXECUTION_PROVIDER_HPP
#define BEH_TAVAN_EXECUTION_PROVIDER_HPP

#include <vector>

#include "time-measuring.hpp"
#include "functions/base.hpp"

namespace BehTavan
{
    using ExecutionTime = TimeMeasuring::Time;
    using ExecutionTimeVector = std::vector<ExecutionTime>;

    /**
     * Returns execution times for a series of functions, for the given input.
     *
     * @param funcsArguments The arguments to be forwarded
     * @param exponent The exponent of the power operation.
     * @return A list of times in the specified unit (via template argument), sorted by the
     * power functions info list given.
     */
    template<typename TimeUnit, typename ReturnType, typename ...ArgTypes>
    ExecutionTimeVector execute(
        const Functions::FunctionInfoList<ReturnType, ArgTypes...> &funcsInfo,
        ArgTypes ...funcArguments
    );
}

#endif // BEH_TAVAN_EXECUTION_PROVIDER_HPP
