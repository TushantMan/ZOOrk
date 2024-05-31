//
// Created by Tushant Man Singh on 31/5/2024.
//

#ifndef ZOORK_HELPCOMMAND_H
#define ZOORK_HELPCOMMAND_H
#include "Command.h"

class HelpCommand : public Command {
public:
    HelpCommand() : Command(nullptr) {}
    void execute() override;
};
#endif //ZOORK_HELPCOMMAND_H
