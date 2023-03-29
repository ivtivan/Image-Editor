#include "PBMPixel.h"

PBMPixel::PBMPixel(unsigned char value) : Pixel(1) , value(value) {
}

const std::string PBMPixel::toString() const {
    return std::to_string((int)value);
}

double PBMPixel::getValue() const {
    return (double)value;
}

void PBMPixel::setToMaxValue() {
    value = getMaxValue();
}

void PBMPixel::setToMinValue() {
    value = getMinValue();
}