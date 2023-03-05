#include "CommandInterpreter.h"
#include "../CustomExceptions/CustomExceptions.h"
#include "../FileController/FileController.h"
#include "../Editor/Editor.h"

CommandInterpreter::CommandInterpreter() : fileController() {
    ;
}

const bool CommandInterpreter::create(const std::vector<std::string> params) {
    // TODO: CREATE FILE
    return fileController.create();
}

const bool CommandInterpreter::open(const std::vector<std::string> params) {
    return fileController.open(params.at(0));
}

const bool CommandInterpreter::close() {
    return fileController.close();
}

const bool CommandInterpreter::save() {
    //TODO
    return true && fileController.close();
}

const bool CommandInterpreter::saveAs(const std::vector<std::string> params) {
    //TODO
    return true && fileController.close();
}

const bool CommandInterpreter::crop(const std::vector<std::string> params) const {
    // TODO:
    // Image* image = FileController::instance().getImage();
    std::size_t x1 = std::stoi(params.at(0));
    std::size_t y1 = std::stoi(params.at(1));
    std::size_t x2 = std::stoi(params.at(2));
    std::size_t y2 = std::stoi(params.at(3));
    // Editor::instance().cropImage(image, x1, y1, x2, y2);
}

const bool CommandInterpreter::resize(const std::vector<std::string> params) const {
    // TODO:
    //Image* image = FileController::instance().getImage();
    std::size_t rows = std::stoi(params.at(0));
    std::size_t cols = std::stoi(params.at(1));
    //Editor::instance().resizeImage(image, rows, cols);
    return true;
}

const bool CommandInterpreter::dither(const std::vector<std::string> params) const {
    // TODO: access image
    // Editor::instance().ditherImage(/* TODO */, params.at(0));
    return true;
}

const bool CommandInterpreter::exit() const {
    // TODO
    throw ExitException("Exit command registered. Program will exit.");
}

void CommandInterpreter::execute(const Command& command) {
    bool result;
    if (command.getCommand() == "new") {
        result = create(command.getParams());
    }
    else if (command.getCommand() == "open") {
        result = open(command.getParams());
    }
    else if (command.getCommand() == "close") {
        result = close();
    }
    else if (command.getCommand() == "save") {
        result = save();
    }
    else if (command.getCommand() == "saveas") {
        result = saveAs(command.getParams());
    }
    else if (command.getCommand() == "crop") {
        result = crop(command.getParams());
    }
    else if (command.getCommand() == "resize") {
        result = resize(command.getParams());
    }
    else if (command.getCommand() == "dither") {
        result = dither(command.getParams());
    }     
    else if (command.getCommand() == "exit") {
        exit();
    }
    else {
        std::cout << "Command was not recognized." << std::endl;
    }
    // TODO: add handling based on rerturn value of functions
    // possibilities: handle it here or change function to const bool
}