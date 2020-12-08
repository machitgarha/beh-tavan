#include "workflows/sorting-time-comparison-workflow.hpp"

using namespace BehTavan::Workflows;

void SortingTimeComparisonWorkflow::run()
{
    const size_t n = this->getArraySize();

    std::vector<Types::UInt64> arr(n);
    // RNG

    const CurFunctionInfoVector &funcsInfo = this->getFunctionsInfo();
    // Measure
    // Print
}
