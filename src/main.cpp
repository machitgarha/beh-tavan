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

int main()
{
    StandardConsoleTable resultTable;

    // The header
    resultTable.addRow({
        static_cast<std::string>(""),
        NAMEOF(power).str(),
        NAMEOF(powerOptimized).str()
    });

    std::forward_list<size_t> exponents = {1, 2, 5, 10, 100, 1000, 10000, 100000, 1000000};
    const BehTavan::Int32 base = 3;

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
