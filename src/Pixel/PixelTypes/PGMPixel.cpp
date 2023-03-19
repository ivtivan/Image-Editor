#include "PGMPixel.h"

PGMPixel::PGMPixel(unsigned short value, unsigned short maxValue) : 
    Pixel(maxValue) , value(value) {
    ;
}

bool PGMPixel::isBlack() const {
    return value == getMinValue();
}

bool PGMPixel::isWhite() const {
    return value == getMaxValue();
}

const std::string PGMPixel::toString() const {
    return std::to_string(value);
}

double PGMPixel::getValue() const {
    return (double)value;
}

void PGMPixel::setToMaxValue() {
    value = getMaxValue();
}

void PGMPixel::setToMinValue() {
    value = getMinValue();
}