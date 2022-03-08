#include "Pixel.h"
#include "../CustomExceptions/CustomExceptions.h"
#include <cmath>

Pixel::Pixel(unsigned short maxValue, std::size_t length) : maxValue(maxValue), ditherValue(0) {
    this->value = new unsigned short[length];
}

Pixel::Pixel(const Pixel& pixel) : maxValue(pixel.maxValue),
    ditherValue(pixel.ditherValue) {
    setValue(pixel.getValueArray());
}

Pixel& Pixel::operator=(const Pixel& pixel) {
    if (this == &pixel) {
        return *this;
    }

    this->maxValue = pixel.maxValue;
    this->ditherValue = pixel.ditherValue;
    setValue(pixel.getValueArray());

    return *this;
}

const unsigned short* Pixel::getValueArray() const {
    return this->value;
}

const unsigned int Pixel::getMaxValue() const {
    return this->maxValue;
}

void Pixel::setValue(const unsigned short* value) {
    delete[] this->value;

    this->value = new unsigned short[sizeof(value) / sizeof(value[0])];
    for (std::size_t i = 0; i < sizeof(value) / sizeof(value[0]); ++i) {
        this->value[i] = value[i];
    }
}

void Pixel::setValue(std::string value) {
    std::stringstream colorReader;
    std::size_t colorLength = 2;
    for (std::size_t i = 0; i * colorLength + 1 < value.length(); ++i) {
        colorReader << value.substr(i * colorLength + 1, colorLength);
        colorReader >> std::hex >> this->value[i];
        colorReader.clear();
    }
}

void Pixel::setBlackOrWhite() {
    if (isBlackOrWhite() == false) {
        throw PixelException("The pixel is neither black nor white.");
    }
    this->maxValue = 1;

    if (this->value[0] > this->maxValue) {
        setValue(this->maxValue);
    }
}

void Pixel::swapBlackAndWhite() {
    if (isBlackOrWhite() == false) {
        throw PixelException("Pixel is neither white nor black.");
    }

    setValue(this->maxValue - value[0]);
}

void Pixel::incrementDitherValue(const double incr) {
    this->ditherValue += incr;
}

void Pixel::resetDitherValue() {
    this->ditherValue = 0.0;
}

const double Pixel::getDitherValue() const {
    return this->ditherValue;
}

const bool Pixel::isGrey() const {
    if (value == NULL) {
        throw PixelException("Pixel is not set.");
    }
    for (std::size_t i = 0; i < sizeof(this->value) / sizeof(this->value[0]); ++i) {
        if (this->value[0] != this->value[i]) {
            return false;
        }
    }
    return true;
}

const bool Pixel::isBlack() const {
    return ((int)getValue() == this->minValue);
}

const bool Pixel::isWhite() const {
    return ((int)getValue() == this->maxValue);
}

const bool Pixel::isBlackOrWhite() const {
    return (isWhite() || isBlack());
}

Pixel::~Pixel() {
    delete[] this->value;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << pixel.getValueString() << " ";
    return os;
}