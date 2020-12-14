#include "workflows/sorting-time-comparison-workflow.hpp"

#include <random>

using namespace BehTavan;
using namespace BehTavan::Workflows;

void SortingTimeComparisonWorkflow::run()
{
    using TimeUnit = TimeMeasuring::TimeUnit::Nanoseconds;

    const size_t n = this->getArraySize();
    std::vector<Types::UInt64> arr = this->generateRandomArray(n);

    const CurFunctionInfoVector &funcsInfo = this->getFunctionsInfo();

    ResultConsoleTable resultTable(funcsInfo);

    // Before sort
    resultTable.addRecord(
        "Time #1\n"
        "(Not sorted)",
        this->timeMeasuring.getFuncExecTimeSet<TimeUnit>(funcsInfo, arr)
    );

    Functions::Sorting::heapSort(arr);

    resultTable.addRecord(
        "Time #2\n"
        "(Sorted)",
        this->timeMeasuring.getFuncExecTimeSet<TimeUnit>(funcsInfo, arr)
    );

    print(resultTable);
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

bool SortingTimeComparisonWorkflow::TimeMeasuring::doProduceSameResults(
    const ReturnValuePair &outputs,
    const ArgSetValuePair &inputArguments
) {
    const std::vector<Types::UInt64>
        &v1 = std::get<0>(inputArguments.previous),
        &v2 = std::get<0>(inputArguments.current);

    return std::equal(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());
}
