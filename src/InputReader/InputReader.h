#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "../../CommandInterpreter/CommandInterpreter.h"

/**
 * @brief Allows reading input from terminal.
 */

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