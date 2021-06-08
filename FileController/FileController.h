#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

class FileController {
    private:
        Image image; // image to which the file data is copied
        bool isLoaded; // checks if a file is currently opened
        std::string filePath; // stores the path of the last loaded file
        bool setFilePath; // checks if a file path was set

        bool fileExists(std::string filePath);

        FileController();
    public:
        FileController(const FileController&) = delete;
        FileController& operator=(const FileController&) = delete;

        static FileController& instance();
        Image* getImage(); // gets image to which the data is copied

        void createFile(std::size_t rows, std::size_t cols, std::string color);
        void openFile(std::string filePath);
        void closeFile();

        // closes file after being saved
        void saveFile();

        // does not rename the file from which the image was loaded
        // creates a new file with the given path
        void saveFileAs(std::string filePath);
};

#endif