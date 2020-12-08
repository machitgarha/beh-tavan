#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"

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
        public:
            inline AbstractTimeComparisonWorkflow():
                isInteractive(Env::isInteractive())
            {}

        protected:
            /** INTERACTIVE env state */
            bool isInteractive;

            /**
             * A type to hold functions information based on the specified prototype.
             */
            using CurFunctionInfoVector = FunctionInfoVector<ReturnType, ArgTypes...>;

            /**
             * Returns the functions information to be executed and measured.
             */
            virtual const CurFunctionInfoVector &getFunctionsInfo() const noexcept = 0;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
