#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"

/**
 * @brief Allows the execution of a command.
 * 
 * Singleton class.
 */

class CommandInterpreter {
    public:
        CommandInterpreter();
        void execute(Command command);
};

#endif