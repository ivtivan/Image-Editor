#include "PGMPixel.h"

PGMPixel::PGMPixel(unsigned short value, unsigned short maxValue) : 
    Pixel(maxValue) , value(value) {
    ;
}

const bool PGMPixel::isBlack() const {
    return value == getMinValue();
}

const bool PGMPixel::isWhite() const {
    return value == getMaxValue();
}

const std::string PGMPixel::toString() const {
    return std::to_string(value);
}

const double PGMPixel::getValue() const {
    return (double)value;
}

void PGMPixel::setToMaxValue() {
    value = getMaxValue();
}

void PGMPixel::setToMinValue() {
    value = getMinValue();
}