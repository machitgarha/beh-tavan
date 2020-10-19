#ifndef BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
#define BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP

#include "standard-console-table.hpp"
#include "power.hpp"
#include "execution.hpp"

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
             * used in the header.
             */
            ExecutionResultTable(const PowerFunctionInfoVector &powerFuncsInfo);

            void addRow(Exponent exponent, ExecutionTimeVector &&timesResult);

        protected:
            using StandardConsoleTable::addRow;

        private:
            /**
             * Fills the header of the given table, based on the power functions.
             *
             * @param powerFuncsInfo The information of all available power functions.
             */
            void addHeader(const PowerFunctionInfoVector &powerFuncsInfo);
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
