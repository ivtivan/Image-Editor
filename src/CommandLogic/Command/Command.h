#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

/**
 *  Supports working with commands.
 * 
 *  Created through splitting a string in substrings.
 */
class Command {
    private:
        std::string command;
        std::vector<std::string> params;

        std::size_t getNextNonspaceIndex(std::size_t begin, const std::string& str);  
        std::size_t getNextSpaceIndex(std::size_t begin, const std::string& str);
        void extractCommand(const std::string& str);
        void extractParams(const std::string& str);
        void parseCommand(const std::string& str);
    public:
        Command(std::string str);

        const std::string getCommand() const;
        const std::vector<std::string> getParams() const;
};

#endif