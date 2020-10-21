#include "execution.hpp"

using namespace BehTavan;

template<typename TimeUnit, typename ReturnType, typename ...ArgTypes>
ExecutionTimeVector BehTavan::execute(
    const Functions::FunctionInfoList<ReturnType, ArgTypes...> &funcsInfo,
    ArgTypes ...funcArguments
) {
    using namespace TimeMeasuring;

    // Function type of each function
    using FunctionType = typename
        Functions::FunctionInfo<ReturnType, ArgTypes...>::FunctionType;

    ExecutionTimeVector times;

    /*
     * To ensure all functions produce the same output, we must compare their outputs to
     * be equal. However, comparing all consecutive output pairs is just enough.
     *
     * So, we need two variables for storing output of previous and current function.
     * As the first element has no previous element, so we check not being the first one.
     */
    ReturnType prevOutput = 0, curOutput = 0;
    bool isFirstElement = true;

    for (const FunctionType &func : funcsInfo) {
        times.push_back(
            measureFuncExecTime<TimeUnit, ReturnType, ArgTypes...>(
                curOutput, func.pointer, funcArguments...
            )
        );

        // Ensure all outputs are equal
        if (!isFirstElement && prevOutput != curOutput) {
            throw std::runtime_error("Functions do not produce the same output");
        }

        isFirstElement = false;
        prevOutput = curOutput;
    }

    return times;
}
