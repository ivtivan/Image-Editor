#include "CommandInterpreter.h"
#include "../../Controllers/ControllerFrame/ControllerFrame.h"

CommandInterpreter::CommandInterpreter() : controllerFrame() {
    ;
}

void CommandInterpreter::execute(const Command& command) {
    bool result;
    if (command.getCommand() == "new") {
        result = controllerFrame.create(command.getParams());
    }
    else if (command.getCommand() == "open") {
        result = controllerFrame.open(command.getParams());
    }
    else if (command.getCommand() == "close") {
        result = controllerFrame.close();
    }
    else if (command.getCommand() == "save") {
        result = controllerFrame.save();
    }
    else if (command.getCommand() == "saveas") {
        result = controllerFrame.saveAs(command.getParams());
    }
    else if (command.getCommand() == "crop") {
        result = controllerFrame.crop(command.getParams());
    }
    else if (command.getCommand() == "resize") {
        result = controllerFrame.resize(command.getParams());
    }
    else if (command.getCommand() == "dither") {
        result = controllerFrame.dither(command.getParams());
    }     
    else if (command.getCommand() == "exit") {
        controllerFrame.exit();
    }
    else {
        std::cout << "Command was not recognized." << std::endl;
    }
    // TODO: add handling based on rerturn value of functions
    // possibilities: handle it here or change function to const bool
}