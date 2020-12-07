#include "output.hpp"

using namespace BehTavan;
using namespace BehTavan::Output;

void Output::printStartMessage()
{
    printLine("Welcome to BehTavan!");
    printLine("This is a free program: Licensed under GPLv3.");
    printNewLine();
}
