#include <cstdlib>
#include <vector>
#include <iostream>

#include "env.hpp"
#include "types.hpp"
#include "time-measuring.hpp"
#include "power.hpp"
#include "util.hpp"
#include "console-table/standard-console-table.hpp"

#include "nameof.hpp"

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

using namespace BehTavan;
using namespace BehTavan::TimeMeasuring;

using ExponentVector = std::vector<Exponent>;

/**
 * Prints a simple message. Supposed to be at the start of the program.
 */
static void showStartMessage();
/**
* Gets the base from the user, and returns it.
*/
static Base getBase(bool interactive = true);
/**
 * Gets a vector of exponents from the user input, and returns it.
 */
static ExponentVector getExponents(bool interactive = true);

int main()
{
    showStartMessage();

    const bool interactive = isInteractive();
    const Base base = getBase(interactive);
    const ExponentVector exponents = getExponents(interactive);

    StandardConsoleTable resultTable;

    // The header
    resultTable.addRow({
        static_cast<std::string>(""),
        NAMEOF(power).str(),
        NAMEOF(powerOptimized).str(),
    });

    for (size_t exponent : exponents) {
        resultTable.addRow({
            exponent,
            measureFuncExecTime<TimeUnit::Nanoseconds>(power, base, exponent),
            measureFuncExecTime<TimeUnit::Nanoseconds>(powerOptimized, base, exponent),
        });
    }

    std::cout << resultTable;

    return 0;
}

void showStartMessage()
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
