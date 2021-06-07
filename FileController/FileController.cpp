#include "FileController.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

FileController::FileController() : isLoaded(false) {
    ;
}

FileController& FileController::instance() {
    static FileController fc;
    return fc;
}

Image* FileController::getImage() {
    return *(this->image);
}

bool FileController::fileExists(std::string fileAddress) {
    bool exists;
    std::ifstream testExists;
    testExists.open(fileAddress);
    
    // Checks if a file was opened.
    if (testExists) {
        exists = true;
    }
    else {
        exists = false;
    }
    
    testExists.close();
    return exists;
}

void FileController::createFile(std::size_t rows, std::size_t cols, std::string color) {
    if (this->isLoaded == true) {
        throw FileException("Cannot create - another file already loaded.");
    }

    this->image.setPixels(color, rows, cols);
}

void FileController::openFile(std::string fileAddress) {
    if (this->isLoaded == true) {
        throw FileException("Cannot open - another file already loaded");
    }

    std::ofstream file(fileAddress);
    this->isLoaded = true;
    this->filePath = fileAddress;

    try {
        this->image.storeImageFrom(this->filePath);
    }
    catch (const FileException& e) {
        this->isLoaded = false;
        throw e;
    }

    file.close();
}

void FileController::closeFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot close file - no file loaded");
    }

    this->isLoaded = false;
}

void FileController::saveFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded");
    }
    
    image.saveImageTo(this->filePath);

    closeFile();
}

void FileController::saveFileAs(std::string fileAddress) {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded");
    }
    
    rename(this->filePath.c_str(), fileAddress.c_str());
    this->filePath = fileAddress;

    saveFile();
}