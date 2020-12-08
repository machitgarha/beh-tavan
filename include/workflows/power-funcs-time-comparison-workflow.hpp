#ifndef BEH_TAVAN_WORKFLOWS_POWER_HPP
#define BEH_TAVAN_WORKFLOWS_POWER_HPP

#include "abstract-interactive-workflow.hpp"
#include "abstract-time-comparison-workflow.hpp"

#include "output.hpp"
#include "nameof.hpp"
#include "types.hpp"
#include "console-table/execution-result-table.hpp"
#include "functions/power.hpp"

namespace BehTavan::Workflows
{
    using namespace Functions;

    /**
     * Print consumed time of some power functions.
     */
    class PowerFuncsTimeComparisonWorkflow:
        public AbstractInteractiveWorkflow,
        public AbstractTimeComparisonWorkflow<
            Power::Result,
            Power::Base,
            Power::Exponent
        >
    {
        public:
            virtual void run();

        protected:
            const Power::Base defaultBase = 3;
            const std::vector<Power::Exponent> defaultExponents = {
                1, 5, 10, 1000, 10000, 100000, 1000000, 10000000, 100000000
            };

            virtual inline const CurFunctionInfoVector &getFunctionsInfo() const noexcept
            {
                static const CurFunctionInfoVector funcs = {
                    FUNCTION_INFO(Power::power),
                    FUNCTION_INFO(Power::powerOptimized),
                };

                return funcs;
            };

            inline Power::Base getBase() const
            {
                return this->getNumber("base", this->defaultBase);
            }

            inline std::vector<Power::Exponent> getExponents() const
            {
                return this->getNumberVector("exponent", this->defaultExponents);
            }
    };
}

#endif // BEH_TAVAN_WORKFLOWS_POWER_HPP
