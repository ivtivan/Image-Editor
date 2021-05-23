#include "FileHandler.h"
#include "../CustomExceptions/FileException/FileException.h"
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
    if (isLoaded == true) {
        throw FileException("Cannot create - another file already loaded.");
    }

    if (fileExists(fileAddress)) {
        throw FileException("Cannot create - file with this name already exists.");
    }

    // File will be created 
    openFile(fileAddress);
}

static void FileHandler::openFile(std::string fileAddress) {
    if (isLoaded == true) {
        throw FileException("Cannot open - another file already loaded");
    }

    std::ofstream file(fileAddress);
    isLoaded = true;
    filePath = fileAddress;

    // TODO: Copy file content to temporary file.

    file.close();
}

static void FileHandler::closeFile() {
    if (isLoaded == false) {
        throw FileException("Cannot close - no file loaded");
    }
    // TODO: Copy temporary file content and the close file
}

static void FileHandler::saveFile() {
    if (isLoaded == false) {
        throw FileException("Cannot close - no file loaded");
    }
    closeFile();
}

static void FileHandler::saveFileAs(std::string fileAddress) {
    if (isLoaded == false) {
        throw FileException("Cannot close - no file loaded");
    }

    filePath = fileAddress;
    saveFile();
}