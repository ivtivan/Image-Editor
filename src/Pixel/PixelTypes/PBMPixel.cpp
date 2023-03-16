#include "PBMPixel.h"

PBMPixel::PBMPixel(unsigned char value) : Pixel(1) , value(value) {
}

const bool PBMPixel::isBlack() const {
    return value == getMaxValue();
}

const bool PBMPixel::isWhite() const {
    return value == getMinValue();
}

const std::string PBMPixel::toString() const {
    return std::to_string((int)value);
}

const double PBMPixel::getValue() const {
    return (double)value;
}

void PBMPixel::setToMaxValue() {
    value = getMaxValue();
}

void PBMPixel::setToMinValue() {
    value = getMinValue();
}