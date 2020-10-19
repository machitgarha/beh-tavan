#ifndef BEH_TAVAN_POWER_HPP
#define BEH_TAVAN_POWER_HPP

#include <vector>
#include <string>

#include "nameof.hpp"

#include "types.hpp"

namespace BehTavan
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
     * A structure to hold properties of a power function.
     */
    struct PowerFunctionInfo
    {
        PowerFunctionPointer ptr;
        std::string name;
    };

    using PowerFunctionInfoVector = std::vector<PowerFunctionInfo>;

    /**
     * Returns all available power functions information.
     */
    inline PowerFunctionInfoVector getAllPowerFunctionsInfo()
    {
        return {
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
}

#endif // BEH_TAVAN_POWER_HPP
