#include "ImageFactory.h"
#include <fstream>
#include <string>

ImageFactory::ImageFactory() : dimension(0, 0) {
    ;
}

std::shared_ptr<PPMImage> ImageFactory::getPPMFromSizeColor(const Dimension& dimension,
    const std::string& hexColor) {
    this->dimension = dimension;
    fillPPMPixelMatrixColor(hexColor);
    return std::make_shared<PPMImage>(dimension, std::move(pixels));
}

void ImageFactory::fillPPMPixelMatrixColor(const std::string& hexColor) {
    for (std::size_t row = 0; row < dimension.getRows(); ++row) {
        for (std::size_t col = 0; col < dimension.getCols(); ++col) {
            pixels.push_back(std::make_shared<PPMPixel>(hexColor));
        }
    }
}

std::shared_ptr<Image> ImageFactory::loadImageFrom(std::ifstream& src) {
    this->src = &src;
    
    std::string type = readImageTypeIdentificator();
    dimension = readDimension();

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

Dimension ImageFactory::readDimension() {
    size_t rows, cols;
    *src >> cols >> rows;
    return Dimension(rows, cols);
}

std::shared_ptr<PBMImage> ImageFactory::loadPBMImageFrom() {
    readIntoPBMPixelMatrix();
    return std::make_shared<PBMImage>(dimension, std::move(pixels));
}

void ImageFactory::readIntoPBMPixelMatrix() {
    const std::size_t rows = dimension.getRows();
    const std::size_t cols = dimension.getCols();

    unsigned short val;
    for (std::size_t i =0; i < rows * cols; ++i) {
        *src >> val;
        pixels.push_back(std::make_shared<PBMPixel>(val));
    }
}

std::shared_ptr<PGMImage> ImageFactory::loadPGMImageFrom() {
    saveMaxValue();
    readIntoPGMPixelMatrix();
    return std::make_shared<PGMImage>(dimension, std::move(pixels));
}

void ImageFactory::readIntoPGMPixelMatrix() {
    const std::size_t rows = dimension.getRows();
    const std::size_t cols = dimension.getCols();

    unsigned short val;
    for (std::size_t i =0; i < rows * cols; ++i) {
        *src >> val;
        pixels.push_back(std::make_shared<PGMPixel>(val, maxValue));
    }
}

void ImageFactory::saveMaxValue() {
    *src >> maxValue;
}

std::shared_ptr<PPMImage> ImageFactory::loadPPMImageFrom() {
    saveMaxValue();
    readIntoPPMPixelMatrix();
    return std::make_shared<PPMImage>(dimension, std::move(pixels));
}


void ImageFactory::readIntoPPMPixelMatrix() {
    const std::size_t rows = dimension.getRows();
    const std::size_t cols = dimension.getCols();

    unsigned short val[3];
    for (std::size_t i =0; i < rows * cols; ++i) {
        for (unsigned short pixelIndex= 0; pixelIndex < 3; ++pixelIndex) {
            *src >> val[pixelIndex];
        }
        pixels.push_back(std::make_shared<PPMPixel>(val, maxValue));
    }
}