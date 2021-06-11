#include "Pixel.h"
#include "../CustomExceptions/PixelException/PixelException.h"
#include <cmath>

Pixel::Pixel() : maxValue(1), isRGB(false) {
}

Pixel::Pixel(const Pixel& pixel) : maxValue(pixel.maxValue),
    isRGB(pixel.isRGB), ditherValue(pixel.ditherValue) {
    this->value[0] = pixel.value[0];
    if (pixel.isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            this->value[i] = pixel.value[i];
        }
    }
}

Pixel& Pixel::operator=(const Pixel& pixel) {
    if (this == &pixel) {
        return *this;
    }

    this->maxValue = pixel.maxValue;
    this->ditherValue = pixel.ditherValue;
    this->isRGB = pixel.isRGB;
    this->value[0] = pixel.value[0];
    if (pixel.isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            this->value[i] = pixel.value[i];
        }
    }

    return *this;
}

const unsigned int Pixel::getMaxValue() const {
    return this->maxValue;
}

const double Pixel::getValue() const {
    if (this->isRGB == false) {
        return (double)this->value[0];
    }

    // Formula from https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
    return (double)this->value[0] * 0.3 + (double)this->value[1] * 0.59 + (double)this->value[2] * 0.11;
}

void Pixel::setMaxValue(const unsigned int maxValue) {
    this->maxValue = maxValue;
}

void Pixel::setValue(const unsigned int value) {
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        this->value[i] = value;
    }
}

void Pixel::setValue(unsigned int value[MAX_VALUES_COUNT]) {
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        this->value[i] = value[i];
    }
    
    this->isRGB = true;
}

void Pixel::setValue(std::string value) {
    std::stringstream colorReader;
    std::size_t colorLength = 2;
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        colorReader << value.substr(i * colorLength + 1, colorLength);
        colorReader >> std::hex >> this->value[i];
        colorReader.clear();
    }

    this->isRGB = true;
}

void Pixel::setRGB(bool value) {
    if (this->isRGB == false || value == true || isGrey() == true) {
        if (this->isRGB == false && value == true) {
            unsigned int maxValueRGB = 255;
            unsigned int adjustedValue = this->value[0] * maxValueRGB / this->maxValue;
            adjustedValue = std::round(std::min((double)adjustedValue, (double)maxValueRGB));
            setValue(adjustedValue);
            this->maxValue = maxValueRGB;
        }

        this->isRGB = value;
    }
    else {
        throw PixelException("Setting RGB value to false will result in loss of data.");
    }
}

void Pixel::setBlackOrWhite() {
    if (isBlackOrWhite() == false) {
        throw PixelException("The pixel is neither black nor white.");
    }

    this->isRGB = false;
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
    if (this->isRGB == true) {
        return (this->value[0] == this->value[1] && this->value[0] == this->value[2]);
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

std::ostream& operator<<(std::ostream& os, Pixel pixel) {
    os << pixel.value[0];
    
    if (pixel.isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            os << " " << pixel.value[i];
        }
    }
    os << " ";
    return os;
}