#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>

class FileHandler {
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