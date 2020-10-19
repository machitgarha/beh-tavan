#ifndef BEH_TAVAN_POWER_HPP
#define BEH_TAVAN_POWER_HPP

#include "base.hpp"
#include "types.hpp"

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

namespace BehTavan::Functions::Power
{
    // Types used in power functions
    using Base = BehTavan::Types::Int32;
    using Exponent = BehTavan::Types::UInt32;
    using Result = BehTavan::Types::Int64;

    // All power functions must have the following prototype
    using PowerFunctionPointer = Result (*)(Base, Exponent);

    /**
     * Powers an integer to an integer, using a normal algorithm.
     */
    Result power(Base base, Exponent exponent);

    /**
     * Powers an integer to an integer, using the optimized method.
     */
    Result powerOptimized(Base base, Exponent exponent);


    using PowerFunctionInfoList = FunctionInfoList<PowerFunctionPointer>;

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
