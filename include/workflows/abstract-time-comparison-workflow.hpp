#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"

// For children
#include "function-info.hpp"
#include "env.hpp"

namespace BehTavan::Workflows
{
    /**
     * A workflow for comparing consumed times of same-prototyped functions.
     */
    template<typename ReturnType, typename ...ArgTypes>
    class AbstractTimeComparisonWorkflow
    {
        protected:
            // Types for the instantiated function information
            using CurFunctionInfo = FunctionInfo<ReturnType, ArgTypes...>;
            using CurFunctionInfoVector = FunctionInfoVector<ReturnType, ArgTypes...>;

            /**
             * Returns the functions information to be executed and measured.
             */
            virtual const CurFunctionInfoVector &getFunctionsInfo() const = 0;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
