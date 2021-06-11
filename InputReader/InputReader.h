#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "../CommandInterpreter/CommandInterpreter.h"

/**
 * @brief Allows reading input from terminal.
 * 
 * Singleton class.
 */

class InputReader {
    private:
        InputReader();
    public:
        InputReader(const InputReader&) = delete;
        InputReader& operator=(const InputReader&) = delete;

        static InputReader& instance();

        /**
         * @brief Prints supported commands.
         * 
         */
        void printCommands();

        /**
         * @brief Reads command from terminal.
         * 
         */
        void readCommands();
};

#endif