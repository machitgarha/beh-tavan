#ifndef BEH_TAVAN_FUNCTIONS_INFO_HPP
#define BEH_TAVAN_FUNCTIONS_INFO_HPP

#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

#include "nameof.hpp"

#define FUNCTION_INFO(a) {a, NAMEOF(a).str()}

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

            const FunctionType func;
            const FunctionName name;

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
    };

    /**
     * A set of functions information.
     *
     * There is a trade-off between memory and time benefit of arrays, and ease of  use of
     * vectors. As the overhead of vectors in this case is pretty much negligible, for
     * writing less code and make things simpler, vector is being used.
     */
    template<typename ReturnType, typename ...ArgTypes>
    using FunctionInfoVector = std::vector<FunctionInfo<ReturnType, ArgTypes...>>;
}

#endif // BEH_TAVAN_FUNCTIONS_INFO_HPP
