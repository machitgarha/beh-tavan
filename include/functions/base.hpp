#ifndef BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP
#define BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP

#include <initializer_list>
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
    template<typename FunctionPointer>
    struct FunctionInfo
    {
        FunctionPointer ptr;
        std::string name;
    };

    template<typename FunctionPointer>
    using FunctionInfoCollection = List<FunctionInfo<FunctionPointer>>;
}

#endif // BEH_TAVAN_FUNCTIONS_COLLECTIONS_HPP
