#include "EditException.h"

EditException::EditException(const std::string& message) :
    message(message) {
        ;
}

const char* EditException::what() const throw() {
     return message.c_str();
}