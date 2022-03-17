#ifndef IMAGE_READER
#define IMAGE_READER

#include "Image.h"
#include "ImageHelpers.cpp"
#include <string>

class ImageReader {
    private:
        ImageParameters params;
    
        const fileType readFileType(std::ifstream& file);
        const unsigned short readNumber(std::ifstream& file);
        void readImageParametersFrom(std::ifstream& file);
        Pixel** getPixelMatrixFrom(std::ifstream& file);
    public:
        Image getImageFrom(std::string filePath);
};

#endif