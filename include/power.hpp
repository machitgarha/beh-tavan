#ifndef BEH_TAVAN_POWER_HPP
#define BEH_TAVAN_POWER_HPP

#include "types.hpp"

namespace BehTavan
{
    /**
     * Powers an integer to an integer, using a normal algorithm.
     */
    Int64 power(Int32 base, UInt32 exponent);

    /**
     * Powers an integer to an integer, using the optimized method.
     */
    Int64 powerOptimized(Int32 base, UInt32 exponent);
}

#endif // BEH_TAVAN_POWER_HPP
