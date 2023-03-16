#include "CommandInterpreter.h"
#include "../../Controllers/ControllerFacade/ControllerFacade.h"

CommandInterpreter::CommandInterpreter() {
    ;
}

const bool CommandInterpreter::execute(const Command& command) {
    bool result;
    if (command.getCommand() == "new") {
        result = controllerFacade.create(command.getParams());
    }
    else if (command.getCommand() == "open") {
        result = controllerFacade.open(command.getParams());
    }
    else if (command.getCommand() == "close") {
        result = controllerFacade.close();
    }
    else if (command.getCommand() == "save") {
        result = controllerFacade.save();
    }
    else if (command.getCommand() == "saveas") {
        result = controllerFacade.saveAs(command.getParams());
    }
    else if (command.getCommand() == "crop") {
        result = controllerFacade.crop(command.getParams());
    }
    else if (command.getCommand() == "resize") {
        result = controllerFacade.resize(command.getParams());
    }
    else if (command.getCommand() == "dither") {
        result = controllerFacade.dither(command.getParams());
    }     
    else if (command.getCommand() == "exit") {
        return false;    
    }
    else {
        std::cout << "Command was not recognized." << std::endl;
    }
    // TODO: add handling based on rerturn value of functions
    // possibilities: handle it here or change function to const bool

    return result;
}