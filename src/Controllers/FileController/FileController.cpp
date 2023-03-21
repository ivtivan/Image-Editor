#include "FileController.h"
#include <fstream>

FileController::FileController() {
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

bool FileController::save() const{
    return write() && close();
}

bool FileController::saveAs(const std::string& filePath) {
    
    return writeTo(filePath) && close();
}

bool FileController::write() const {
    return writeTo(filePath);
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

bool FileController::close() const {
    delete srcImage;
    return true;
}