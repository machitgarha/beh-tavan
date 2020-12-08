#ifndef BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
#define BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP

#include "abstract-workflow.hpp"

#include <type_traits>
#include <vector>
#include "env.hpp"
#include "output.hpp"

namespace BehTavan::Workflows
{
    /**
     * Abstract workflow for user interactions.
     *
     * The class also uses INTERACTIVE environment variable (enabled by default), which can
     * be set to 0 to disable user interactions and use default values instead.
     */
    class AbstractInteractiveWorkflow: public AbstractWorkflow
    {
        public:
            AbstractInteractiveWorkflow():
                isInteractive(Env::isInteractive())
            {};

        protected:
            const bool isInteractive = true;

            /*
             * Input name.
             */
            using InputName = const char *;

            /**
             * Returns a number, and if needed, gets it from the user.
             *
             * @param name The name of the input number.
             * @param defaultValue The default value.
             * @param interactive Whether the value is user supplied or not.
             */
            template<typename NumType>
            NumType getNumber(InputName name, NumType defaultValue)
            {
                AbstractInteractiveWorkflow::assertIsIntegeral<NumType>();

                if (!this->isInteractive) {
                    return defaultValue;
                }

                NumType input;

                printLine("Please enter the ", name, " (0: default):");
                std::cin >> input;
                printLine();

                return input ?: defaultValue;
            }

            /**
             * Returns a collection of numbers, and if needed, gets it from the user.
             *
             * @param name The name of the input number.
             * @param defaultValue The default value.
             * @param interactive Whether the value is user supplied or not.
             */
            template<typename NumType>
            std::vector<NumType> getNumberCollection(
                InputName name,
                const std::vector<NumType> &defaultValue
            ) {
                AbstractInteractiveWorkflow::assertIsIntegeral<NumType>();

                if (!this->isInteractive) {
                    return defaultValue;
                }

                std::vector<NumType> result;
                NumType tmpNum = 1;

                printLine("Please enter a list of ", name, "s (0: exit, 0 at beginning: default): ");

                std::cin >> tmpNum;
                while (tmpNum != 0) {
                    result.push_back(tmpNum);
                    std::cin >> tmpNum;
                }

                printLine();

                if (result.empty()) {
                    return defaultValue;
                } else {
                    return result;
                }
            }

        private:
            template<typename T>
            constexpr static inline void assertIsIntegeral()
            {
                static_assert(
                    std::is_integral_v<T>,
                    "The given type is not integral"
                );
            }
    };
}

#endif // BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
