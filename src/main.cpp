#include "output.hpp"
#include "workflows/power.hpp"

using namespace BehTavan;

int main()
{
    Output::printStartMessage();

    Workflows::PowerWorkflow w;
    w.run();

    return 0;
}
