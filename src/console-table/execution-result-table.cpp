#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using BehTavan::ExecutionResultTable;

ExecutionResultTable::ExecutionResultTable(const PowerFunctionInfoList &powerFuncsInfo)
{
    this->addHeader(powerFuncsInfo);
}

void ExecutionResultTable::addHeader(const PowerFunctionInfoList &powerFuncsInfo)
{
    std::vector<std::string> headerCells;
    headerCells.reserve(powerFuncsInfo.size() + 1);

    // The top left table cell
    headerCells.push_back("");

    for (const PowerFunctionInfo &i : powerFuncsInfo) {
        headerCells.push_back(i.name);
    }

    this->addRow(headerCells);
}
