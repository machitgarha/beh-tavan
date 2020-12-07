#ifndef BEH_TAVAN_FUNCTIONS_POWER_HPP
#define BEH_TAVAN_FUNCTIONS_POWER_HPP

#include "types.hpp"
#include "function-info.hpp"

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
}

#endif // BEH_TAVAN_FUNCTIONS_POWER_HPP
