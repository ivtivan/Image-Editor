#include "PixelTypes.h"
#include "../CustomExceptions/CustomExceptions.h"

/**
 * @brief PBM functionality.
 */

PBMPixel::PBMPixel() : Pixel(1, 1) {
    ;
}

PBMPixel::PBMPixel(unsigned short value) : Pixel(value, 1, 1) {
    ;
}

const double PBMPixel::getValue() const {
    return this->value[0];
}

const std::string PBMPixel::getValueString() const {
    return std::to_string(value[0]);
}

void PBMPixel::setValue(const unsigned short value) {
    this->value[0] = value;
}

const bool PBMPixel::isGrey() const {
    return true;
}

PBMPixel PBMPixel::toPBMPixel() {
    throw PixelException("The pixel is already in PBM.");
}

PGMPixel PBMPixel::toPGMPixel() {
    return PGMPixel(this->getMaxValue() - (unsigned short) (this->getValue()), this->getMaxValue());
}

PPMPixel PBMPixel::toPPMPixel() {
    return PPMPixel(this->getMaxValue() - (unsigned short) (this->getValue()), this->getMaxValue());
}

/**
 * @brief PGM functionality.
 */

PGMPixel::PGMPixel(unsigned short maxValue) : Pixel(maxValue, 1) {
    ;
}

PGMPixel::PGMPixel(unsigned short value, unsigned short maxValue) : Pixel(value, maxValue, 1) {
    ;
}

const double PGMPixel::getValue() const {
    return this->value[0];
}

const std::string PGMPixel::getValueString() const {
    return std::to_string(value[0]);
}

void PGMPixel::setValue(const unsigned short value) {
    this->value[0] = value;
}

const bool PGMPixel::isGrey() const {
      return true;
}

PBMPixel PGMPixel::toPBMPixel() {
    if (this->isBlack()) {
        return PBMPixel(1);
    }
    if (this->isWhite()) {
        return PBMPixel(0);
    }

    throw PixelException("The pixel is neither black nor white and cannot be converted.");
}

PGMPixel PGMPixel::toPGMPixel() {
    throw PixelException("The pixel is already in PGM.");
}

PPMPixel PGMPixel::toPPMPixel() {
    return PPMPixel((unsigned short) (this->getValue()), this->getMaxValue());
}

/**
 * @brief PPM functionality.
 */

PPMPixel::PPMPixel(unsigned short maxValue) : Pixel(maxValue, 3) {
    ;
}

PPMPixel::PPMPixel(unsigned short value, unsigned short maxValue) : Pixel(value, maxValue, 3) {
    ;
}

const double PPMPixel::getValue() const {
    // Formula from https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
    return (double)this->value[0] * 0.3 + (double)this->value[1] * 0.59 + (double)this->value[2] * 0.11;
}

const std::string PPMPixel::getValueString() const {
    return std::to_string(value[0]);
}

void PPMPixel::setValue(const unsigned short value) {
    for (std::size_t i = 0; i < 3; ++i) {
        this->value[i] = value;
    }
}

const bool PPMPixel::isGrey() const {
      return this->value[0] == this->value[1] && this->value[0] == this->value[2];
}

PBMPixel PPMPixel::toPBMPixel() {
    if (this->isBlack()) {
        return PBMPixel(1);
    }
    if (this->isWhite()) {
        return PBMPixel(0);
    }

    throw PixelException("The pixel is neither black nor white and cannot be converted.");
}

PGMPixel PPMPixel::toPGMPixel() {
    return PGMPixel((unsigned short) (this->getValue()), this->getMaxValue());
}

PPMPixel PPMPixel::toPPMPixel() {
    throw PixelException("The pixel is already in PPM.");
}