#include <iostream>
#include "InputReader/InputReader.h"

int main() {
    InputReader::instance().printCommands();
    
    InputReader::instance().readCommands();

    return 0;
}