#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "../Command/Command.h"
#include "../../FileController/FileController.h"

/**
 *  Allows the execution of a command.
 */

class CommandInterpreter {
    private:
        FileController fileController;

        const bool create(const std::vector<std::string> params);
        const bool open(const std::vector<std::string> params);
        const bool close();
        const bool save();
        const bool saveAs(const std::vector<std::string> params);
        const bool crop(const std::vector<std::string> params) const;
        const bool resize(const std::vector<std::string> params) const;
        const bool dither(const std::vector<std::string> params) const;
        const bool exit() const;
    public:
        CommandInterpreter();
        void execute(const Command& command);
};

#endif