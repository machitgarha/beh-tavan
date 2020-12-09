#ifndef BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
#define BEH_TAVAN_WORKFLOWS_COMPARISON_HPP

#include "abstract-workflow.hpp"

// For children
#include "function-info.hpp"
#include "env.hpp"

#include "time-measuring.hpp"
#include "console-table/standard-console-table.hpp"

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

        /**
         * Console table specifically for representing execution time results.
         *
         * Obviously, what is going to be done is, we have one or more input set to pass
         * to some functions, measure its time and output the results.
         *
         * Here, we call the set of time results for each input set a record. In other
         * words, records are input-based rather than function-based.
         */
        class ExecutionTimeResultConsoleTable: public StandardConsoleTable
        {
        public:
            /**
             * Orientation of the table. Specifies the table output structure and flow.
             */
            const enum class Orientation
            {
                /**
                 * Each record lives in one row (also function titles).
                 */
                ROW_BASED,
                /**
                 * Each record lives in one column (also function titles).
                 */
                COLUMN_BASED,
            } orientation;

            const size_t funcsSize;

            ExecutionTimeResultConsoleTable(
                const FunctionInfoVector<ReturnType, ArgTypes...> &,
                Orientation = Orientation::COLUMN_BASED
            );

            /**
             * Adds a record to the table.
             *
             * @param inputIdentifier The identifier for distinction between input sets.
             * It can be the input set itself, only the changing input, or a phrase
             * describing it.
             */
            ExecutionTimeResultConsoleTable &addRecord(
                const std::string &inputIdentifier,
                std::vector<TimeMeasuring::ExecutionTime>
            );

        protected:
            // addRecord must be used instead
            using StandardConsoleTable::addRow;
            using StandardConsoleTable::addColumn;

            /**
             * Fills the table header.
             */
            constexpr ExecutionTimeResultConsoleTable &addHeader(
                const FunctionInfoVector<ReturnType, ArgTypes...> &funcsInfo
            );

        private:
            /** Current index row. First and second rows are for header. */
            size_t curRow = 2;

        };
    };
}

#endif // BEH_TAVAN_WORKFLOWS_COMPARISON_HPP
