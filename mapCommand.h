#ifndef FLIGHT_SIMULATOR_MAPCOMMAND_H
#define FLIGHT_SIMULATOR_MAPCOMMAND_H

#include <string>
#include <map>

class Commands;
using namespace std;

class mapCommand {
    map<string,Commands> commandMap;


public:
    mapCommand(){};
    const map<string, Commands> &getCommandMap() const;

    void addCommand(string symbol,Commands& commands);
    Commands* getCommand(string symbol) ;
};


#endif //FLIGHT_SIMULATOR_MAPCOMMAND_H