#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

class FileController {
    private:
        static Image image; // image to which the file data is copied
        static bool isLoaded; // checks if a file is currently opened
        static std::string filePath; // stores the path of the last loaded file

        static bool fileExists(std::string fileAddress);
    public:
        static Image* getImage(); // gets image to which the data is copied

        static void createFile(std::string fileAddress);
        static void openFile(std::string fileAddress);
        static void closeFile();

        static void saveFile();
        static void saveFileAs(std::string fileAddress);
};

#endif