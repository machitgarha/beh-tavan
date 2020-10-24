#ifndef BEH_TAVAN_EXECUTION_PROVIDER_HPP
#define BEH_TAVAN_EXECUTION_PROVIDER_HPP

#include "time-measuring.hpp"
#include "functions/base.hpp"

namespace BehTavan
{
    using namespace TimeMeasuring;

    /*
     * A list of execution times. As the function information list is constant, so its size
     * is constant too, thus, it is more efficient to use arrays instead of other
     * containers (e.g. vectors).
     */
    template<size_t size>
    using ExecutionTimeArray = std::array<ExecutionTime, size>;

    /**
     * Returns execution times of a group of functions, for the given input.
     *
     * @param funcArgs The arguments to be forwarded to each function.
     * @return List of execution times of the functions, in the specified unit (i.e. via
     * template argument), sorted the same as input function list.
     */
    template<typename TimeUnit, typename ReturnType, typename ...ArgTypes>
    inline auto getFuncExecTimeSet(
        const Functions::FunctionInfoList<ReturnType, ArgTypes...> &funcsInfo,
        ArgTypes ...funcArgs
    ) -> ExecutionTimeArray<funcsInfo.size()> {
        // TODO: Maybe remove implementation to a CPP file and specialize it?

        // Function type of each function
        using FunctionType = typename
            Functions::FunctionInfo<ReturnType, ArgTypes...>::FunctionType;

        const size_t funcsCount = funcsInfo.size();
        ExecutionTimeArray<funcsCount> times;

        /*
         * To ensure all functions produce the same output, we must compare their outputs
         * to be equal. However, comparing all consecutive output pairs is just enough.
         *
         * So, we need two variables for storing output of previous and current function.
         * As the first element has no previous element, so we check not being the first
         * one.
         *
         * Also, the default value of both variables is zero. Although the following this
         * rule is always good (i.e. having default values always and preventing random
         * values in random variables), but here is necessary to handle void functions. In
         * this case, there is no output, and thus, no comparisons
         */
        ReturnType prevOutput = 0, curOutput = 0;
        bool isFirstElement = true;

        for (size_t i = 0; i < funcsCount; i++) {
            /*
             * Handle void functions explicitly, as the arguments count differ with the
             * non-void ones. The later have to get the output, but the former not.
             *
             * And, it should be noted that, the cost of this if is zero at runtime; since
             * it gets evaluated at compile-time (i.e. it is constexpr). As a result,
             * putting it inside the for and outside of it does not matter.
             *
             * Also, by making the following peice of code a function, the code only gets
             * duplicated. If you wonder why, try doing that.
             */
            if constexpr (std::is_void_v<ReturnType>) {
                times[i] = getFuncExecTime<TimeUnit, ArgTypes...>(
                    funcsInfo[i].pointer, std::forward<ArgTypes>(funcArgs)...
                );
            } else {
                times[i] = getFuncExecTime<TimeUnit, ReturnType, ArgTypes...>(
                    funcsInfo[i].pointer, curOutput, std::forward<ArgTypes>(funcArgs)...
                );
            }

            // Ensure all outputs are equal
            if (!isFirstElement && prevOutput != curOutput) {
                throw std::runtime_error("Functions do not produce the same output");
            }

            isFirstElement = false;
            prevOutput = curOutput;
        }

        return times;
    }
}

#endif // BEH_TAVAN_EXECUTION_PROVIDER_HPP
