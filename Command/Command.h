#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

/**
 * @brief KSupports working with commands.
 * 
 * Keeps a command and its parameters in a vector.
 * Created through splitting a string in substrings.
 */
class Command {
    private:
        /**
         * @brief Contains command and arguments
         * 
         */
        std::vector<std::string> comm;

        /**
         * @brief Converts uppercase letters in string to lowercase.
         * 
         */
        void toLower(std::string& str);

        /**
         * @brief Removes unneeded spaces.
         * 
         * Removes space at the beginning and at the end, and 
         * replaces multiple cnsecutive spaces with a single one.
         */
        void removeAdditionalSpaces(std::string& str);

        /**
         * @brief Saves substrings in a vector.
         * 
         * Splits a string in substrings and saves them in a vector.
         * Substrings are delimited by " ".
         */
        void splitInVector(std::string str);
    public:
        Command(std::string str);

        /**
         * @brief Accesses elements of the attribute vector.
         * 
         * Accesses elements of the attribute vector, containing commands and parameters.
         * The first element is the command.
         */
        std::string& operator[](std::size_t index);

        /**
         * @brief Accesses elements of the attribute vector.
         * 
         * Accesses elements of the attribute vector, containing commands and parameters.
         * The first element is the command.
         */
        const std::string& operator[](std::size_t index) const;
};

#endif