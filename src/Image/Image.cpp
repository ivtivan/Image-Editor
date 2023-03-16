#include "Image.h"
#include <fstream>

Image::Image() : cols(0), rows(0) {
    this->pixels = nullptr;
}

const std::size_t Image::getRows() const {
    return this->rows;
}

Pixel** Image::getPixels() const {
    return pixels;
}

const std::size_t Image::getCols() const {
    return this->cols;
}

std::ostream& operator<<(std::ostream& os, const Image* image) {
    os << image->getTypeID() << std::endl;
    os << image->getCols() << " " << image->getRows() << std::endl;

    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {
            os << image->getPixels();

            if (j != image->getCols()- 1) {
                os << " ";
            }
        }
        os << '\n';
    }
    return os;
}

void Image::allocatePixels() {
    ;
}

void Image::updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols) {
    ;
}

const std::string Image::getTypeID() const {
    return "";
}

Image::~Image() {
    ;
}