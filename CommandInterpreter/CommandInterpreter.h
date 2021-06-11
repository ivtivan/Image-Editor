#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"

/**
 * Singleton class.
 * Allows the execution of a command.
 */

class CommandInterpreter {
    private:
        CommandInterpreter();
    public:
        CommandInterpreter(const CommandInterpreter&) = delete;
        CommandInterpreter& operator=(const CommandInterpreter&) = delete;

        static CommandInterpreter& instance();

        /**
         * Call the function, needed to execute the command.
         */
        void execute(Command command);
};

#endif