#ifndef BEH_TAVAN_POWER_HPP
#define BEH_TAVAN_POWER_HPP

#include "base.hpp"
#include "types.hpp"
#include <type_traits>

namespace BehTavan::Functions::Power
{
    // Return type
    using Result = BehTavan::Types::Int64;
    // Arguments types
    using Base = BehTavan::Types::Int32;
    using Exponent = BehTavan::Types::UInt32;

    /**
     * Powers an integer to an integer, using a normal algorithm.
     */
    Result power(Base base, Exponent exponent);

    /**
     * Powers an integer to an integer, using the optimized method.
     */
    Result powerOptimized(Base base, Exponent exponent);


    using PowerFunctionInfoList = FunctionInfoList<Result, Base, Exponent>;

    /**
     * List of information of all available power functions.
     */
    const PowerFunctionInfoList powerFuncsInfo = {
        {
            power,
            NAMEOF(power).str()
        },
        {
            powerOptimized,
            NAMEOF(powerOptimized).str()
        },
    };
}

#endif // BEH_TAVAN_POWER_HPP
