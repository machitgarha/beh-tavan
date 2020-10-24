#include "console-table/execution-result-table.hpp"

using namespace BehTavan;
using BehTavan::ExecutionResultTable;

template<size_t funcsSize, typename FuncReturnType, typename ...FuncArgTypes>
void ExecutionResultTable::addHeader(
    std::string &&topLeftCellContent,
    Functions::FunctionInfoArray<funcsSize, FuncReturnType, FuncArgTypes...> &&funcsInfo
) {
    (*this)[0][0] = topLeftCellContent;

    for (size_t i = 0; i < funcsSize; i++) {
        (*this)[0][i + 1] = funcsInfo[i];
    }
}
