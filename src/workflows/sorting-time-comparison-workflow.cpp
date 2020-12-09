#include "workflows/sorting-time-comparison-workflow.hpp"

#include <random>

using namespace BehTavan;
using namespace BehTavan::Workflows;

void SortingTimeComparisonWorkflow::run()
{
    const size_t n = this->getArraySize();
    std::vector<Types::UInt64> arr(this->generateRandomArray(n));

    const CurFunctionInfoVector &funcsInfo = this->getFunctionsInfo();

    // Measure
    // Print
}

std::vector<Types::UInt64> SortingTimeComparisonWorkflow::generateRandomArray(size_t size)
{
    std::mt19937_64 randGen;
    randGen.seed(time(nullptr));

    std::vector<Types::UInt64> result(size);

    for (Types::UInt64 &i : result) {
        i = static_cast<Types::UInt64>(randGen() % this->randMax);
    }

    return result;
}
