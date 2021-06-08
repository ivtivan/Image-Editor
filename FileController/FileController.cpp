#include "FileController.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <fstream>

FileController::FileController() : isLoaded(false), setFilePath(false) {
    ;
}

FileController& FileController::instance() {
    static FileController fc;
    return fc;
}

Image* FileController::getImage() {
    return *(this->image);
}

bool FileController::fileExists(std::string filePath) {
    bool exists;
    std::ifstream testExists;
    testExists.open(filePath);
    
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
    isLoaded = true;
}

void FileController::openFile(std::string filePath) {
    if (this->isLoaded == true) {
        throw FileException("Cannot open - another file already loaded.");
    }

    if (fileExists(filePath) == false) {
        throw FileException("Cannot open - no such file was found.");
    }

    std::ofstream file(filePath);
    this->isLoaded = true;
    this->setFilePath = true;
    this->filePath = filePath;

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
        throw FileException("Cannot close file - no file loaded.");
    }

    this->isLoaded = false;
    this->setFilePath = false;
}

void FileController::saveFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded.");
    }
    if (this->setFilePath == false) {
        throw FileException("Cannot save file - no file path is given.");
    }

    image.saveImageTo(this->filePath);

    closeFile();
}

void FileController::saveFileAs(std::string filePath) {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded.");
    }
    
    this->filePath = filePath;
    this->setFilePath = true;

    saveFile();
}