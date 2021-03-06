
#include <map>
#include <iostream>
#include "VarCommand.h"
#include "../data/symbolTable.h"

extern pthread_mutex_t mutex;

int VarCommand::execute() {
    return (int)value->calculate();
}

void VarCommand::setCommand(string& str){

}

VarCommand::VarCommand(string name, Expression *value , string path, mapCommand *commandTable,
        symbolTable *varTable, ShuntingYard* shuntingYard) :
        Commands(commandTable,varTable , shuntingYard) {
    VarCommand::name = name;
    VarCommand::path = path;
    VarCommand::value = value;
}

const string &VarCommand::getSentence() const {
    return path;
}

/*
 * This func sets the var's value.
 */
void VarCommand::setValue(Expression *value) {
    // lock thread.
    pthread_mutex_lock(&mutex);
   // delete this->value;
    VarCommand::value = value;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
}

Expression *VarCommand::getValue() const {
    return value;
}

string VarCommand::getName() {
    return name;
}

vector<VarCommand*> VarCommand::getFriends(){
    return friends;
}

/*
 * This func updates all "firends" with the new information.
 * ("friends" are two variables that got the same path).
 */
void VarCommand::setFriends(){
    map<string,VarCommand*> :: iterator it;
    for(it = varTable->getSymbolMap().begin(); it != varTable->getSymbolMap().end(); it++){
        if((*it).second->getSentence() == path){
            friends.push_back((*it).second);
        }
    }
}