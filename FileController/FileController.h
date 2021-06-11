#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

/** 
 * @brief Controlls opening, closing, creating and saving a file.
 * Singleton class.
 */
class FileController {
    private:
        /**
         * @brief Image to which the file data is copied
         * 
         */
        Image image;

        /**
         * @brief Checks if a file is currently opened 
         * 
         */
        bool isLoaded;

        /**
         * @brief Path of the last loaded file
         * 
         */
        std::string filePath;

        /**
         * @brief Checks if a file path was set
         * 
         */
        bool setFilePath;

        /**
         * @brief Checks if a file exists.
         * 
         */
        bool fileExists(std::string filePath);

        FileController();
    public:
        FileController(const FileController&) = delete;
        FileController& operator=(const FileController&) = delete;

        static FileController& instance();
        
        /**
         * @brief Returns pointer to the image to which the file content is copied.
         * 
         */
        Image* getImage();

        /**
         * @brief Creates an image from the given parameters.
         * 
         * Creating an image counts as loading/opening a file.
         */
        void createFile(std::size_t rows, std::size_t cols, std::string color);

        /**
         * @brief Copies information from file in an Image object.
         * 
         * Throws FileException if a file is already opened or the file does not exist.
         */
        void openFile(std::string filePath);

        /**
         * @brief Closes file.
         * 
         * Does not automatically save the chages made.
         * 
         * Throws FileException if no file is opened.
         */
        void closeFile();

        /**
         * @brief Replaces the content of the loaded file with the one in the image attribute.
         * 
         * Closes the file.
         * 
         * Throws FileException if no file is opened or the destination file papth is not given.
         */
        void saveFile();

        /**
         * @brief Saves the content in the image attribute in a new file.
         * 
         * Closes the file.
         * 
         * Does not delete the loaded file.
         * Saves changes to a newly created file with the given filePath.
         * 
         * Throws FileException if no file is opened.
         */
        void saveFileAs(std::string filePath);
};

#endif