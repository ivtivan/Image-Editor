#include "ImageReader.h"
#include "PixelTypes.h"
#include "../CustomExceptions/CustomExceptions.h"
#include <fstream>

Image ImageReader::getImageFrom(std::string filePath) {
    std::ifstream file(filePath);
    if(!file) {
        throw FileException("Could not open file.");
    }

    this->params.type = readFileType(file);    

    if (this->params.type == ERROR) {
        throw FileException("File type not valid.");
    }

    readImageParametersFrom(file);
    Pixel** pixels = getPixelMatrixFrom(file);

    file.close();\

    return Image(pixels, this->params.rows, this->params.cols);
}

const fileType ImageReader::readFileType(std::ifstream& file) {
    std::string type;
    while (file >> type) {
        if (type[0] != '#') {
            return getTypeFrom(type);
        }
    }

    throw ImageException("Reading file type failed.");
}

const unsigned short ImageReader::readNumber(std::ifstream& file) {
    std::string param;
    while (file >> param) {
        if (param[0] != '#') {
            return stoi(param);
        }
        else {
            std::getline(file, param);
        }
    }

    throw ImageException("Reading image characteristics failed.");
}

void ImageReader::readImageParametersFrom(std::ifstream& file) {
    this->params.cols = readNumber(file);
    this->params.rows = readNumber(file);

    if (this->params.type != PBM) {
        this->params.pixelMaxValue = readNumber(file);
    }
    else {
        this->params.pixelMaxValue = 1;
    }
}

Pixel** ImageReader::getPixelMatrixFrom(std::ifstream& file) {
    Pixel** pixels = new Pixel*[this->params.rows];
    for (size_t i = 0; i < this->params.rows; ++i) {
        pixels[i] = new Pixel[this->params.cols];
    }

    for (size_t i = 0; i < this->params.rows * this->params.cols; ++i) {
        switch(this->params.type) {
            case PBM: pixels[i / this->params.rows][i % this->params.cols] = PBMPixel(readNumber(file)); break;
            case PGM: break;
            case PPM: break;
        }
    }

    return pixels;
}