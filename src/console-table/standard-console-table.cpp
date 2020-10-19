#include "console-table/standard-console-table.hpp"

using namespace BehTavan;
using BehTavan::StandardConsoleTable;

StandardConsoleTable::StandardConsoleTable():
    samilton::ConsoleTable(
        // Indents
        1, 1,
        // Alignment
        samilton::Alignment::centre
    )
{
    this->setTableChars(StandardConsoleTable::getStandardTableChars());
}

StandardConsoleTable::TableChars StandardConsoleTable::getStandardTableChars() noexcept
{
    TableChars tableChars;

    tableChars.centreSeparation = '+';
    tableChars.downSeparation = '+';
    tableChars.topSeparation = '+';
    tableChars.leftSeparation = '+';
    tableChars.rightSeparation = '+';

    tableChars.downRight = '+';
    tableChars.downLeft = '+';
    tableChars.topLeft = '+';
    tableChars.topRight = '+';

    tableChars.leftRightSimple = '|';
    tableChars.topDownSimple = '-';

    return tableChars;
}
