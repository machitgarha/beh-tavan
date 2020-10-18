#include "output.hpp"

using namespace BehTavan;
using namespace BehTavan::Output;

void Output::printStartMessage()
{
    printLine("Welcome to BehTavan!");
    printLine("A simple program to show you how we can optimize a power function.");
    printLine("This is a free program: Licensed under GPLv3.");
    printNewLine();

    printLine("It raises a base number to one or more exponents using two power");
    printLine("functions, using normal and optimized algorithms, and measures");
    printLine("the time taken for each one, for each exponent. Then, the results");
    printLine("are shown in a simple table.");
    printNewLine();
}
