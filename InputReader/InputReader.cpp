#include "InputReader.h"
#include "../Image/Image.h"
#include "../CustomExceptions/CustomExceptions.h"
#include <iostream>

InputReader::InputReader() {
    ;
}

InputReader& InputReader::instance() {
    static InputReader iR;
    return iR;
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
        catch (const FileException& e) {
            std::cout << e.what() << std::endl;
        }
        catch (const EditException& e) {
            std::cout << "Image not editted due to the following reason:" << std::endl;
            std::cout << e.what() << std::endl;
        }
        catch (const ImageException& e) {
            std::cout << "Image was not createds due to the following reason:" << std::endl;
            std::cout << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}