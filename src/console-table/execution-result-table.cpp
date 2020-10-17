#include "console-table/execution-result-table.hpp"

#include <algorithm>

#include "power.hpp"

using namespace BehTavan;
using BehTavan::ExecutionResultTable;

ExecutionResultTable::ExecutionResultTable(const PowerFunctionInfoList powerFuncsInfo):
    powerFuncsInfo(powerFuncsInfo)
{
    this->addHeader();
}

void ExecutionResultTable::addHeader()
{
    std::vector<std::string> headerTitles;
    headerTitles.reserve(this->powerFuncsInfo.size() + 1);

    // The top left table cell
    headerTitles.push_back("");

    for (const PowerFunctionInfo &i : this->powerFuncsInfo) {
        headerTitles.push_back(i.name);
    }

    this->addRow(headerTitles);
}
