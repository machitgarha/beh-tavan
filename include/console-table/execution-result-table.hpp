#ifndef BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
#define BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP

#include "standard-console-table.hpp"
#include "power.hpp"

namespace BehTavan
{
    /**
     * Console table specifically for holding results of executions.
     */
    class ExecutionResultTable: public StandardConsoleTable
    {
        public:
            /**
             * Constructor.
             *
             * Prepares the table header, based on the given argument.
             *
             * @param powerFuncsInfo The information of all available power functions to be
             * used in the header, as well as future usages.
             */
            ExecutionResultTable(const PowerFunctionInfoList powerFuncsInfo);

        private:
            /**
             * Information container for all available power functions.
             */
            const PowerFunctionInfoList powerFuncsInfo;

            /**
             * Fills the header of the given table, based on the power functions.
             */
            void addHeader();
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
