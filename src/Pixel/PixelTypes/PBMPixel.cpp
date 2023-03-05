#include "PBMPixel.h"

PBMPixel::PBMPixel(unsigned char value) : Pixel(1) , value(value) {
}

const bool PBMPixel::isBlack() const {
    return value == 1;
}

const bool PBMPixel::isWhite() const {
    return value == 0;
}

const std::string PBMPixel::toString() const {
    return std::to_string((int)value);
}

const double PBMPixel::getValue() const {
    return (double)value;
}