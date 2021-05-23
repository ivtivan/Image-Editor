#include "FileException.h"

FileException::FileException(const std::string& message) :
    message(message) {
        ;
}

const char* FileException::what() const throw() {
     return message.c_str();
}