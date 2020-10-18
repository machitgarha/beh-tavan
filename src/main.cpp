#include "env.hpp"
#include "input.hpp"
#include "output.hpp"
#include "types.hpp"
#include "time-measuring.hpp"
#include "power.hpp"
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

    ExecutionResultTable resultTable {getAllPowerFunctionsInfo()};

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
