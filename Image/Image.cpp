#include "Image.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>
#include <iostream>

Image::Image() {
    ;
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
    for (std::size_t i = 0; i < this->rows; ++i) {
        delete[] this->pixels[i];
    }
    delete[] this->pixels;

    this->pixels = pixels;

    this->rows = rows;
    this->cols = cols;
}

void Image::colorPixels(std::string color) {
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            pixels[i][j].setValue(color);
        }
    }
}

void Image::setPixels(std::string color, std::size_t rows, std::size_t cols) {
    this->rows = rows;
    this->cols = cols;
    this->type = PPM;
    allocatePixelArray();
    colorPixels(color);
}

const fileType Image::determineFileType(std::string fileExtension) {
    if (fileExtension == "pbm") {
        return PBM;
    }
    else if (fileExtension == "pgm") {
        return PGM;
    }
    else if (fileExtension == "ppm") {
        return PPM;
    }

    throw FileException("File type not valid.");
}

void Image::storeFileType(std::string filePath) {
    const std::size_t fileExtensionLength = 3;
    std::string fileExtension = filePath.substr(filePath.length() - 3, fileExtensionLength);
    this->type = determineFileType(fileExtension);
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
        if (this->content[i] == ' ' || this->content[i] == '\n' && isSpaced == false) {
            value = this->content.substr(begin, i - begin);
            this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(atoi(value.c_str()));
            countSetPixels++;
        }
        else if (this->content[i] != ' ' && this->content[i] != '\n' && isSpaced == true) {
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

    for (std::size_t i = 0 ; i < this->content.length(); ++i) {
        if (this->content[i] == ' ' || this->content[i] == '\n' && isSpaced == false) {
            value = this->content.substr(begin, i - begin);
            pixelValue[valueCount] = atoi(value.c_str());
            valueCount = (valueCount + 1) % MAX_VALUES_COUNT;
            if(valueCount == 0) {
                this->pixels[countSetPixels / this->cols][countSetPixels % this->cols].setValue(pixelValue);
                countSetPixels++;
            }
        }
        else if (this->content[i] != ' ' && this->content[i] != '\n' && isSpaced == true) {
            isSpaced = false;
            begin = i;
        }
    }

    if (this->content[this->content.length() - 1] != ' ' && this->content[this->content.length() - 1] != '\n') {
        value = this->content.substr(begin, this->content.length() - begin);
        pixelValue[valueCount] = atoi(value.c_str());
        valueCount = (valueCount + 1) % MAX_VALUES_COUNT;
        if(valueCount == 0) {
            this->pixels[countSetPixels / this->rows][countSetPixels % this->cols].setValue(pixelValue);
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

void Image::storeContent(std::string filePath) {
    std::string readWord;
    std::string readLine;
    std::string comment;
    int pos;
    bool isReadType = false;
    bool isSetCols = false;
    bool isSetRows = false;
    bool isSetMaxValue = false;

    std::ifstream file(filePath);
    if (!file) {
        throw FileException("Could not open file.");
    }

    while (isReadType == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#' && readWord[0] != ' ') {
            isReadType = true;
        }
        else if (readWord[0] == '#') {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    while (isSetCols == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#' && readWord[0] != ' ') {
            isSetCols = true;
            this->cols = atoi(readWord.c_str());
        }

        else if (readWord[0] == '#') {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    while (isSetRows == false) {
        pos = file.tellg();
        file >> readWord;
        if (readWord[0] != '#' && readWord[0] != ' ') {
            isSetRows = true;
            this->rows = atoi(readWord.c_str());
        }

        else if (readWord[0] == '#') {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    if (this->type != PBM) {
        while (isSetMaxValue == false) {
            pos = file.tellg();
            file >> readWord;

            if (readWord[0] != '#' && readWord[0] != ' ') {
                isSetMaxValue = true;
                this->pixelMaxValue = atoi(readWord.c_str());
            }

            else if (readWord[0] == '#') {
                file.seekg(pos);
                getline(file, comment);
            }
        }
    }


    while(getline(file, readLine)) {
        removeCommentsFrom(readLine);
        this->content += readLine;
    }

    file.close();

    allocatePixelArray();
    fillPixelArray();
}

void Image::storeImageFrom(std::string filePath) {
    storeFileType(filePath);
    storeContent(filePath);
}

const fileType Image::getFileType() const {
    return this->type;
}

const std::string Image::getContent() const {
    return this->content;
}

Image* Image::operator*() {
    return this;
}

Image::~Image() {
    for (std::size_t i = 0; i < this->cols; ++i) {
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