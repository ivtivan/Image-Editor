#include "PPMImage.h"

PPMImage::PPMImage(const std::ifstream& sourceFile) : Image(sourceFile) {

}

PPMImage::PPMImage(std::string hexColor, std::size_t rows, std::size_t cols) {
    this->rows = rows;
    this->cols = cols;
}

void PPMImage::allocatePixels() {
    pixels = new PPMPixel*[rows];
    for (std::size_t row = 0; row < rows; ++row) {
        pixels[row] = new PPMPixel[cols];
    }
}

PPMImage::~PPMImage() {
    for (std::size_t row = 0; row < rows; ++row) {
        delete[] pixels[row];
    }
    delete[] pixels;
}