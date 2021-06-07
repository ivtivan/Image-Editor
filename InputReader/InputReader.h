#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "../CommandInterpreter/CommandInterpreter.h"

class InputReader {
    private:
        InputReader();
    public:
        InputReader(const InputReader&) = delete;
        InputReader& operator=(const InputReader&) = delete;

        static InputReader& instance();

        void printCommands();
        void readCommands();
};

#endif