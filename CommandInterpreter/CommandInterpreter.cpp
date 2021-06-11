#include "CommandInterpreter.h"
#include "../CustomExceptions/ExitException/ExitException.h"
#include "../FileController/FileController.h"
#include "../Editor/Editor.h"

CommandInterpreter::CommandInterpreter() {
    ;
}

CommandInterpreter& CommandInterpreter::instance() {
    static CommandInterpreter cI;
    return cI;
}

void CommandInterpreter::execute(Command command) {
    if (command[0] == "new") {
        std::size_t rows = atoi(command[1].c_str());
        std::size_t cols = atoi(command[2].c_str());
        FileController::instance().createFile(rows, cols, command[3]);
        std::cout << "Creating successful." << std::endl;
    }
    else if (command[0] == "open") {
        FileController::instance().openFile(command[1]);
        std::cout << "Opened successfully." << std::endl;
    }
    else if (command[0] == "close") {
        FileController::instance().closeFile();
        std::cout << "Closing successful." << std::endl;
    }
    else if (command[0] == "save") {
        FileController::instance().saveFile();
        std::cout << "Saving successful." << std::endl;
    }
    else if (command[0] == "saveas") {
        FileController::instance().saveFileAs(command[1]);
        std::cout << "Saving successful." << std::endl;
    }
    else if (command[0] == "crop") {
        Image* image = FileController::instance().getImage();
        std::size_t x1 = atoi(command[1].c_str());
        std::size_t y1 = atoi(command[2].c_str());
        std::size_t x2 = atoi(command[3].c_str());
        std::size_t y2 = atoi(command[4].c_str());
        Editor::instance().cropImage(image, x1, y1, x2, y2);
        std::cout << "Cropping successful." << std::endl;
    }
    else if (command[0] == "resize") {
        Image* image = FileController::instance().getImage();
        std::size_t rows = atoi(command[1].c_str());
        std::size_t cols = atoi(command[2].c_str());
        Editor::instance().resizeImage(image, rows, cols);
        std::cout << "Resizing successful." << std::endl;
    }
    else if (command[0] == "dither") {
        Image* image = FileController::instance().getImage();
        Editor::instance().ditherImage(image, command[1]);
        std::cout << "Dithering successful." << std::endl;
    }     
    else if (command[0] == "exit") {
        throw ExitException("Exit command registered. Program will exit.");
    }
    else {
        std::cout << "Command was not recognized." << std::endl;
    }
}