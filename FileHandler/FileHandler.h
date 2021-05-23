#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>

class FileHandler {
    private:
        static bool isLoaded; // checks if a file is currently opened
        static std::string filePath; // stores the path of the last loaded file
    public:
        static void createFile(std::string fileName);
        static void openFile(std::string fileName);
        static void closeFile();

        static void saveFile();
        static void saveFileAs(std::string fileName);
};

#endif