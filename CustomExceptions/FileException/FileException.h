#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception
 * Exception, that is thrown when working with a file.
 */
class FileException : std::exception {
    private:
        std::string message;
    public:
        FileException(const std::string& message);
        const char* what() const throw();
};
#endif