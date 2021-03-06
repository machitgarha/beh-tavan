#ifndef BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
#define BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP

#include "standard-console-table.hpp"
#include "function-info.hpp"
#include "time-measuring.hpp"

namespace BehTavan
{
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
             * @param firstColumnName The title of the changing values in the first column.
             * @param funcsInfo Information list of functions being worked on.
             */
            inline ExecutionResultTable(
                const std::string &&firstColumnName,
                const FunctionInfoVector<
                    FuncReturnType,
                    FuncArgTypes...
                > &funcsInfo
            ): colCount(funcsInfo.size())
            {
                this->addHeader(std::move(firstColumnName), std::move(funcsInfo));
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
                TimeMeasuring::ExecutionTimeVector &&execTimes
            ) {
                if (execTimes.size() != colCount) {
                    throw std::invalid_argument(
                        "Execution times count does not equal functions count"
                    );
                }

                // First cell
                (*this)[this->curRow][0] = recordInputValue;

                for (size_t i = 0; i < this->colCount; i++) {
                    (*this)[this->curRow][i + 1] = execTimes[i];
                }

                // Go to next row, for the next call
                this->curRow++;
            }

        protected:
            using StandardConsoleTable::addRow;

        private:
            /** Column count, based on the number of functions. */
            const size_t colCount;

            /** Current index row. First and second rows are for header. */
            size_t curRow = 2;

            /**
             * Fills the header of the given table, including the first two rows.
             */
            void addHeader(
                const std::string &&firstColumnName,
                const FunctionInfoVector<
                    FuncReturnType,
                    FuncArgTypes...
                > &&funcsInfo
            ) {
                // First row
                (*this)[0][0] = "Functions:";
                for (size_t i = 0; i < this->colCount; i++) {
                    (*this)[0][i + 1] = funcsInfo[i].name;
                }

                // Second row
                (*this)[1][0] = firstColumnName;
            }
    };
}

#endif // BEH_TAVAN_EXECUTION_RESULT_TABLE_HPP
