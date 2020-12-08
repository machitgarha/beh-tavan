#include "workflows/sorting-time-comparison-workflow.hpp"

#include "random-generator.hpp"

using namespace BehTavan::Workflows;

void SortingTimeComparisonWorkflow::run()
{
    size_t n = this->getArraySize();

    std::vector<Types::UInt64> arr(n);
    Farsang::RandomGenerator randGen(time(nullptr));
    for (Types::UInt64 &i : arr) {
        i = randGen.generate();
    }

    const CurFunctionInfoVector &funcsInfo = this->getFunctionsInfo();
    // Measure
    // Print
}
