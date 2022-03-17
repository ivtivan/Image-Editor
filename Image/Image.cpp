#include "Image.h"
#include "../CustomExceptions/CustomExceptions.h"
#include <fstream>

Image::Image() : cols(0), rows(0) {
    this->pixels = nullptr;
}

Image::Image(const Image& image) {
    this->pixels = image.getPixels();
    this->rows = image.getRows();
    this->cols = image.getCols();
}

Image& Image::operator=(const Image& image) {
    if (this == &image) {
        return *this;
    }
    
    this->pixels = image.getPixels();
    this->rows = image.getRows();
    this->cols = image.getCols();

    return *this;
}

const std::size_t Image::getRows() const {
    return this->rows;
}

const std::size_t Image::getCols() const {
    return this->cols;
}

Pixel** Image::getPixels() const {
    return this->pixels;
}

void Image::setPixels(Pixel** pixels, std::size_t rows, std::size_t cols) {
    reset();
    
    this->pixels = pixels;
    this->rows = rows;
    this->cols = cols;
}

void Image::setPixels(std::string color, std::size_t rows, std::size_t cols) {
    if (isValidColor(color) == false) {
        throw ImageException("Color is not valid.");
    }

    reset();
    this->pixelMaxValue = 255;
    this->rows = rows;
    this->cols = cols;
    colorPixels(color);
}

const bool Image::isValidColor(std::string color) const {
    std::size_t validColorLength = 7;

    if (color.length() != validColorLength) {
        return false;
    }

    if (color[0] != '#') {
        return false;
    }

    for (std::size_t i = 1; i < validColorLength; ++i) {
        if (((color[i] >= '0' && color[i] <= '9') || 
            (color[i] >= 'a' && color[i] <= 'f') || 
            (color[i] >= 'A' && color[i] <= 'F')) == false) {
            return false;
        }
    }

    return true;
}

void Image::colorPixels(std::string color) {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            pixels[i][j].setValue(color);
        }
    }
}

void Image::fillPBM() {
    unsigned int countSetPixels = 0;
    for(std::size_t i = 0 ; i < this->content.length(); ++i) {
        if (this->content[i] != ' ') {
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(this->content[i] - '0');
            countSetPixels++;
        }
    }
}

void Image::fillPGM() {
    unsigned int countSetPixels = 0;
    std::string value;
    bool isSpaced = false;
    std::size_t begin = 0;

    for (std::size_t i = 0 ; i < this->content.length(); ++i) {
        if (this->content[i] == ' ' && isSpaced == false) {
            value = this->content.substr(begin, i - begin);
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(atoi(value.c_str()));
            countSetPixels++;
            isSpaced = true;
        }
        else if (this->content[i] != ' ' && isSpaced == true) {
            isSpaced = false;
            begin = i;
        }
    }

    if (this->content[this->content.length() - 1] != ' ' && this->content[this->content.length() - 1] != '\n') {
        value = this->content.substr(begin, this->content.length() - begin);
        this->pixels[countSetPixels / this->rows][countSetPixels % this->cols].setValue(atoi(value.c_str()));
    }
}

void Image::fillPPM() {
    unsigned int countSetPixels = 0;
    std::size_t valueCount = 0;
    unsigned int pixelValue[MAX_VALUES_COUNT];
    std::string value;
    bool isSpaced = false;
    std::size_t begin = 0;
    for (std::size_t i = 0 ; i < this->content.length() ; ++i) {
        if (this->content[i] == ' ' && isSpaced == false) {
            value = this->content.substr(begin, i - begin);
            pixelValue[valueCount] = atoi(value.c_str());
            valueCount = (valueCount + 1) % MAX_VALUES_COUNT;
            if (valueCount == 0) {
                this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(pixelValue);
                countSetPixels++;
            }
            isSpaced = true;
        }
        else if (this->content[i] != ' ' && isSpaced == true) {
            isSpaced = false;
            begin = i;
        }
    }

    if (this->content[this->content.length() - 1] != ' ') {
        value = this->content.substr(begin, this->content.length() - 1 - begin);
        pixelValue[valueCount] = atoi(value.c_str());
        valueCount = (valueCount + 1) % MAX_VALUES_COUNT;
        if (valueCount == 0) {
            this->pixels[countSetPixels / this->rows][countSetPixels % this->cols].setValue(pixelValue);
            countSetPixels++;
        }
    }
}

const bool Image::isGrey() const {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (!this->pixels[i][j].isGrey()) {
                return false;
            }
        }
    }

    return true;
}

const bool Image::isBlackAndWhite() const {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (!this->pixels[i][j].isBlackOrWhite()) {
                return false;
            }
        }
    }

    return true;
}

void Image::toPBMPixels() {
    if (isBlackAndWhite() == false) {
        throw FileException("Cannot convert file to PBM.");
    }

    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            pixels[i][j] = pixels[i][j].toPBMPixel();
        }
    }
}

void Image::toPGMPixels() {
    if (isGrey() == false) {
        throw FileException("Cannot convert file to PGM.");
    }

    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            pixels[i][j] = pixels[i][j].toPBMPixel();
        }
    }
}

void Image::toPPMPixels() {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            pixels[i][j] = pixels[i][j].toPBMPixel();
        }
    }
}

void Image::convertTo(fileType neededType) {
    if (this->type != neededType) {
        switch (neededType) {
            case PBM: convertToPBM(); break;
            case PGM: convertToPGM(); break;
            case PPM: convertToPPM(); break;
        }
    }
}

void Image::reset() {
    for (std::size_t i = 0; i < this->rows; ++i) {
        delete[] this->pixels[i];
    }

    delete[] this->pixels;

    this->pixels = nullptr;

    this->rows = 0;
    this->cols = 0;
}

Image* Image::operator*() {
    return this;
}

Image::~Image() {
    for (std::size_t i = 0; i < this->rows; ++i) {
        delete[] this->pixels[i];
    }

    delete[] this->pixels;
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
    switch (image.type) {
        case PBM: os << "P1" << std::endl; break;
        case PGM: os << "P2" << std::endl; break;
        case PPM: os << "P3" << std::endl; break;
    }

    os << image.cols << " " << image.rows << std::endl;

    switch (image.type) {
        case PGM: case PPM: os << image.pixels[0][0].getMaxValue() << std::endl; break;
    }

    for (std::size_t i = 0; i < image.rows; ++i) {
        for (std::size_t j = 0; j < image.cols; ++j) {
            os << image.pixels[i][j];

            if (j != image.cols - 1) {
                os << " ";
            }
        }
        os << '\n';
    }
    return os;
}