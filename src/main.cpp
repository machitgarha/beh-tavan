#include "env.hpp"
#include "input.hpp"
#include "output.hpp"
#include "types.hpp"
#include "execution.hpp"
#include "console-table/execution-result-table.hpp"

#include "functions/power.hpp"

using namespace BehTavan;
using namespace BehTavan::Functions;

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

static inline Power::Base getBase(bool interactive)
{
    return Input::getNumber<Power::Base>(
        "base", BASE_DEFAULT, interactive
    );
}

static inline Input::Collection<Power::Exponent> getExponents(bool interactive)
{
    return Input::getNumberCollection<Power::Exponent>(
        "exponent", EXPONENTS_DEFAULT, interactive
    );
}

int main()
{
    Output::printStartMessage();

    const bool interactive = Env::isInteractive();

    const Power::Base &&base = getBase(interactive);
    const Input::Collection<Power::Exponent> &&exponents = getExponents(interactive);

    const auto &funcsInfo = Power::powerFuncsInfo;
    ExecutionResultTable resultTable("Functions:\n--------\nExponents", funcsInfo);

    using TimeUnit = TimeMeasuring::TimeUnit::Nanoseconds;

    // Print information about the table
    printVarVal(base);
    printLine3("Time unit is in ", getPrintableTimeUnit<TimeUnit>(), "s.");
    printNewLine();

    // Fill the table with data
    try {
        for (Power::Exponent exponent : exponents) {
            resultTable.addRow(
                exponent,
                getFuncExecTimeSet<TimeUnit>(
                    funcsInfo, std::move(base), std::move(exponent)
                )
            );
        }
    } catch (std::runtime_error &e) {
        printLine2("Runtime error: ", e.what());
    }

    // Print the table
    std::cout << resultTable;

    return 0;
}
