#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

class FileController {
    private:
        Image image; // image to which the file data is copied
        bool isLoaded; // checks if a file is currently opened
        std::string filePath; // stores the path of the last loaded file

        bool fileExists(std::string fileAddress);

        FileController();
    public:
        FileController(const FileController&) = delete;
        FileController& operator=(const FileController&) = delete;

        static FileController& instance();
        Image* getImage(); // gets image to which the data is copied

        void createFile(std::size_t rows, std::size_t cols, std::string color);
        void openFile(std::string fileAddress);
        void closeFile();

        void saveFile();
        void saveFileAs(std::string fileAddress);
};

#endif