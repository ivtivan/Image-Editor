#include "FileController.h"
#include <fstream>

FileController::FileController() : filePath(""),
    srcImage(nullptr) {
    ;
}

void FileController::setSrcImage(Image* srcImage) {
    this->srcImage = srcImage;
}

std::ifstream FileController::open(const std::string& filePath) {
    this->filePath = filePath;
    std::ifstream readFrom;
    readFrom.open(filePath);
    return readFrom;
}

bool FileController::save() {
    if (isSetFilePath()) {
        return write();
    }

    close();
    return false;
}

bool FileController::close() {
    if (srcImage) {
        delete srcImage;
        srcImage = nullptr;
    }
    return true;
}

bool FileController::isSetFilePath() const {
    return filePath != "";
}

bool FileController::saveAs(const std::string& filePath) {
    
    return writeTo(filePath) && close();
}

bool FileController::write() const {
    if (isSetFilePath()) {
        return writeTo(filePath);
    }

    return false;
}

bool FileController::writeTo(const std::string& filePath) const {
    try {
        std::ofstream file(filePath);
        file << srcImage;
        file.close();
    }
    catch (...) {
        return false;
    }
    return true;
}