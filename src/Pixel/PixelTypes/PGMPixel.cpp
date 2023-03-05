#include "PGMPixel.h"

PGMPixel::PGMPixel(unsigned short value, unsigned short maxValue) : 
    Pixel(maxValue) , value(value) {
    ;
}

const bool PGMPixel::isBlack() const {
    return value == 0;
}

const bool PGMPixel::isWhite() const {
    return value == maxValue;
}

const std::string PGMPixel::toString() const {
    return std::to_string(value);
}

const double PGMPixel::getValue() const {
    return (double)value;
}