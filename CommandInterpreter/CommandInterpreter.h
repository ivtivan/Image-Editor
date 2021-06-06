#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"

// Allows the execution of a command in the form of a string.
// The command is formated in the needed way before calling 
// the respective function.

class CommandInterpreter {
    public:
        static void execute(Command command);
};

#endif