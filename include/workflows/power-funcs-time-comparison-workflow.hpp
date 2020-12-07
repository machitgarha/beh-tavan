#ifndef BEH_TAVAN_WORKFLOWS_POWER_HPP
#define BEH_TAVAN_WORKFLOWS_POWER_HPP

#include "abstract-time-comparison-workflow.hpp"

#include "input.hpp"
#include "output.hpp"
#include "env.hpp"
#include "types.hpp"
#include "console-table/execution-result-table.hpp"

#include "functions/power.hpp"

// TODO: Move into the class
#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

namespace BehTavan::Workflows
{
    using namespace Functions;

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
                return Input::getNumber<Power::Base>(
                    "base", BASE_DEFAULT, this->isInteractive
                );
            }

            inline Input::Collection<Power::Exponent> getExponents() const
            {
                return Input::getNumberCollection<Power::Exponent>(
                    "exponent", EXPONENTS_DEFAULT, this->isInteractive
                );
            }

        private:
            bool isInteractive;
    };
}

#endif // BEH_TAVAN_WORKFLOWS_POWER_HPP
