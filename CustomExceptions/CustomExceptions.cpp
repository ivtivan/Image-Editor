#include "CustomExceptions.h"

EditException::EditException(const std::string& message) :
    message(message) {
        ;
}

const char* EditException::what() const throw() {
     return message.c_str();
}

ExitException::ExitException(const std::string& message) :
    message(message) {
        ;
}

const char* ExitException::what() const throw() {
     return message.c_str();
}

FileException::FileException(const std::string& message) :
    message(message) {
        ;
}

const char* FileException::what() const throw() {
     return message.c_str();
}

ImageException::ImageException(const std::string& message) :
    message(message) {
        ;
}

const char* ImageException::what() const throw() {
     return message.c_str();
}

PixelException::PixelException(const std::string& message) :
    message(message) {
        ;
}

const char* PixelException::what() const throw() {
     return message.c_str();
}