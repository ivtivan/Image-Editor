#include "Image.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

Image::Image() {
    ;
}

Image::Image(const Image& image) : imageContent(image.imageContent),
    type(image.type) {
    ;
}

Image& Image::operator=(const Image& image) {
    if (this == &other) {
        return this;
    }

    this->imageContent = other.imageContent;
    this->type = other.type;
}

void Image::determineFileType(std::string fileExtension) {
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

void Image::saveFileType(std::string filePath) {
    const std::size_t fileExtensionLength = 3;
    std::string fileExtension = substr(filePath.lenth() - 4, fileExtensionLength);
    this->type = determineFileType(fileExtension);
}

void Image::storeContent(std::string filePath) {
    std::ifstream file(filePath);

    if (!file) {
        throw FileException("Could not open file.");
    }

    file.seekg (0, file.end);
    std::size_t length = file.tellg();
    file.seekg (0, file.beg);

    char* fileContent = new char [length];
    file.read(fileContent, length);
    file.close();

    this->imageContent.assign(fileContent);

    delete[] fileContent;
}

const fileType getFileType() const {
    return this->type;
}

const std::string Image::getImageContent() const {
    return this->imageContent;
}

void Image::storeImageFrom(std::string filePath) {
    determineFileType();
    storeContent();
}

void Image::saveChangesTo(std::string filePath) const {
    std::ofstream file(filePath);
    file << imageContent << std::endl;

    file.close();
}

Image* Image::operator*() {
    return this;
}