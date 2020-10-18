#ifndef BEH_TAVAN_ENV_HPP
#define BEH_TAVAN_ENV_HPP

#include <cstdlib>
#include <cstring>

namespace BehTavan::Env
{
    /**
     * Returns whether the program should get input from the user or not at all.
     */
    inline bool isInteractive()
    {
        const char *envInteractiveStr = std::getenv("INTERACTIVE");

        // By default, it's interactive
        if (envInteractiveStr == nullptr) {
            return true;
        }
        return strcmp(envInteractiveStr, "0") != 0;
    }
}

#endif // BEH_TAVAN_ENV_HPP
