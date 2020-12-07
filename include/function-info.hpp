#ifndef BEH_TAVAN_FUNCTIONS_BASE_HPP
#define BEH_TAVAN_FUNCTIONS_BASE_HPP

#include <vector>
#include <functional>
#include <string>

// For children only
#include "nameof.hpp"

namespace BehTavan
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
}

#endif // BEH_TAVAN_FUNCTIONS_BASE_HPP
