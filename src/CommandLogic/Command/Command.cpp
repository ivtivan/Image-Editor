#include "Command.h"

Command::Command(std::string str) {
    parseCommand(str);
}

void Command::parseCommand(const std::string& str) {
    extractCommand(str);
    extractParams(str); 
}

void Command::extractCommand(const std::string& str) {
    std::size_t commandIndex = getNextNonspaceIndex(0, str);
    command = str.substr(commandIndex,
        getNextSpaceIndex(commandIndex, str) - commandIndex);
}

std::size_t Command::getNextNonspaceIndex(std::size_t begin, const std::string& str) {
    while (begin < str.length() && isspace(str[begin])) {
        ++begin;
    }

    return begin;
}

std::size_t Command::getNextSpaceIndex(std::size_t begin, const std::string& str) {
    while (begin < str.length() && !isspace(str[begin])) {
        ++begin;
    }   

    return begin;
}

void Command::extractParams(const std::string& str) {
    std::size_t commandIndex = getNextNonspaceIndex(0, str);
    std::size_t commandEndIndex = getNextSpaceIndex(commandIndex, str);
    std::size_t paramEndIndex = commandEndIndex;
    std::size_t paramIndex = getNextNonspaceIndex(paramEndIndex, str);
    
    while (paramIndex < str.length()) {
        paramEndIndex = getNextSpaceIndex(paramIndex, str);
        params.push_back(str.substr(paramIndex, paramEndIndex - paramIndex));
        paramIndex = getNextNonspaceIndex(paramEndIndex, str);
    }
}

const std::string Command::getCommand() const {
    return command;
}

const std::vector<std::string> Command::getParams() const {
    return params;
}