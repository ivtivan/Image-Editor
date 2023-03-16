#include "PPMImage.h"

PPMImage::PPMImage(std::size_t rows, std::size_t cols, std::string hexColor) {
    this->rows = rows;
    this->cols = cols;
    
    allocatePixels();
    createPixels(hexColor);
}

void PPMImage::allocatePixels() {
    // placement-new used, care with destructor
    // TODO: TEST!!!!!
    pixels = new PPMPixel*[rows];
    for (std::size_t row = 0; row < rows; ++row) {
        pixels[row] = (PPMPixel*) operator new[](cols * sizeof(PPMPixel));
    }
}

void PPMImage::createPixels(const std::string& hexColor) {
    PPMPixel* pixel_ptr;
    for (std::size_t row = 0; row < rows; ++row) {
        pixel_ptr = static_cast<PPMPixel*>(pixels[row]);
        for (std::size_t col = 0; col < cols; ++col) {
            new(&pixel_ptr[col]) PPMPixel(hexColor);
        }
    }
}

void PPMImage::updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols) {
    //  TODO
} 

const std::string PPMImage::getTypeID() const {
    return "P3";
}

PPMImage::~PPMImage() {
    PPMPixel* toDelete;
    for (std::size_t row = 0; row < rows; ++row) {
        toDelete = static_cast<PPMPixel*>(pixels[row]);
        for (std::size_t col = 0; col < cols; ++col) {
            toDelete[col].~PPMPixel();
        }
        operator delete[](pixels[row]);
    }
    delete[] pixels;
}