#include "output.hpp"
#include "workflows/sorting-time-comparison-workflow.hpp"

using namespace BehTavan;

int main()
{
    Output::printStartMessage();

    Workflows::SortingTimeComparisonWorkflow w;
    w.run();

    return 0;
}
