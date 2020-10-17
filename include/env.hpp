#ifndef BEH_TAVAN_ENV_HPP
#define BEH_TAVAN_ENV_HPP

#include <string>

namespace BehTavan
{
    /**
     * Returns whether the program should get input from the user or not at all.
     */
    inline bool isInteractive()
    {
        std::string envInteractive = getenv("INTERACTIVE");
        return envInteractive != "0";
    }
}

#endif // BEH_TAVAN_ENV_HPP
