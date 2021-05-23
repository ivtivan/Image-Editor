#include "ExitException.h"

ExitException::ExitException(const std::string& message) :
    message(message) {
        ;
}

const char* ExitException::what() const throw() {
     return message.c_str();
}