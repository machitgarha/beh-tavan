#ifndef BEH_TAVAN_INPUT_HPP
#define BEH_TAVAN_INPUT_HPP

#include <string>
#include <vector>

#include "output.hpp"

namespace BehTavan::Input
{
    /*
     * Input name.
     */
    using Name = const char *;

    /*
     * A type to hold a collection of things. Using vector directly is not a good idea, as
     * we may change it in the future (considering we do not break BC), and also, a
     * separated type helps preventing confusions.
     */
    template<typename T>
    using Collection = std::vector<T>;

    /**
     * Returns a number, and if needed, gets it from the user.
     *
     * @param name The name of the input number.
     * @param defaultValue The default value.
     * @param interactive Whether the value is user supplied or not.
     */
    template<typename NumberType>
    NumberType getNumber(Name name, NumberType defaultValue, bool interactive)
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

    /**
     * Returns a collection of numbers, and if needed, gets it from the user.
     *
     * @param name The name of the input number.
     * @param defaultValue The default value.
     * @param interactive Whether the value is user supplied or not.
     */
    template<typename NumberType>
    Collection<NumberType> getNumberCollection(
        Name name,
        const Collection<NumberType> &defaultValue,
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
}

#endif // BEH_TAVAN_INPUT_HPP
