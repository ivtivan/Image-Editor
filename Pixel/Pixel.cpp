#include "Pixel.h"

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

void Pixel::setValue(unsigned int value[MAX_VALUES_COUNT]) {
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        this->value[i] = value[i];
    }
}

void Pixel::setValue(std::string value) {
    std::stringstream colorReader;
    std::size_t colorLength = 2;
    for (std::size_t i = 0; i < MAX_VALUES_COUNT; ++i) {
        colorReader << value.substr(i * colorLength + 1, colorLength);
        colorReader >> std::hex >> this->value[i];
    }

    this->maxValue = 255;
    this->isRGB = true;
}

void Pixel::incrementDitherValue(const double incr) {
    this->ditherValue += incr;
}

void Pixel::resetDitherValue() {
    this->ditherValue = 0.0;
}

const unsigned int Pixel::getMaxValue() const {
    return this->maxValue;
}

const double Pixel::getValue() const {
    if (this->isRGB == false) {
        return (double)value[0];
    }

    // Formula from https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
    return (double)value[0] * 0.3 + (double)value[1] * 0.59 + (double)value[2] * 0.11;
}

const double Pixel::getDitherValue() const {
    return this->ditherValue;
}

std::ostream& operator<<(std::ostream& os, Pixel pixel) {
    os << pixel.value[0];
    
    if (pixel.isRGB == true) {
        for (std::size_t i = 1; i < MAX_VALUES_COUNT; ++i) {
            os << pixel.value[i];

            if (i != MAX_VALUES_COUNT - 1) {
                os << " ";
            }
        }
    }

    return os;
}