#include "Image.h"
#include <fstream>

Image::Image() : rows(0) , cols(0), pixels(nullptr) {
    ;
}

Image::Image(std::size_t rows, std::size_t cols, Pixel*** pixels) :
    rows(rows), cols(cols), pixels(pixels) {
    ;
}


std::size_t Image::getRows() const {
    return this->rows;
}

Pixel* Image::getPixelAt(std::size_t row, std::size_t col) const {
    return pixels[row][col];
}

std::size_t Image::getCols() const {
    return this->cols;
}

void Image::setPixels(Pixel*** pixels) {
    this->pixels = pixels;
}


std::ostream& operator<<(std::ostream& os, const Image* image) {
    os << image->getTypeID() << std::endl;
    os << image->getCols() << " " << image->getRows() << std::endl;

    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {
            os << image->getPixelAt(i, j);

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
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            delete pixels[i][j];
        }
        delete pixels[i];
    }
    delete pixels;
}