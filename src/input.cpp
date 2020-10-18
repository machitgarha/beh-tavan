#include "input.hpp"

#include <iostream>

#include "util.hpp"

using namespace BehTavan;
using namespace BehTavan::Input;

Base getBase(bool interactive)
{
    if (!interactive) {
        return BASE_DEFAULT;
    }

    Base base;

    printLine("Please enter the base (enter 0 for default):");
    std::cin >> base;

    return base ?: BASE_DEFAULT;
}

ExponentVector getExponents(bool interactive)
{
    if (!interactive) {
        return EXPONENTS_DEFAULT;
    }

    ExponentVector result;
    Exponent tmpExponent = 1;

    printLine("Please enter the exponents (enter 0 to exit, if 0 is entered as the first");
    printLine("input, then the default value is used):");

    std::cin >> tmpExponent;
    while (tmpExponent != 0) {
        result.push_back(tmpExponent);
        std::cin >> tmpExponent;
    }

    if (result.empty()) {
        return EXPONENTS_DEFAULT;
    } else {
        return result;
    }
}