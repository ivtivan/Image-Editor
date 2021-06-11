#include "ImageException.h"

ImageException::ImageException(const std::string& message) :
    message(message) {
        ;
}

const char* ImageException::what() const throw() {
     return message.c_str();
}