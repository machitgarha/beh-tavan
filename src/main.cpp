#include <cstdlib>
#include <forward_list>
#include <iostream>

#include "standard-console-table.hpp"
#include "types.hpp"
#include "time-measuring.hpp"
#include "power.hpp"

#include "nameof.hpp"

using namespace BehTavan;
using namespace BehTavan::TimeMeasuring;

/**
 * Prints a simple message. Supposed to be at the start of the program.
 */
static void showStartMessage();

int main()
{
    showStartMessage();

    std::forward_list<size_t> exponents = {1, 2, 5, 10, 100, 1000, 10000, 100000, 1000000};
    const BehTavan::Int32 base = 3;    

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
    using namespace std;

    cout << "Welcome to BehTavan!" << endl;
    cout << "A simple program to show you how we can optimize a power function." << endl;
    cout << "You can see the difference between the normal and the optimized one." << endl;
    cout << endl;
}
