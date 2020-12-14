#include "output.hpp"
#include "workflows/sorting-time-comparison-workflow.hpp"

using namespace BehTavan;

int main()
{
    Output::printStartMessage();

    // TODO: Improve exception handling and implement custom ones
    try {
        Workflows::SortingTimeComparisonWorkflow w;
        w.run();
    } catch (std::runtime_error &e) {
        printLine("Error!");
        printLine(e.what());
    }

    return 0;
}
