#include "Image.h"
#include "../CustomExceptions/ImageException/ImageException.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

Image::Image() : cols(0), rows(0) {
    this->pixels = nullptr;
}

Image::Image(const Image& image) : content(image.content),
    type(image.type) {
    ;
}

Image& Image::operator=(const Image& image) {
    if (this == &image) {
        return *this;
    }

    this->content = image.content;
    this->type = image.type;

    return *this;
}

const fileType Image::getFileType() const {
    return this->type;
}

const std::size_t Image::getRows() const {
    return this->rows;
}

const std::size_t Image::getCols() const {
    return this->cols;
}

Pixel** Image::getPixels() {
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
    this->type = PPM;
    allocatePixelArray();
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
            pixels[i][j].setMaxValue(this->pixelMaxValue);
        }
    }
}

const fileType Image::determineFileType(std::string identifier) {
    if (identifier == "P1") {
        return PBM;
    }
    else if (identifier == "P2") {
        return PGM;
    }
    else if (identifier == "P3") {
        return PPM;
    }

    throw ImageException("Image type not valid.");
}

void Image::allocatePixelArray() {
    this->pixels = new Pixel*[this->rows];
    for(std::size_t i = 0; i < this->rows; ++i) {
        try {
            this->pixels[i] = new Pixel[this->cols];
        }
        catch (const std::bad_alloc&) {
            for(std::size_t j = 0; j < i; ++j) {
                delete[] this->pixels[j];
            }
            delete[] this->pixels;
        }
    }
}

void Image::fillPBM() {
    unsigned int countSetPixels = 0;
    for(std::size_t i = 0 ; i < this->content.length(); ++i) {
        if (this->content[i] != ' ') {
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(this->content[i] - '0');
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setMaxValue(this->pixelMaxValue);
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
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setMaxValue(this->pixelMaxValue);
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
        this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setMaxValue(this->pixelMaxValue);
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
                this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setMaxValue(this->pixelMaxValue);
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
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setMaxValue(this->pixelMaxValue);
            countSetPixels++;
        }
    }
}

void Image::fillPixelArray() {
    switch(this->type) {
        case PBM: fillPBM(); break;
        case PGM: fillPGM(); break;
        case PPM: fillPPM(); break;
    }
}

void Image::removeCommentsFrom(std::string& line) {
    for (std::size_t i  = 0; i < line.length(); ++i) {
        if (line[i] == '#') {
            line = line.substr(0, i);
            break;
        }
    }
}

const fileType Image::readFileType(std::ifstream& file) {
    bool isRead = false;
    std::size_t pos;
    std::string readWord;

    while (isRead == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#' && readWord[0] != ' ') {
            isRead = true;
            return determineFileType(readWord);
        }
        else if (readWord[0] == '#') {
            file.seekg(pos);
            getline(file, readWord);
        }
    }

    throw ImageException("Could not read fileType.");
}

const std::size_t Image::readParameter(std::ifstream& file) {
    bool isRead = false;
    std::size_t pos;
    std::string readWord;

    while (isRead == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#' && readWord[0] != ' ') {
            isRead = true;
            return atoi(readWord.c_str());
        }

        else if (readWord[0] == '#') {
            file.seekg(pos);
            getline(file, readWord);
        }
    }

    throw ImageException("Could not read parameter.");
}

const std::string Image::readPixels(std::ifstream& file) {
    std::string pixels;
    std::string readLine;

    while(getline(file, readLine)) {
        removeCommentsFrom(readLine);
        pixels += readLine;
    }

    return pixels;
}

void Image::storeImageFrom(std::string filePath) {
    std::string readLine;
    std::size_t pos = 0;

    std::ifstream file(filePath);
    if(!file) {
        throw FileException("Could not open file.");
    }

    this->type = readFileType(file);    

    this->cols = readParameter(file);
    this->rows = readParameter(file);

    if (this->type != PBM) {
        this->pixelMaxValue = readParameter(file);
    }
    else {
        this->pixelMaxValue = 1;
    }

    this->content = readPixels(file);

    file.close();

    allocatePixelArray();
    fillPixelArray();
}

const bool Image::isGrey() const {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (this->pixels[i][j].isGrey() == false) {
                return false;
            }
        }
    }

    return true;
}

const bool Image::isBlackAndWhite() const {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (this->pixels[i][j].isBlackOrWhite() == false) {
                return false;
            }
        }
    }

    return true;
}

void Image::convertToPBM() {
    if (isBlackAndWhite() == false) {
        throw FileException("Cannot convert file to PBM.");
    }

    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            this->pixels[i][j].swapBlackAndWhite();
            this->pixels[i][j].setBlackOrWhite();
        }
    }
    
    this->type = PBM;
    this->pixelMaxValue = 1;
}

void Image::convertToPGM() {
    if (isGrey() == false) {
        throw FileException("Cannot convert file to PGM.");
    }

    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (this->type == PBM) {
                this->pixels[i][j].swapBlackAndWhite();
            }

            this->pixels[i][j].setRGB(false);
        }
    }

    this->type = PGM;
    this->pixelMaxValue = this->pixels[0][0].getMaxValue();
}

void Image::convertToPPM() {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            if (this->type == PBM) {
                this->pixels[i][j].swapBlackAndWhite();
            }
            
            this->pixels[i][j].setRGB(true);
        }
    }

    this->type = PPM;
    this->pixelMaxValue = this->pixels[0][0].getMaxValue();
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