
#ifndef HPP_EXPULSIONSERVERCOMMAND
#define HPP_EXPULSIONSERVERCOMMAND

#include <sstream>

#include "IServerCommand.hpp"

class ExpulsionServerCommand : public IServerCommand
{
    SERVERCOMMAND_META

    public:
    static IServerCommand* factory(std::string const& str)
    {
        std::stringstream ss(str);
        std::string cmd;
        int player;

        ss.exceptions(std::ios_base::failbit);
        ss >> cmd;
        
        if (cmd != "pex")
            return 0;

        ss >> player;
        if (!ss.eof())
            return 0;

        return new ExpulsionServerCommand(player);
    }

    ExpulsionServerCommand(int player_arg)
        : player(player_arg)
    {
    }

    int const player;
};

#endif

