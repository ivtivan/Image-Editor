#include "ImageHolder.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

bool ImageHolder::isLoaded = false;

void ImageHolder::copyImagePixelsFrom(std::string filePath) {
    if (this->isLoaded == true) {
        throw FileException("An image is already loaded.");
    }
    std::ifstream file("test.txt");
    this->isLoaded = true;
}

void ImageHolder::clear() {
    if (this->isLoaded == false) {
        throw FileException("No image was loaded.");
    }
    this->isLoaded = false;
}