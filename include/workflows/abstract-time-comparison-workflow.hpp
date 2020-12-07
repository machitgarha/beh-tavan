#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"
#include "function-info.hpp"

namespace BehTavan::Workflows
{
    /**
     * A workflow for comparing consumed times of same-prototyped functions.
     */
    template<typename ReturnType, typename ...ArgTypes>
    class AbstractTimeComparisonWorkflow
    {
        protected:
            /**
             * A set of functions information.
             *
             * There is a trade-off between memory and time benefit of arrays, and ease of
             * use of vectors. As the overhead of vectors in this case is pretty much
             * negligible, for writing less code and make things simpler, vector is being
             * used.
             */
            using FunctionInfoVector = std::vector<
                FunctionInfo<ReturnType, ArgTypes...>
            >;

            /**
             * Returns the functions information to be executed and measured.
             */
            virtual const FunctionInfoVector &getFunctions() = 0;
    };

}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
