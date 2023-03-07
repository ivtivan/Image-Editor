#include "PPMImage.h"

PPMImage::PPMImage(const std::ifstream& sourceFile) : Image(sourceFile) {

}

PPMImage::PPMImage(std::string hexColor, std::size_t rows, std::size_t cols) {
    this->rows = rows;
    this->cols = cols;
    
    allocatePixels();
}

void PPMImage::allocatePixels() {
    // placement-new used, care with destructor
    // TODO: TEST!!!!!
    pixels = new PPMPixel*[rows];
    for (std::size_t row = 0; row < rows; ++row) {
        pixels[row] = (PPMPixel*) operator new[](cols * sizeof(PPMPixel));
    }
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