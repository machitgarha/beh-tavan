#ifndef BEH_TAVAN_WORKFLOWS_POWER_HPP
#define BEH_TAVAN_WORKFLOWS_POWER_HPP

#include "abstract-time-comparison-workflow.hpp"

#include "input.hpp"
#include "output.hpp"
#include "env.hpp"
#include "types.hpp"
#include "console-table/execution-result-table.hpp"
#include "functions/power.hpp"

namespace BehTavan::Workflows
{
    using namespace Functions;

    /**
     * Print consumed time of some power functions.
     */
    class PowerFuncsTimeComparisonWorkflow: public AbstractTimeComparisonWorkflow<
        Power::Result,
        Power::Base,
        Power::Exponent
    > {
        public:
            inline PowerFuncsTimeComparisonWorkflow():
                isInteractive(Env::isInteractive())
            {
            };

            virtual void run();

        protected:
            const Power::Base defaultBase = 3;
            const Input::Collection<Power::Exponent> defaultExponents = {
                1, 5, 10, 1000, 10000, 100000, 1000000, 10000000, 100000000
            };

            virtual inline const CurFunctionInfoVector &getFunctionsInfo() const noexcept
            {
                static const CurFunctionInfoVector funcs = {
                    {
                        Power::power,
                        NAMEOF(Power::power).str()
                    },
                    {
                        Power::powerOptimized,
                        NAMEOF(Power::powerOptimized).str()
                    },
                };

                return funcs;
            };

            inline Power::Base getBase() const
            {
                return Input::getNumber(
                    "base", this->defaultBase, this->isInteractive
                );
            }

            inline Input::Collection<Power::Exponent> getExponents() const
            {
                return Input::getNumberCollection(
                    "exponent", this->defaultExponents, this->isInteractive
                );
            }

        private:
            bool isInteractive;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_POWER_HPP
