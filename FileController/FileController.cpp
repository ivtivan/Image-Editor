#include "FileController.h"
#include "../CustomExceptions/CustomExceptions.h"
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
    catch (const ImageException& e) {
        this->isLoaded = false;
        throw e;
    }

}

void FileController::closeFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot close file - no file loaded.");
    }

    this->isLoaded = false;
    this->setFilePath = false;
    this->image.reset();
}

void FileController::saveFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded.");
    }
    if (this->setFilePath == false) {
        throw FileException("Cannot save file - no file path is given.");
    }

    std::ofstream file(this->filePath);
    file << this->image;

    file.close();

    closeFile();
}

void FileController::saveFileAs(std::string filePath) {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded.");
    }

    fileType neededType = determineDestinationFileType(filePath);
    image.convertTo(neededType);
    
    this->filePath = filePath;
    this->setFilePath = true;

    saveFile();
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