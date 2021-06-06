#include "Command.h"

Command::Command(std::string str) {
    removeAdditionalSpaces(str);
    splitInVector(str);
    toLower(this->comm[0]);
}

void Command::toLower(std::string& str) {
    for (std::size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
}

void Command::removeAdditionalSpaces(std::string& str) {
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

void Command::splitInVector(std::string str) {
    std::size_t numParam = 0;
    std::size_t indexBegin = 0;
    bool isInQuotes = false;
    for (std::size_t i = 0; i < str.length(); ++i) {
        if (isInQuotes == true) {
            if (str[i] == '\"') {
                isInQuotes = false;
                this->comm.push_back(str.substr(indexBegin, i - indexBegin));
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
                this->comm.push_back(str.substr(indexBegin, i - indexBegin));
                ++numParam;
                indexBegin = i + 1;
            }
            else if (i == str.length() - 1) {
                this->comm.push_back(str.substr(indexBegin, i - indexBegin + 1));
            }
        }
    }
}

std::string& Command::operator[](std::size_t index) {
    return this->comm[index];
}

const std::string& Command::operator[](std::size_t index) const {
    return this->comm[index];
}