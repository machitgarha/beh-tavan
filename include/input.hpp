#ifndef BEH_TAVAN_INPUT_HPP
#define BEH_TAVAN_INPUT_HPP

#include "types.hpp"

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

namespace BehTavan::Input
{
    /**
     * Returns a base number.
     *
     * @param interactive Whether the value is user supplied or not.
     */
    Base getBase(bool interactive = true);

    /**
     * Returns a list of exponent numbers.
     *
     * @param interactive Whether the value is user supplied or not.
     */
    ExponentVector getExponents(bool interactive = true);
}

#endif // BEH_TAVAN_INPUT_HPP
