#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include <string>
#include "../ImageControl/ImageFactory/ImageFactory.h"

/** 
 * Controls opening, closing, creating and saving a file.
 */
class FileController {
    private:
        bool isOpened;
        bool isSetFilePath;

        std::string filePath;
        Image* targetImage;

        const bool fileExists(std::string filePath) const;

        const bool write() const;
        const bool writeTo(const std::string& filePath) const;

        const bool canBeOpened(const std::string& filePath) const;
        const bool canBeCreated(const std::string& filePath) const;
    public:
        FileController();

        void setTargetImage(Image* targetImage);
        const bool save();
        const bool saveAs(const std::string& filePath);
        const bool open(const std::string& filePath);
        const bool create(const std::string& filePath);
        const bool close();
};

#endif