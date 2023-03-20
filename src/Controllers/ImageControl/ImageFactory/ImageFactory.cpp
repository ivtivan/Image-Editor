#include "ImageFactory.h"
#include <fstream>
#include <string>

ImageFactory::ImageFactory() {
    ;
}

PPMImage* ImageFactory::getPPMFromSizeColor(const Dimension& dimension,
    const std::string& hexColor) {
    this->dimension = &dimension;
    allocatePixelMatrix();
    fillPPMPixelMatrixColor(hexColor);
    return new PPMImage(dimension, pixels);
}

void ImageFactory::fillPPMPixelMatrixColor(const std::string& hexColor) {
    for (std::size_t row = 0; row < dimension->getRows(); ++row) {
        for (std::size_t col = 0; col < dimension->getCols(); ++col) {
            pixels[row][col] = new PPMPixel(hexColor);
        }
    }
}

Image* ImageFactory::loadImageFrom(std::ifstream& src) {
    this->src = &src;
    
    std::string type = readImageTypeIdentificator();
    saveDimension();
    allocatePixelMatrix();

    if (type == "P1") {
        return loadPBMImageFrom();
    }
    else if (type == "P2") {
        return loadPGMImageFrom();
    }
    else if (type == "P3") {
        return loadPPMImageFrom();
    }
    return nullptr;
}

std::string ImageFactory::readImageTypeIdentificator() {
    std::string type;
    *src >> type;
    return type;
}

void ImageFactory::saveDimension() {
    size_t rows, cols;
    *src >> rows >> cols;
    dimension = new Dimension(rows, cols);
}

void ImageFactory::allocatePixelMatrix() {
    const std::size_t rows = dimension->getRows();
    const std::size_t cols = dimension->getRows();
    
    pixels = new Pixel**[rows];
    for (std::size_t row = 0; row < rows; ++row) {
        pixels[row] = new Pixel*[cols];
    }
}

PBMImage* ImageFactory::loadPBMImageFrom() {
    readIntoPBMPixelMatrix();
    return new PBMImage(*dimension, pixels);
}

void ImageFactory::readIntoPBMPixelMatrix() {
    const std::size_t rows = dimension->getRows();
    const std::size_t cols = dimension->getRows();

    std::size_t curr = 0;
    unsigned short val;
    while (curr < rows * cols) {
        *src >> val;
        pixels[curr / cols][curr % cols] = new PBMPixel(val);
        ++curr;
    }
}

PGMImage* ImageFactory::loadPGMImageFrom() {
    readIntoPGMPixelMatrix();
    return new PGMImage(*dimension, pixels);
}

void ImageFactory::readIntoPGMPixelMatrix() {
    const std::size_t rows = dimension->getRows();
    const std::size_t cols = dimension->getRows();

    std::size_t curr = 0;
    unsigned short val;
    while (curr < rows * cols) {
        *src >> val;
        pixels[curr / cols][curr % cols] = new PGMPixel(val, maxValue);
        ++curr;
    }
}

void ImageFactory::saveMaxValue() {
    *src >> maxValue;
}

PPMImage* ImageFactory::loadPPMImageFrom() {
    readIntoPPMPixelMatrix();
    return new PPMImage(*dimension, pixels);
}


void ImageFactory::readIntoPPMPixelMatrix() {
    const std::size_t rows = dimension->getRows();
    const std::size_t cols = dimension->getRows();

    std::size_t curr = 0;
    unsigned short val[3];
    while (curr < rows * cols) {
        for (unsigned short pixelIndex= 0; pixelIndex < 3; ++pixelIndex) {
            *src >> val[pixelIndex];
        }
        pixels[curr / cols][curr % cols] = new PPMPixel(val, maxValue);
        ++curr;
    }
}