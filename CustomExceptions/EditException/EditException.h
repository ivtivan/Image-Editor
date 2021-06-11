#ifndef EDIT_EXCEPTION_H
#define EDIT_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception
 * Exception, that is thrown when editing.
 */
class EditException : std::exception {
    private:
        std::string message;
    public:
        EditException(const std::string& message);
        const char* what() const throw();
};
#endif