#ifndef BEH_TAVAN_FUNCTIONS_BASE_HPP
#define BEH_TAVAN_FUNCTIONS_BASE_HPP

#include <vector>
#include <functional>
#include <string>

// For children only
#include "nameof.hpp"

namespace BehTavan::Functions
{
    template<typename T, size_t size>
    using Array = std::array<T, size>;

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
        using FunctionType = std::function<ReturnType(ArgTypes...)>;
        using FunctionName = std::string;

        // TODO: Add default value (e.g. a functor) to prevent UB
        FunctionType pointer;
        FunctionName name;
    };

    template<size_t size, typename ReturnType, typename ...ArgTypes>
    using FunctionInfoArray = Array<FunctionInfo<ReturnType, ArgTypes...>, size>;
}

#endif // BEH_TAVAN_FUNCTIONS_BASE_HPP
