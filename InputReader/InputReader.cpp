#include "InputReader.h"

void PVDatabase::printCommands() {
    std::cout << "------------------------------------\n";
    std::cout << "Commands supported:\n";
    std::cout << "open <file path>\n";
    std::cout << "saveas <file path>\n";
    std::cout << "exit\n";
    std::cout << "------------------------------------\n";
    std::cout << std::endl;
}

void PVDatabase::readCommands() {
    std::string inputCommand;

    while (true) {
        std::cout << "Command: ";
        getline(std::cin, inputCommand);
        try {
            CommandInterpreter::execute(inputCommand);
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