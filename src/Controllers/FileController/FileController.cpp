#include "FileController.h"
#include <fstream>

FileController::FileController() : isOpened(false), isSetFilePath(false) {
    ;
}

void FileController::setTargetImage(Image* targetImage) {
    this->targetImage = targetImage;
}

const bool FileController::fileExists(std::string filePath) const {
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


const bool FileController::open(const std::string& filePath) {
    if (canBeOpened(filePath)) {
        isOpened = true;
        isSetFilePath = true;
        this->filePath = filePath;

        return true;
    }

    return false;
}

const bool FileController::canBeOpened(const std::string& filePath) const {
     return !isOpened && fileExists(filePath);
}


const bool FileController::create(const std::string& filePath) {
    if (canBeCreated(filePath)) {
        isOpened = true;
        // TODO create and open
        return true;
    }
    return false;
}

const bool FileController::canBeCreated(const std::string& filePath) const {
    return !isOpened && !fileExists(filePath);
}


const bool FileController::save() {
    write();
    close();
    return true;
}

const bool FileController::saveAs(const std::string& filePath) {
    writeTo(filePath);
    close();
    return true;
}

const bool FileController::write() const {
    return writeTo(filePath);
}

const bool FileController::writeTo(const std::string& filePath) const {
    try {
        std::ofstream file(filePath);
        file << targetImage;
    }
    catch (...) {
        return false;
    }
    return true;
}

const bool FileController::close() {
    if (!isOpened) {
        return false;
    }

    isOpened = false;
    isSetFilePath = false;
    return true;
}