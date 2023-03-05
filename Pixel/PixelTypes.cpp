#include "PixelTypes.h"

PBMPixel::PBMPixel(unsigned char value) : Pixel(1) , value(value) {
}

const bool PBMPixel::isBlack() const {
    return value == 1;
}

const bool PBMPixel::isWhite() const {
    return value == 0;
}


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

PPMPixel::PPMPixel(unsigned char value[3], unsigned short maxValue) : Pixel(maxValue) {
    for (char i = 0; i < 3; ++i) {
        this->value[i] = value[i];
    }
}

const bool PPMPixel::isBlack() const {
    bool isBlack;
    for (char i = 0; i < 3; ++i) {
        isBlack &= (value[i] == 0);
    }
    return isBlack;
}

const bool PPMPixel::isWhite() const {
    bool isWhite;
    for (char i = 0; i < 3; ++i) {
        isWhite &= (value[i] == maxValue);
    }
    return isWhite;
}