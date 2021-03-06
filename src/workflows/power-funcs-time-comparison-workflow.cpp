#include "workflows/power-funcs-time-comparison-workflow.hpp"

using namespace BehTavan::Workflows;
using namespace BehTavan::TimeMeasuring;

void PowerFuncsTimeComparisonWorkflow::run()
{
    // TODO: Seperate into a function
    printLine("It raises a base number to one or more exponents using two power");
    printLine("functions, using normal and optimized algorithms, and measures");
    printLine("the time taken for each one, for each exponent. Then, the results");
    printLine("are shown in a simple table.");
    printNewLine();

    const Power::Base &&base = this->getBase();
    const Input::Collection<Power::Exponent> &&exponents = this->getExponents();

    const CurFunctionInfoVector &funcsInfo = this->getFunctionsInfo();
    ExecutionResultTable resultTable("Exponents", funcsInfo);

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
}
