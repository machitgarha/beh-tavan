#ifndef BEH_TAVAN_WORKFLOWS_POWER_HPP
#define BEH_TAVAN_WORKFLOWS_POWER_HPP

#include "base.hpp"
#include "input.hpp"
#include "output.hpp"
#include "env.hpp"
#include "types.hpp"
#include "execution.hpp"
#include "console-table/execution-result-table.hpp"

#include "functions/power.hpp"

#define BASE_DEFAULT 3
#define EXPONENTS_DEFAULT {1, 5, 10, 100, 1000, 10000, 100000, 1000000, 10000000}

namespace BehTavan::Workflows
{
    using namespace Functions;
    using namespace std;

    class PowerWorkflow: public BaseWorkflow
    {
        public:
            inline PowerWorkflow():
                isInteractive(Env::isInteractive())
            {
            };

            virtual void run();

        private:
            bool isInteractive;

            // TODO: Make interactive a class property
            static inline Power::Base getBase(bool interactive)
            {
                return Input::getNumber<Power::Base>(
                    "base", BASE_DEFAULT, interactive
                );
            }

            static inline Input::Collection<Power::Exponent> getExponents(bool interactive)
            {
                return Input::getNumberCollection<Power::Exponent>(
                    "exponent", EXPONENTS_DEFAULT, interactive
                );
            }
    };
}

#endif // BEH_TAVAN_WORKFLOWS_POWER_HPP
