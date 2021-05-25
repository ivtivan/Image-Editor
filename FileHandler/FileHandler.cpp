#include "FileHandler.h"
#include "../CustomExceptions/FileException/FileException.h"
#include "../ImageHolder/ImageHolder.h"
#include <fstream>

bool FileHandler::isLoaded = false;

static bool FileHandler::fileExists(std::string fileAddress) {
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

static void FileHandler::createFile(std::string fileAddress) {
    if (this->isLoaded == true) {
        throw FileException("Cannot create - another file already loaded.");
    }

    if (fileExists(fileAddress)) {
        throw FileException("Cannot create - file with this name already exists.");
    }

    std::ofstream file(fileAddress);
    file.close();

    openFile(fileAddress);
}

static void FileHandler::openFile(std::string fileAddress) {
    if (this->isLoaded == true) {
        throw FileException("Cannot open - another file already loaded");
    }

    std::ofstream file(fileAddress);
    this->isLoaded = true;
    this->filePath = fileAddress;

    try {
        ImageHoder::copyImagePixelsFrom(this->filePath);
    }
    catch (const FileException& e) {
        this->isLoaded = false;
        throw e;
    }

    file.close();
}

static void FileHandler::closeFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot close file - no file loaded");
    }
    
    ImageHoder::clear();

    this->isLoaded = false;
}

static void FileHandler::saveFile() {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded");
    }
    
    ImageHolder::saveChangesTo(this->filePath);

    closeFile();
}

static void FileHandler::saveFileAs(std::string fileAddress) {
    if (this->isLoaded == false) {
        throw FileException("Cannot save file - no file loaded");
    }
    
    rename(this->filePath, fileAddress);
    this->filePath = fileAddress;

    saveFile();
}