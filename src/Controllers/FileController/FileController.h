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

        bool fileExists(std::string filePath) const;

        bool write() const;
        bool writeTo(const std::string& filePath) const;

        bool canBeOpened(const std::string& filePath) const;
        bool canBeCreated(const std::string& filePath) const;
    public:
        FileController();

        void setTargetImage(Image* targetImage);
        bool save();
        bool saveAs(const std::string& filePath);
        bool open(const std::string& filePath);
        bool create(const std::string& filePath);
        bool close();
};

#endif