#include "CommandInterpreter.h"
#include "../CustomExceptions/CustomExceptions.h"
#include "../FileController/FileController.h"
#include "../Editor/Editor.h"

CommandInterpreter::CommandInterpreter() : fileController() {
    ;
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