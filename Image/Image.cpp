#include "Image.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

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
    std::string fileExtension = filePath.substr(filePath.length() - 4, fileExtensionLength);
    this->type = determineFileType(fileExtension);
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

    std::ifstream file(filePath);
    if (!file) {
        throw FileException("Could not open file.");
    }

    while (isReadType == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#') {
            isSetRows = true;
        }

        else {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    while (isSetCols == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#') {
            isSetCols = true;
            this->cols = atoi(readWord.c_str());
        }

        else {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    while (isSetRows == false) {
        pos = file.tellg();
        file >> readWord;

        if (readWord[0] != '#') {
            isSetRows = true;
            this->rows = atoi(readWord.c_str());
        }

        else {
            file.seekg(pos);
            getline(file, comment);
        }
    }

    while(getline(file, readLine)) {
        removeCommentsFrom(readLine);
        this->content += readLine;
    }

    file.close();
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

void Image::saveImageTo(std::string filePath) const {
    std::ofstream file(filePath);
    file << content << std::endl;

    file.close();
}

Image* Image::operator*() {
    return this;
}