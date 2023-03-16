#include "PPMPixel.h"

PPMPixel::PPMPixel(unsigned short value[3], unsigned short maxValue) : Pixel(maxValue) {
    for (unsigned short i = 0; i < 3; ++i) {
        this->value[i] = value[i];
    }
}

PPMPixel::PPMPixel(std::string hex) : Pixel(255) {
    for (unsigned short i = 0; i < 3; ++i) {
        this->value[i] = std::stoi(hex.substr(2 * i + 1, 2));
    }
}

const bool PPMPixel::isBlack() const {
    bool isBlack;
    for (unsigned short i = 0; i < 3; ++i) {
        isBlack = isBlack && (value[i] == getMinValue());
    }
    return isBlack;
}

const bool PPMPixel::isWhite() const {
    bool isWhite;
    for (unsigned short i = 0; i < 3; ++i) {
        isWhite = isWhite && (value[i] == getMaxValue());
    }
    return isWhite;
}

const std::string PPMPixel::toString() const {
    return std::to_string(value[0]) + " " + std::to_string(value[1])
        + " " + std::to_string(value[2]) + " ";
}

const double PPMPixel::getValue() const {
    // Formula from https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
    return (double)this->value[0] * 0.3 + (double)this->value[1] * 0.59 +
        (double)this->value[2] * 0.11;
}

void PPMPixel::setToMaxValue() {
    for (unsigned short i = 0; i < 3; ++i) {
        value[i] = getMaxValue();
    }
}

void PPMPixel::setToMinValue() {
    for (unsigned short i = 0; i < 3; ++i) {
        value[i] =  getMinValue();
    }
}