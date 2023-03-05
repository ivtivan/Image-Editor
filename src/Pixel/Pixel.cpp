#include "Pixel.h"
#include "../CustomExceptions/CustomExceptions.h"

Pixel::Pixel() : minValue(0), ditherValue(0) {
    ;
}

Pixel::Pixel(unsigned short maxValue) : minValue(0), ditherValue(0),
    maxValue(maxValue) {
    ;
}

const unsigned short Pixel::getMaxValue() const {
    return maxValue;
}

void Pixel::incrementDitherValue(const double incr) {
    ditherValue += incr;
}

void Pixel::resetDitherValue() {
    ditherValue = 0.0;
}

const double Pixel::getDitherValue() const {
    return ditherValue;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)  {
    os << pixel.toString() << " ";
    return os;
}