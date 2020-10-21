#ifndef BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP
#define BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP

#include <initializer_list>
#include <functional>
#include <string>

// For children only
#include "nameof.hpp"

namespace BehTavan::Functions
{
    template<typename T>
    using List = std::initializer_list<T>;

    /**
     * Container for information about a function. It contains two properties, function's
     * name and its pointer.
     *
     * As the function can be whatever, so the pointer is not a constant thing. Thus, we
     * must use a generic form, so for each function it can be narrowed for that specific
     * use case.
     */
    template<typename ReturnType, typename ...ArgTypes>
    struct FunctionInfo
    {
        using FunctionType = ReturnType(ArgTypes...);

        // TODO: Add default value (e.g. a functor) to prevent UB
        std::function<FunctionType> pointer;
        std::string name;
    };

    template<typename ReturnType, typename ...ArgTypes>
    using FunctionInfoList = List<FunctionInfo<ReturnType, ArgTypes...>>;
}

#endif // BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP
