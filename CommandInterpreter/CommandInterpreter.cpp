#include "CommandInterpreter.h"
#include "../CustomExceptions/ExitException/ExitException.h"
#include "../FileController/FileController.h"
#include "../ImageEditors/Editor/Editor.h"

void CommandInterpreter::toLower(std::string& str) {
    for (std::size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
}

void CommandInterpreter::removeAdditionalSpaces(std::string& str) {
    char alteredStr[str.length()];
    std::size_t write = 0;
    std::size_t read = 0;
    bool isSpaced = true;
    
    // Removes all additional spaces except one space at the end (if there is such)
    while (read < str.length()) {
        if (isSpaced == true && str[read] != ' ') {
            isSpaced = false;
            alteredStr[write] = str[read];
            ++write;
        }
        else if (isSpaced == false) {
            alteredStr[write] = str[read];

            if (read != str.length() - 1 && str[read] == ' ') {
                isSpaced = true;
            }

            ++write;
        }
        ++read;
    }

    // If the last char is ' ', it is not coppied
    if (alteredStr[write - 1] == ' ') {
        --write;
    }

    str.assign(alteredStr, write);
}

void CommandInterpreter::splitInArray(std::string str, std::string commPar[]) {
    std::size_t numParam = 0;
    std::size_t indexBegin = 0;
    bool isInQuotes = false;
    for (std::size_t i = 0; i < str.length(); ++i) {
        if (isInQuotes == true) {
            if (str[i] == '\"') {
                isInQuotes = false;
                commPar[numParam] = str.substr(indexBegin, i - indexBegin);
                ++numParam;
                if (i < str.length() - 1 && str[i + 1] == ' ') {
                    ++i;
                }
                indexBegin = i + 1;
            }
        }
        else {
            if (str[i] == '\"') {
                isInQuotes = true;
                indexBegin = i + 1;
            }
            else if (str[i] == ' ') {
                commPar[numParam] = str.substr(indexBegin, i - indexBegin);
                ++numParam;
                indexBegin = i + 1;
            }
            else if (i == str.length() - 1) {
                commPar[numParam] = str.substr(indexBegin, i - indexBegin + 1);
            }
        }
    }
}

void CommandInterpreter::formatCommand(std::string commandAndParameters, std::string commPar[]) {
    removeAdditionalSpaces(commandAndParameters);
    splitInArray(commandAndParameters, commPar);
    toLower(commPar[0]);
}

void CommandInterpreter::callFunction(std::string commPar[]) {
    if (commPar[0] == "new") {
        FileController::instance().createFile(commPar[1]);
    }
    else if (commPar[0] == "open") {
        FileController::instance().createFile(commPar[1]);
    }
    else if (commPar[0] == "close") {
        FileController::instance().closeFile();
    }
    else if (commPar[0] == "save") {
        FileController::instance().saveFile();
    }
    else if (commPar[0] == "saveas") {
        FileController::instance().saveFileAs(commPar[1]);
    }
    else if (commPar[0] == "crop") {
        Image* image = FileController::instance().getImage();
        std::size_t x1 = atoi(commPar[1].c_str());
        std::size_t y1 = atoi(commPar[2].c_str());
        std::size_t x2 = atoi(commPar[3].c_str());
        std::size_t y2 = atoi(commPar[4].c_str());
        Editor::instance().cropImage(image, x1, y1, x2, y2);
    }
    else if (commPar[0] == "resize") {
        Image* image = FileController::instance().getImage();
        std::size_t rows = atoi(commPar[1].c_str());
        std::size_t cols = atoi(commPar[2].c_str());
        Editor::instance().resizeImage(image, rows, cols);
    }
    else if (commPar[0] == "dither") {
        Image* image = FileController::instance().getImage();
        Editor::instance().ditherImage(image, commPar[1]);
    }     
    else if (commPar[0] == "exit") {
        throw ExitException("Exit command registered. Program will exit.");
    }
}

void CommandInterpreter::execute(std::string commandAndParameters) {
    std::string commPar[MAX_NUMBER_PARAMETERS + 1];
    formatCommand(commandAndParameters, commPar);

    callFunction(commPar);
}