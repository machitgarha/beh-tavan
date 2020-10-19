#ifndef BEH_TAVAN_POWER_HPP
#define BEH_TAVAN_POWER_HPP

#include "base.hpp"
#include "types.hpp"

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

namespace BehTavan::Functions::Power
{
    // All power functions must have the following prototype
    using PowerFunctionPointer = Int64 (*)(Base, Exponent);

    /**
     * Powers an integer to an integer, using a normal algorithm.
     */
    Int64 power(Base base, Exponent exponent);

    /**
     * Powers an integer to an integer, using the optimized method.
     */
    Int64 powerOptimized(Base base, Exponent exponent);

    /**
     * List of information of all available power functions.
     */
    const FunctionInfoCollection<PowerFunctionPointer> powerFuncsInfo = {
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
