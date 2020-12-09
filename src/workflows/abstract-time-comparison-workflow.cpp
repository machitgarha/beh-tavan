#include "workflows/abstract-time-comparison-workflow.hpp"

// For use in fluent-interface functions
#define This \
    typename AbstractTimeComparisonWorkflow<ReturnType, ArgTypes...>::ResultConsoleTable &

using namespace BehTavan;
using namespace BehTavan::Workflows;

template<typename ReturnType, typename ...ArgTypes>
AbstractTimeComparisonWorkflow<ReturnType, ArgTypes...>
::ResultConsoleTable::ResultConsoleTable(
    const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo,
    Orientation orientation
):
    orientation(orientation),
    funcsSize(funcsInfo.size())
{
    this->addHeader(funcsInfo);
}

template<typename ReturnType, typename ...ArgTypes>
This AbstractTimeComparisonWorkflow<ReturnType, ArgTypes...>
::ResultConsoleTable::addRecord(
    const std::string &inputIdentifier,
    const std::vector<TimeMeasuring::ExecutionTime> &record
) {
    if constexpr (record.size() != this->funcsSize) {
        throw std::invalid_argument(
            "Record size does not match functions size"
        );
    }

    std::vector<std::string> dataSet(this->funcsSize + 1);
    dataSet[0] = inputIdentifier;
    std::copy(record.cbegin(), record.cend(), std::back_inserter(dataSet));

    if constexpr (this->orientation == Orientation::ROW_BASED) {
        this->addRow(dataSet);
    } else {
        this->addColumn(dataSet);
    }

    return *this;
}

template<typename ReturnType, typename ...ArgTypes>
constexpr This AbstractTimeComparisonWorkflow<ReturnType, ArgTypes...>
::ResultConsoleTable::addHeader(
    const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo
) {
    // TODO: Get the top left cell data from input
    (*this)[0][0] = "";

    for (size_t i = 0; i < this->funcsSize; i++) {
        if constexpr (this->orientation == Orientation::ROW_BASE) {
            (*this)[i + 1][0] = funcsInfo[i].name;
        } else {
            (*this)[0][i + 1] = funcsInfo[i].name;
        }
    }
}
