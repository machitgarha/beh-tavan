#ifndef BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP

#include "abstract-interactive-workflow.hpp"
#include "abstract-time-comparison-workflow.hpp"

#include "types.hpp"
#include "input.hpp"
#include "nameof.hpp"
#include "functions/sorting.hpp"

namespace BehTavan::Workflows
{
    using namespace Functions;

    class SortingTimeComparisonWorkflow:
        public AbstractInteractiveWorkflow,
        public AbstractTimeComparisonWorkflow<
            void,
            std::vector<Types::UInt64>
        >
    {
        public:
            virtual void run();

        protected:
            const size_t defaultArraySize = 256;

            inline size_t getArraySize() const
            {
                return Input::getNumber(
                    "array size", this->defaultArraySize, this->isInteractive
                );
            }
    };
}

#endif // BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP
