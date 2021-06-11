#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

/** 
 * Singleton class.
 * Controlls opening, closing, creating and saving a file.
 */
class FileController {
    private:
        Image image; /**< Image to which the file data is copied */
        bool isLoaded; /**< Checks if a file is currently opened */
        std::string filePath; /**< Path of the last loaded file */
        bool setFilePath; /**< checks if a file path was set */

        /**
         * Checks if a file exists.
         */
        bool fileExists(std::string filePath);

        FileController();
    public:
        FileController(const FileController&) = delete;
        FileController& operator=(const FileController&) = delete;

        static FileController& instance();
        
        /**
         * Returns pointer to the image to which the file content is copied.
         */
        Image* getImage();

        /**
         * Creates an image from the given parameters.
         */
        void createFile(std::size_t rows, std::size_t cols, std::string color);

        /**
         * Copies file information in image.
         */
        void openFile(std::string filePath);

        /**
         * Closes file.
         * Does not automatically save the chages made.
         */
        void closeFile();

        /**
         * Replaces the content of the loaded file with the image.
         */
        void saveFile();

        /**
         * Does not delete the loaded file.
         * Saves changes to a newly created file with the given filePath.
         */
        void saveFileAs(std::string filePath);
};

#endif