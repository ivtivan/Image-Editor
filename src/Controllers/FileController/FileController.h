#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include <string>
#include "../ImageControl/ImageFactory/ImageFactory.h"

/** 
 * Controls opening, closing, creating and saving a file.
 */
class FileController {
    private:
        std::string filePath;
        Image* srcImage;

        bool write() const;
        bool writeTo(const std::string& filePath) const;
        bool isSetFilePath() const;
    public:
        FileController();

        void setSrcImage(Image* srcImage);
        bool save();
        bool saveAs(const std::string& filePath);
        bool close();
        std::ifstream open(const std::string& filePath);
};

#endif