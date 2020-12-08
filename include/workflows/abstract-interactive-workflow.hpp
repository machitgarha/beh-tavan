#ifndef BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
#define BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP

#include "abstract-workflow.hpp"

#include "env.hpp"
#include "input.hpp"

namespace BehTavan::Workflows
{
    /**
     * Abstract workflow for user interactions.
     *
     * The class also uses INTERACTIVE environment variable (enabled by default), which can
     * be set to 0 to disable user interactions and use default values instead.
     */
    class AbstractInteractiveWorkflow: public AbstractWorkflow
    {
        public:
            AbstractInteractiveWorkflow():
                isInteractive(Env::isInteractive())
            {};

        protected:
            const bool isInteractive = true;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
