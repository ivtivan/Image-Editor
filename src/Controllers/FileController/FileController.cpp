#include "FileController.h"
#include "../CustomExceptions/CustomExceptions.h"
#include <fstream>

FileController::FileController() : isOpened(false), isSetFilePath(false) {
    ;
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
    if (isOpened || !fileExists(filePath)) {
        return false;
    }

    isOpened = true;
    isSetFilePath = true;
    this->filePath = filePath;

    return true;
}

const bool FileController::create() {
    if (isOpened == true) {
        return false;
    }

    isOpened = true;
    return true;
}

const bool FileController::write(const Image* image) const {
    return writeTo(image, filePath);
}

const bool FileController::writeTo(const Image* image, const std::string& filePath) const {
    //image->convertTo(determineDestinationFileType(filePath));
    try {
        std::ofstream file(filePath);
        file << *image;
    }
    catch (...) {
        return false;
    }
    return true;
}

const bool FileController::close() {
    if (isOpened == false) {
        return false;
    }

    isOpened = false;
    isSetFilePath = false;
    return true;
}

const bool FileController::save(const Image* image) {
    write(image);
    close();
}

const bool FileController::saveAs(const Image* image, const std::string& filePath) {
    write(image);
    close();
}

const fileType FileController::determineFileType(std::string fileExtension) const {
    if (fileExtension == "pbm") {
        return PBM;
    }
    else if (fileExtension == "pgm") {
        return PGM;
    }
    else if (fileExtension == "ppm") {
        return PPM;
    }

    throw FileException("FileType not supported.");
}

const std::string FileController::determineFileName(std::string filePath) const {
    std::size_t lastSlashIndex = filePath.find_last_of('/');
    std::size_t lastReversedSlashIndex = filePath.find_last_of('\\');

    if (lastSlashIndex == std::string::npos && lastReversedSlashIndex == std::string::npos) {
        return filePath;
    }

    if (lastSlashIndex == std::string::npos) {
        return filePath.substr(lastReversedSlashIndex + 1);
    }

    if (lastReversedSlashIndex == std::string::npos) {
        return filePath.substr(lastSlashIndex + 1);
    }

    if (lastReversedSlashIndex > lastSlashIndex) {
        return filePath.substr(lastReversedSlashIndex + 1);
    }

    return filePath.substr(lastSlashIndex + 1);
}

const fileType FileController::determineDestinationFileType(std::string filePath) const {
    std::string fileName = determineFileName(filePath);
    
    std::size_t extensionLength = 3;
    if (fileName.length() <= 1 + extensionLength) {
        throw FileException("File path not valid.");
    }

    if (fileName[fileName.length() - extensionLength - 1] != '.') {
        throw FileException("File path not valid.");
    }

    std::string fileExtension = fileName.substr(fileName.length() - extensionLength);

    return determineFileType(fileExtension);
}