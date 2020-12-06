#include "workflows/power.hpp"

using namespace BehTavan::Workflows;

void PowerWorkflow::run()
{
    const Power::Base &&base = this->getBase();
    const Input::Collection<Power::Exponent> &&exponents = this->getExponents();

    const auto &funcsInfo = Power::powerFuncsInfo;
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