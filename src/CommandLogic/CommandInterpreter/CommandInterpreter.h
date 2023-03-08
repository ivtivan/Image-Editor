#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"
#include "../../Controllers/ControllerFrame/ControllerFrame.h"

/**
 *  Allows the execution of a command.
 */

class CommandInterpreter {
    private:
        ControllerFrame controller_frame;
    public:
        CommandInterpreter();
        void execute(const Command& command);
};

#endif