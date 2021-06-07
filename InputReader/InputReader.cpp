#include "InputReader.h"
#include "../Image/Image.h"
#include "../CustomExceptions/ExitException/ExitException.h"

#include <iostream>

InputReader::InputReader() {
    ;
}

InputReader& InputReader::instance() {
    static InputReader iR;
    return iR;
}

void InputReader::printCommands() {
    std::cout << "------------------------------------\n";
    std::cout << "Commands supported:\n";
    std::cout << "open <file path>\n";
    std::cout << "saveas <file path>\n";
    std::cout << "exit\n";
    std::cout << "------------------------------------\n";
    std::cout << std::endl;
}

void InputReader::readCommands() {
    std::string inputCommand;
    while (true) {
        std::cout << "Command: ";
        getline(std::cin, inputCommand);
        Command command(inputCommand);
        try {
            CommandInterpreter::instance().execute(command);
        }
        catch (const ExitException& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}