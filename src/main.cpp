#include "env.hpp"
#include "input.hpp"
#include "output.hpp"
#include "types.hpp"
#include "execution.hpp"
#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using namespace BehTavan::TimeMeasuring;
using namespace BehTavan::Functions::Power;

int main()
{
    Output::printStartMessage();

    const bool interactive = Env::isInteractive();

    const Base base = Input::getNumber("base", BASE_DEFAULT, interactive);
    const auto exponents = Input::getNumberCollection<Exponent>(
        "exponent", EXPONENTS_DEFAULT, interactive
    );

    const auto &funcsInfo = powerFuncsInfo;
    ExecutionResultTable resultTable(funcsInfo);

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
