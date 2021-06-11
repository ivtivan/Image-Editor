#ifndef EXIT_EXCEPTION_H
#define EXIT_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception.
 * Exception, that is thrown when the program must exit.
 */
class ExitException : std::exception {
    private:
        std::string message;
    public:
        ExitException(const std::string& message);
        const char* what() const throw();
};

#endif