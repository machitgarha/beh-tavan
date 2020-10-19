#ifndef BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
#define BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP

#include "standard-console-table.hpp"
#include "execution.hpp"
#include "functions/base.hpp"

namespace BehTavan
{
    using namespace Functions;

    /**
     * Console table specifically for holding results of executions.
     */
    template<typename Func>
    class ExecutionResultTable: public StandardConsoleTable
    {
        public:
            /**
             * Constructor.
             *
             * Prepares the table header, based on the given argument.
             *
             * @param funcsInfo Information list of functions being worked on.
             */
            ExecutionResultTable(const FunctionInfoList<Func> &funcsInfo);

            void addRow(Exponent exponent, ExecutionTimeVector &&timesResult);

        protected:
            using StandardConsoleTable::addRow;

        private:
            /**
             * Fills the header of the given table, based on the power functions.
             *
             * @param powerFuncsInfo The information of all available power functions.
             */
            void addHeader(const FunctionInfoList<Func> &powerFuncsInfo);
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
