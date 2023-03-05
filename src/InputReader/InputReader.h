#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "../CommandLogic/CommandInterpreter/CommandInterpreter.h"

/**
 * @brief Allows reading input from terminal.
 */

// TODO: rename
class InputReader {
    private:
        CommandInterpreter commandInterpreter;

        std::string readCommand();
    public:
        InputReader();
        
        void printCommands();
        void readCommands();
};

#endif