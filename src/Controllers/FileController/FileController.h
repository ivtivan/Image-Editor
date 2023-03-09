#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "../Image/Image.h"

#include <string>

/** 
 * Controls opening, closing, creating and saving a file.
 */
class FileController {
    private:
        bool isOpened;
        std::string filePath;
        bool isSetFilePath;

        const bool fileExists(std::string filePath) const;

        const std::string determineFileName(std::string filePath) const;
        const fileType determineFileType(std::string fileExtension) const;
        const bool FileController::write(const Image* image) const;
        const bool FileController::writeTo(const Image* image, const std::string& filePath) const;

        const fileType determineDestinationFileType(std::string filePath) const;
    public:
        FileController();

        const bool save(const Image* image);
        const bool saveAs(const Image* image, const std::string& filePath);
        const bool open(const std::string& filePath);
        const bool create();
        const bool close();
};

#endif