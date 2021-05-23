#include "FileHandler.h"
#include "../CustomExceptions/FileException/FileException.h"

bool FileHandler::isLoaded = false;

static void FileHandler::createFile(std::string fileName) {
    if (isLoaded == true) {
        throw FileException("A file is already opened. Cannot opena new one.");
    }

    // TODO: Checks if such file exists

    filePath = fileName;

    closeFile();
}

static void FileHandler::openFile(std::string fileName) {
    if (isLoaded == true) {
        throw FileException("Cannot open - another file already loaded");
    }

    filePath = fileName;

    closeFile();
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

static void FileHandler::saveFileAs(std::string fileName) {
    if (isLoaded == false) {
        throw FileException("Cannot close - no file loaded");
    }

    filePath = fileName;
    saveFile();
}