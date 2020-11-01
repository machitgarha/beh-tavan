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
    template<size_t funcsSize, typename FuncReturnType, typename ...FuncArgTypes>
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
                const FunctionInfoArray<
                    funcsSize,
                    FuncReturnType,
                    FuncArgTypes...
                > &funcsInfo
            ) {
                this->addHeader(std::move(topLeftCellContent), std::move(funcsInfo));
            }

            /**
             * Add a new row, consisting a new record.
             *
             * @param recordInputValue The first cell value, which is the variable input
             * changing between records.
             * @param execTimes Execution times of each function, sorted as the functions
             * information passed to the constructor.
             */
            template<typename Value>
            inline void addRow(
                Value recordInputValue,
                ExecutionTimeArray<funcsSize> &&execTimes
            ) {
                // First cell
                (*this)[this->curRow][0] = recordInputValue;

                for (size_t i = 0; i < funcsSize; i++) {
                    (*this)[this->curRow][i + 1] = execTimes[i];
                }

                // Go to next row, for the next call
                this->curRow++;
            }

        protected:
            using StandardConsoleTable::addRow;

        private:
            /** Current row index */
            size_t curRow = 1;

            /**
             * Fills the header of the given table.
             */
            void addHeader(
                const std::string &&topLeftCellContent,
                const FunctionInfoArray<
                    funcsSize,
                    FuncReturnType,
                    FuncArgTypes...
                > &&funcsInfo
            ) {
                (*this)[0][0] = topLeftCellContent;

                for (size_t i = 0; i < funcsSize; i++) {
                    (*this)[0][i + 1] = funcsInfo[i].name;
                }
            }
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
