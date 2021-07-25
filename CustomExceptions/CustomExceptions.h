#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

#include <string>

/**
 * @brief Custom exception.
 * Exception, that is thrown when editing an image.
 */
class EditException : std::exception {
    private:
        std::string message;
    public:
        EditException(const std::string& message);
        const char* what() const throw();

};

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


/**
 * @brief Custom exception.
 * Exception, that is thrown when working with a file.
 */
class FileException : std::exception {
    private:
        std::string message;
    public:
        FileException(const std::string& message);
        const char* what() const throw();
};

/**
 * @brief Custom exception.
 * Exception, that is thrown when creating an image.
 */
class ImageException : std::exception {
    private:
        std::string message;
    public:
        ImageException(const std::string& message);
        const char* what() const throw();

};

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