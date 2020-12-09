#include "output.hpp"
#include "workflows/power-funcs-time-comparison-workflow.hpp"

using namespace BehTavan;

int main()
{
    Output::printStartMessage();

    Workflows::PowerFuncsTimeComparisonWorkflow w;
    w.run();

    return 0;
}
