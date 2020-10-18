#include "env.hpp"
#include "input.hpp"
#include "output.hpp"
#include "types.hpp"
#include "execution.hpp"
#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using namespace BehTavan::TimeMeasuring;

int main()
{
    Output::printStartMessage();

    const bool interactive = Env::isInteractive();

    const Base base = Input::getBase(interactive);
    const ExponentVector exponents = Input::getExponents(interactive);

    PowerFunctionInfoVector powerFuncsInfo = getAllPowerFunctionsInfo();
    ExecutionResultTable resultTable(powerFuncsInfo);

    using TimeUnit = TimeUnit::Nanoseconds;

    // Print information about the table
    printVarVal(base);
    printLine3("Time unit is in ", getPrintableTimeUnit<TimeUnit>(), "s.");
    printNewLine();

    // Fill the table with data
    try {
        for (size_t exponent : exponents) {
            resultTable.addRow(
                exponent,
                execute<TimeUnit>(powerFuncsInfo, base, exponent)
            );
        }
    } catch (std::runtime_error &e) {
        printLine2("Runtime error: ", e.what());
    }

    // Print the table
    std::cout << resultTable;

    return 0;
}
