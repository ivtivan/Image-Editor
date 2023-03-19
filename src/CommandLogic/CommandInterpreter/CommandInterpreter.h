#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"
#include "../../Controllers/ControllerFacade/ControllerFacade.h"

/**
 *  Allows the execution of a command.
 */

class CommandInterpreter {
    private:
        ControllerFacade controllerFacade;
    public:
        CommandInterpreter();
        bool execute(const Command& command);
};

#endif