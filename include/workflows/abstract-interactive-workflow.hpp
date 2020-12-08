#ifndef BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
#define BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP

#include "abstract-workflow.hpp"

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
            using Name = const char *;

            /*
             * A type to hold a collection of things. Using vector directly is not a good idea, as
             * we may change it in the future (considering we do not break BC), and also, a
             * separated type helps preventing confusions.
             */
            template<typename T>
            using Collection = std::vector<T>;

            /**
             * Returns a number, and if needed, gets it from the user.
             *
             * @param name The name of the input number.
             * @param defaultValue The default value.
             * @param interactive Whether the value is user supplied or not.
             */
            template<typename NumberType>
            NumberType getNumber(Name name, NumberType defaultValue)
            {
                if (!this->isInteractive) {
                    return defaultValue;
                }

                NumberType input;

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
            template<typename NumberType>
            Collection<NumberType> getNumberCollection(
                Name name,
                const Collection<NumberType> &defaultValue
            ) {
                if (!this->isInteractive) {
                    return defaultValue;
                }

                Collection<NumberType> result;
                NumberType tmpNum = 1;

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
    };
}

#endif // BEH_TAVAN_WORKFLOWS_ABSTRACT_INTERACTIVE_WORKFLOW_HPP
