#include "input.hpp"

#include "output.hpp"

using namespace BehTavan;
using namespace BehTavan::Input;

template<typename NumberType>
NumberType Input::getNumber(Name name, NumberType defaultValue, bool interactive)
{
    if (!interactive) {
        return defaultValue;
    }

    NumberType input;

    printLine3("Please enter the ", name, " (0: default):");
    std::cin >> input;
    printNewLine();

    return input ?: defaultValue;
}

template<typename NumberType>
Collection<NumberType> Input::getNumberCollection(
    Name name,
    Collection<NumberType> &&defaultValue,
    bool interactive
) {
    if (!interactive) {
        return defaultValue;
    }

    Collection<NumberType> result;
    NumberType tmpNum = 1;

    printLine3("Please enter a list of ", name, "s (0: exit, 0 at beginning: default): ");

    std::cin >> tmpNum;
    while (tmpNum != 0) {
        result.push_back(tmpNum);
        std::cin >> tmpNum;
    }

    printNewLine();

    if (result.empty()) {
        return defaultValue;
    } else {
        return result;
    }
}


/*
 * Instantiations.
 *
 * TODO: Add more detailed comment here.
 */

#include "functions/base.hpp"
using namespace BehTavan::Functions;

#include "functions/power.hpp"
template Power::Base Input::getNumber(Name, Power::Base, bool);
template Collection<Power::Exponent> Input::getNumberCollection(
    Name,
    Collection<Power::Exponent> &&,
    bool
);
