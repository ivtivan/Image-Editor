#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

/**
 * Command class
 * Keeps a command and its parameters in a vector.
 * Created through splitting a string in substrings.
 */
class Command {
    private:
        /**
         * Contains command and arguments.
         */
        std::vector<std::string> comm;

        /**
         * Converts uppercase letters in string to lowercase.
         */
        void toLower(std::string& str);

        /**
         * Removes space at the beginning and at the end, and 
         * replaces multiple cnsecutive spaces with a single one.
         */
        void removeAdditionalSpaces(std::string& str);

        /**
         * Splits a string in substrings and saves them in a vector.
         * Substrings are delimited by " ".
         */
        void splitInVector(std::string str);
    public:
        /**
         * Calls the needed functions in order to
         * split the string in substrings.
         */
        Command(std::string str);

        /**
         * Accesses elements of the vector, containing commands and parameters.
         * The first element is the command.
         */
        std::string& operator[](std::size_t index);

        /**
         * Accesses elements of the vector, containing commands and parameters.
         * The first element is the command.
         */
        const std::string& operator[](std::size_t index) const;
};

#endif