#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"

/**
 * @brief Allows the execution of a command
 * Allows the execution of a command.
 * 
 * Singleton class
 */

class CommandInterpreter {
    private:
        CommandInterpreter();
    public:
        CommandInterpreter(const CommandInterpreter&) = delete;
        CommandInterpreter& operator=(const CommandInterpreter&) = delete;

        static CommandInterpreter& instance();

        /**
         * @brief Call the function, needed to execute the command.
         */
        void execute(Command command);
};

#endif