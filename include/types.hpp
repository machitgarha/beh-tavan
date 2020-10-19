#ifndef BEH_TAVAN_TYPES_HPP
#define BEH_TAVAN_TYPES_HPP

#include <vector>

namespace BehTavan
{
    using Int32 = long int;
    using Int64 = long long int;

    using UInt32 = unsigned long int;
    using UInt64 = unsigned long long int;

    using Base = Int32;
    using Exponent = UInt32;
    using ExponentVector = std::vector<Exponent>;
}

#endif // BEH_TAVAN_TYPES_HPP
