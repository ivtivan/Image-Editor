#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "../CommandInterpreter/CommandInterpreter.h"

/**
 * Singleton class.
 * Allows reading input from terminal.
 */

class InputReader {
    private:
        InputReader();
    public:
        InputReader(const InputReader&) = delete;
        InputReader& operator=(const InputReader&) = delete;

        static InputReader& instance();

        /**
         * Prints supported commands.
         */
        void printCommands();

        /**
         * Reads command from terminal.
         */
        void readCommands();
};

#endif