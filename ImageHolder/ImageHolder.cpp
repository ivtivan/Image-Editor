#include "ImageHolder.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

bool ImageHolder::isLoaded = false;

void ImageHolder::determineFileType(std::string fileExtension) {
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

void ImageHolder::saveFileType(std::string filePath) {
    const std::size_t fileExtensionLength = 3;
    std::string fileExtension = substr(filePath.lenth() - 4, fileExtensionLength);
    this->type = determineFileType(fileExtension);
}

void ImageHolder::storeContent(std::string filePath) {
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
}

const bool ImageHolder::getIsLoaded() {
    return this->isLoaded;
}

const fileType getFileType() {
    return this->type;
}

std::string ImageHolder::getImageContent() {
    return this->imageContent;
}

void ImageHolder::storeImage(std::string filePath) {
    if (this->isLoaded == true) {
        throw FileException("An image is already loaded.");
    }

    determineFileType();
    storeContent();

    this->isLoaded = true;
}

void ImageHolder::clear() {
    if (this->isLoaded == false) {
        throw FileException("No image was loaded.");
    }
    this->isLoaded = false;
}