#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using BehTavan::ExecutionResultTable;

template<typename FuncReturnType, typename ...FuncArgTypes>
ExecutionResultTable::ExecutionResultTable(
    const std::string &&topLeftCellContent,
    const FunctionInfoList<FuncReturnType, FuncArgTypes...> &funcsInfo
): colSize(funcsInfo.size())
{
    this->addHeader(funcsInfo);
}

template<typename FuncReturnType, typename ...FuncArgTypes>
void ExecutionResultTable::addHeader(
    FunctionInfoList<FuncReturnType, FuncArgTypes...> &&powerFuncsInfo
) {
    std::vector<std::string> headerCells;
    headerCells.reserve(powerFuncsInfo.size() + 1);

    // The top left table cell
    headerCells.push_back("");

    for (const PowerFunctionInfo &i : powerFuncsInfo) {
        headerCells.push_back(i.name);
    }

    this->addRow(headerCells);
}
