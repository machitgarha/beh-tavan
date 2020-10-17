#ifndef BEH_TAVAN_STANDARD_CONSOLE_TABLE_HPP
#define BEH_TAVAN_STANDARD_CONSOLE_TABLE_HPP

#include "CppConsoleTable.hpp"

namespace BehTavan
{
    /**
     * A console table that uses more standard characters in the output.
     */
    class StandardConsoleTable: public samilton::ConsoleTable
    {
        public:
            StandardConsoleTable();

        protected:
            /**
             * Get standard table characters structure.
             *
             * As the default one may not be supported in all shells and environments,
             * instead, this function returns more ASCII characters like + and -.
             */
            static TableChars getStandardTableChars() noexcept;
    };
}

#endif // BEH_TAVAN_STANDARD_CONSOLE_TABLE_HPP
