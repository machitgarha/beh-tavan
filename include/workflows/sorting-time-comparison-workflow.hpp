#ifndef BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP

#include "abstract-interactive-workflow.hpp"
#include "abstract-time-comparison-workflow.hpp"

#include "functions/sorting.hpp"

namespace BehTavan::Workflows
{
    class SortingTimeComparisonWorkflow:
        public AbstractInteractiveWorkflow,
        public AbstractTimeComparisonWorkflow<
            void,
            std::vector<Types::UInt64> &
        >
    {
    public:
        virtual void run();

    protected:
        const size_t defaultArraySize = 256;

        virtual inline const CurFunctionInfoVector &getFunctionsInfo() const
        {
            using namespace Functions;

            static const CurFunctionInfoVector funcsInfo = {
                FUNCTION_INFO(Sorting::bubbleSort<Types::UInt64>),
                FUNCTION_INFO(Sorting::countingSort<Types::UInt64>),
                FUNCTION_INFO(Sorting::heapSort<Types::UInt64>),
                FUNCTION_INFO(Sorting::insertionSort<Types::UInt64>),
                FUNCTION_INFO(Sorting::selectionSort<Types::UInt64>),
            };

            return funcsInfo;
        }

        inline size_t getArraySize() const
        {
            return this->getNumber("array size", this->defaultArraySize);
        }

        class TimeMeasuring:
            public AbstractTimeComparisonWorkflow::TimeMeasuring
        {
        protected:
            virtual bool doProduceSameResults(
                const ReturnValuePair &,
                const ArgSetValuePair &
            ) final;
        } timeMeasuring;

    private:
        static const Types::UInt64 randMax = 40000;

        std::vector<Types::UInt64> generateRandomArray(size_t);
    };
}

#endif // BEH_TAVAN_WORKFLOWS_SORTING_TIME_COMPARISON_HPP
