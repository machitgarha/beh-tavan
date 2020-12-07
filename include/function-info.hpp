#ifndef BEH_TAVAN_FUNCTIONS_BASE_HPP
#define BEH_TAVAN_FUNCTIONS_BASE_HPP

#include <vector>
#include <functional>
#include <string>

#include "types.hpp"

// For children only
#include "nameof.hpp"

namespace BehTavan::Functions
{
    /**
     * Container storing function information.
     */
    template<typename ReturnType, typename ...ArgTypes>
    class FunctionInfo
    {
        public:
            using FunctionType = std::function<ReturnType(ArgTypes...)>;
            using FunctionName = std::string;

            FunctionInfo(FunctionType f, FunctionName fName):
                func(f),
                name(fName)
            {
                if (!f) {
                    throw std::invalid_argument("Function must not be empty");
                }
                if (fName.empty()) {
                    throw std::invalid_argument("Function name must not be empty");
                }
            }

            const FunctionType func;
            const FunctionName name;
    };

    template<size_t size, typename ReturnType, typename ...ArgTypes>
    using FunctionInfoArray = Types::Array<FunctionInfo<ReturnType, ArgTypes...>, size>;
}

#endif // BEH_TAVAN_FUNCTIONS_BASE_HPP
