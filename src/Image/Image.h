#ifndef IMAGE_H
#define IMAGE_H

#include "../Pixel/Pixel.h"
#include <string>

enum fileType {
    PBM,
    PGM,
    PPM
};

/**
 * @brief Supports working with images.
 * 
 * Creates an image form parameters or loads one from a PBM/PGM/PPM file.
 */
class Image {
    protected:
        Pixel** pixels;
        fileType type;
        unsigned int pixelMaxValue;

        std::size_t cols;
        std::size_t rows;

        void removeCommentsFrom(std::string& line);
        virtual void allocatePixels();
        const std::size_t readParameter(std::ifstream& file);
        const std::string readPixels(std::ifstream& file);
        void fillPixelArray();
    public:
        Image();
        Image(const std::ifstream& sourceFile);
        
        virtual ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

#endif