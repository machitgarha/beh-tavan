#ifndef BEH_TAVAN_TYPES_HPP
#define BEH_TAVAN_TYPES_HPP

#include <array>

namespace BehTavan::Types
{
    using Int32 = long int;
    using Int64 = long long int;

    using UInt32 = unsigned long int;
    using UInt64 = unsigned long long int;

    template<typename T, std::size_t size>
    using Array = std::array<T, size>;
}

#endif // BEH_TAVAN_TYPES_HPP
