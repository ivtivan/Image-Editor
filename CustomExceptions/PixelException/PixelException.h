#ifndef PIXEL_EXCEPTION_H
#define PIXEL_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception.
 * Exception, that is thrown when working with pixels.
 */
class PixelException : std::exception {
    private:
        std::string message;
    public:
        PixelException(const std::string& message);
        const char* what() const throw();

};

#endif