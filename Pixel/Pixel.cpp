#include "Pixel.h"

Pixel::Pixel() : maxValue(1), isRGB(false) {
}

Pixel::Pixel(const Pixel& pixel) : maxValue(pixel.maxValue),
    isRGB(pixel.isRGB) {
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
    this->isRGB = pixel.isRGB;
    this->value[0] = pixel.value[0];
    if (pixel.isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            this->value[i] = pixel.value[i];
        }
    }

    return *this;
}

void Pixel::setMaxValue(const unsigned int maxValue) {
    this->maxValue = maxValue;
}

void Pixel::setValue(const unsigned int value) {
    this->value[0] = value;

    if (this-> isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            this->value[i] = value;
        }
    }
}

void Pixel::setRGBValue(unsigned int value[MAX_VALUES_COUNT]) {
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        this->value[i] = value[i];
    }
}

void Pixel::incrementDitherValue(const double incr) {
    this->ditherValue += incr;
}

const unsigned int Pixel::getMaxValue() const {
    return this->maxValue;
}

const double Pixel::getValue() const {
    if (this->isRGB == false) {
        return (double)value[0];
    }

    // Formula from https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
    return (double)value[0] * 0.3 + (double)value[1] * 0.59 + (double)value[2] * 0.11)
}

const double Pixel::getDitherValue() const {
    return this->ditherValue;
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