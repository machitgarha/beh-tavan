#ifndef BEH_TAVAN_WORKFLOWS_BASE_HPP
#define BEH_TAVAN_WORKFLOWS_BASE_HPP

namespace BehTavan::Workflows
{
    /**
     * Workflow base class.
     *
     * A workflow is a set of works (i.e. functions) done in order to make a whole work
     * done. Useful to keep things as simple as possible, and also to hide implementation.
     */
    class BaseWorkflow
    {
        /**
         * Runs the workflow in the specified order.
         *
         * There should be no work under constructor, it should only prepare necessary
         * stuff before running the workflow.
         *
         * To keep things simple, implementation of this function should be minimal and
         * restricted to a set of function calls only. More modular, the better.
         */
        virtual void run() = 0;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_BASE_HPP
