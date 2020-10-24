#ifndef BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
#define BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP

#include "standard-console-table.hpp"
#include "execution.hpp"
#include "functions/base.hpp"

namespace BehTavan
{
    using namespace Functions;

    /**
     * Console table specifically for representing execution time results.
     */
    template<typename FuncReturnType, typename ...FuncArgTypes>
    class ExecutionResultTable: public StandardConsoleTable
    {
        public:
            /**
             * Constructor.
             *
             * Creates the table, and prepares the table header, based on the given input.
             *
             * @param topLeftCellContent The title of the cell in index [0, 0].
             * @param funcsInfo Information list of functions being worked on.
             */
            inline ExecutionResultTable(
                const std::string &&topLeftCellContent,
                const FunctionInfoList<FuncReturnType, FuncArgTypes...> &funcsInfo
            );

            template<typename Value, const size_t timesCount>
            inline void addRow(
                Value variableInputValue,
                ExecutionTimeArray<timesCount> &&timesResult
            ) {
                // Make sure cells count remain constant in each row
                if (timesCount != this->coreColCount) {
                    throw std::invalid_argument("Times");
                }

                // First cell
                (*this)[0] = variableInputValue;

                for (size_t i = 1; i <= timesCount; i++) {
                    (*this)[i] = timesResult[i - 1];
                }
            }

        protected:
            using StandardConsoleTable::addRow;

        private:
            /*
             * When adding new rows, the input must be in a way that, cell count of each
             * row must remain constant, which is the functions count given at construction
             * time.
             */
            const size_t coreColCount = 0;

            /**
             * Fills the header of the given table.
             */
            void addHeader(FunctionInfoList<FuncReturnType, FuncArgTypes...> &&funcsInfo);
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
