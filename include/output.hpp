#ifndef BEH_TAVAN_OUTPUT_HPP
#define BEH_TAVAN_OUTPUT_HPP

#include <iostream>

#include "nameof.hpp"

#define printNewLine() std::cout << std::endl
#define printLine(a) std::cout << a << std::endl

#define printVarVal(var) printLine(NAMEOF(var).str() << " = " << var)

namespace BehTavan::Output
{
    /**
     * Prints a simple message supposed to be at the start of the program.
     */
    void showStartMessage();
}

#endif // BEH_TAVAN_OUTPUT_HPP
