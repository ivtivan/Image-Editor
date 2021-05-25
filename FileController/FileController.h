#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include <string>

class FileController {
    private:
        static bool isLoaded; // checks if a file is currently opened
        static std::string filePath; // stores the path of the last loaded file

        static bool fileExists(std::string fileAddress);
    public:
        static void createFile(std::string fileAddress);
        static void openFile(std::string fileAddress);
        static void closeFile();

        static void saveFile();
        static void saveFileAs(std::string fileAddress);
};

#endif