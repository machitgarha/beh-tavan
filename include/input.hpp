#ifndef BEH_TAVAN_INPUT_HPP
#define BEH_TAVAN_INPUT_HPP

#include <string>
#include <vector>

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
    NumberType getNumber(
        Name name,
        NumberType defaultValue,
        bool interactive = true
    );

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
        Collection<NumberType> &&defaultValue,
        bool interactive = true
    );
}

#endif // BEH_TAVAN_INPUT_HPP
