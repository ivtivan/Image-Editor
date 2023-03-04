#include <iostream>
#include "src/InputReader/InputReader.h"

int main() {
    InputReader inputReader;
    
    inputReader.printCommands();
    inputReader.readCommands();

    return 0;
}