#ifndef BEH_TAVAN_FUNCTIONS_BASE_HPP
#define BEH_TAVAN_FUNCTIONS_BASE_HPP

#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

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

#endif // BEH_TAVAN_FUNCTIONS_BASE_HPP
