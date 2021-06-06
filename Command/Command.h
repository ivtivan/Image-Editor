#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

class Command {
    private:
        std::vector<std::string> comm; 
        void toLower(std::string& str);
        void removeAdditionalSpaces(std::string& str);
        void splitInVector(std::string str);

        // Formats the command in the needed form.
        void formatCommand();
    public:
        Command(std::string str);

        std::string& operator[](std::size_t index);
        const std::string& operator[](std::size_t index) const;
};

#endif