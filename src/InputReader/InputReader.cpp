#include "InputReader.h"
#include <iostream>

InputReader::InputReader() {
    ;
}

void InputReader::printCommands() {
    std::cout << "-------------------------------------------------\n";
    std::cout << "Commands supported:\n";
    std::cout << "new <rows> <cols> <color>\n";
    std::cout << "open <file path>\n";
    std::cout << "close\n";
    std::cout << "save\n";
    std::cout << "saveas <file path>\n";
    std::cout << "exit\n";
    std::cout << "crop <x1> <y1> <x2 (x2 >= x1)> <y2 (y2 >= y1)>\n";
    std::cout << "resize <rows> <cols>\n";
    std::cout << "dither <algorithmName>\n";
    std::cout << "Algorithms supported: Linear, FS, JJN, Atkinson, \n";
    std::cout << "Burkes, Sierra, TRSierra, SierraLite, Stucku, \n";
    std::cout << "4Bayer, 8Bayer \n";
    std::cout << "-------------------------------------------------\n";
    std::cout << std::endl;
}

std::string InputReader::readCommand() {
    std::string inputCommand;
    std::cout << "Command: ";
    getline(std::cin, inputCommand);
    return inputCommand;
}

void InputReader::readCommands() {
    bool isInValidState = true;
    while (isInValidState) {
        Command command(readCommand());

        isInValidState = commandInterpreter.execute(command);
    }
}