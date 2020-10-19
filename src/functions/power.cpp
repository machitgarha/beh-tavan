#include "functions/power.hpp"

#include <stdexcept>

using namespace BehTavan;

/**
 * Throws exceptions in the case of bad inputs.
 *
 * The only invalid case is 0^0.
 */
static inline void handleInvalidCases(Base base, Exponent exponent);

Int64 BehTavan::power(Base base, Exponent exponent)
{
    handleInvalidCases(base, exponent);

    Int64 result = 1;
    for (Base i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}

Int64 BehTavan::powerOptimized(Base base, Exponent exponent)
{
    handleInvalidCases(base, exponent);

    if (exponent == 0) {
        return 1;
    }
    if (base == 0 || base == 1) {
        return base;
    }
    // base >= 2
    // exponent >= 1

    /*
     * For more optimization, we do not define new variables for a copied version of base
     * and exponent; as we do not need them later.
     */
    Int64 remainingMul = 1;
    while (exponent != 1) {
        if (exponent % 2 == 0) {
            base *= base;
            exponent /= 2;
        } else {
            exponent--;
            remainingMul *= base;
        }
    }
    // exponent == 1

    return base * remainingMul;
}

void handleInvalidCases(Base base, Exponent exponent)
{
    if (base == 0 && exponent == 0) {
        throw std::invalid_argument("0 raised to 0 is undefined");
    }
}
