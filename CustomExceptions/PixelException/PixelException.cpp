#include "PixelException.h"

PixelException::PixelException(const std::string& message) :
    message(message) {
        ;
}

const char* PixelException::what() const throw() {
     return message.c_str();
}