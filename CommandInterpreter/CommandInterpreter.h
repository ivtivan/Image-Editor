#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"

// Allows the execution of a command in the form of a string.
// The command is formated in the needed way before calling 
// the respective function.

class CommandInterpreter {
    private:
        CommandInterpreter();
    public:
        CommandInterpreter(const CommandInterpreter&) = delete;
        CommandInterpreter& operator=(const CommandInterpreter&) = delete;

        static CommandInterpreter& instance();

        void execute(Command command);
};

#endif