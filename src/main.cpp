#include "env.hpp"
#include "input.hpp"
#include "output.hpp"
#include "types.hpp"
#include "execution.hpp"
#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using namespace BehTavan::TimeMeasuring;

using ExponentVector = std::vector<Exponent>;

int main()
{
    Output::showStartMessage();

    const bool interactive = Env::isInteractive();

    const Base base = Input::getBase(interactive);
    const ExponentVector exponents = Input::getExponents(interactive);

    PowerFunctionInfoVector powerFuncsInfo = getAllPowerFunctionsInfo();
    ExecutionResultTable resultTable(powerFuncsInfo);

    for (size_t exponent : exponents) {
        resultTable.addRow(
            exponent,
            execute(powerFuncsInfo, base, exponent)
        );
    }

    std::cout << resultTable;

    return 0;
}
