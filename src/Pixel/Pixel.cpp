#include "Pixel.h"

Pixel::Pixel() : minValue(0), maxValue(1), ditherValue(0) {
    ;
}

Pixel::Pixel(unsigned short maxValue) : minValue(0), maxValue(maxValue), ditherValue(0) {
    ;
}

unsigned short Pixel::getMinValue() const {
    return minValue;
}

unsigned short Pixel::getMaxValue() const {
    return maxValue;
}

double Pixel::getDitherValue() const {
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

double Pixel::getValue() const {
    return 0.0;
}

bool Pixel::isBlack() const {
    return true;
}

bool Pixel::isWhite() const {
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
