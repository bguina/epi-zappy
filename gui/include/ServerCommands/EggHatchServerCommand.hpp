
#ifndef HPP_EGGHATCHSERVERCOMMAND
#define HPP_EGGHATCHSERVERCOMMAND

#include <sstream>

#include "IServerCommand.hpp"

class EggHatchServerCommand : public IServerCommand
{
    SERVERCOMMAND_META

    public:
    static IServerCommand* factory(std::string const& str)
    {
        std::stringstream ss(str);
        std::string cmd;
        int egg;

        ss.exceptions(std::ios_base::failbit);
        ss >> cmd;
        
        if (cmd != "eht")
            return 0;

        ss >> egg;
        if (!ss.eof())
            return 0;

        return new EggHatchServerCommand(egg);
    }

    EggHatchServerCommand(int egg_arg)
        : egg(egg_arg)
    {
    }

    int const egg;
};

#endif

