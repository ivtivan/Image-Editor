#ifndef IMAGE_EXCEPTION_H
#define IMAGE_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception
 * Exception, that is thrown when creating an image.
 */
class ImageException : std::exception {
    private:
        std::string message;
    public:
        ImageException(const std::string& message);
        const char* what() const throw();

};

#endif