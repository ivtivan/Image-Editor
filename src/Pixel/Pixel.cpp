#include "Pixel.h"

Pixel::Pixel() : minValue(0), maxValue(1), ditherValue(0) {
    ;
}

Pixel::Pixel(unsigned short maxValue) : minValue(0), maxValue(maxValue), ditherValue(0) {
    ;
}

const unsigned short Pixel::getMinValue() const {
    return minValue;
}

const unsigned short Pixel::getMaxValue() const {
    return maxValue;
}

const double Pixel::getDitherValue() const {
    return ditherValue;
}

void Pixel::incrementDitherValue(const double incr) {
    ditherValue += incr;
}

void Pixel::resetDitherValue() {
    ditherValue = 0.0;
}

std::ostream& operator<<(std::ostream& os, const Pixel* pixel)  {
    os << pixel->toString() << " ";
    return os;
}

Pixel::~Pixel() {
    ;
}

const double Pixel::getValue() const {
    return 0.0;
}

const bool Pixel::isBlack() const {
    return true;
}

const bool Pixel::isWhite() const {
    return true;
}

void Pixel::setToMaxValue() {
    ;
}

void Pixel::setToMinValue() {
    ;
}

const std::string Pixel::toString() const {
    return "";
}
