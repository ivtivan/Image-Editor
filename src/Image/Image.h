#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "../Pixel/Pixel.h"

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
        unsigned int pixelMaxValue;
        std::size_t cols;
        std::size_t rows;

        virtual void allocatePixels();
    public:
        Image();

        virtual void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);
        Pixel** getPixels() const;
        const std::size_t getRows() const;
        const std::size_t getCols() const;

        virtual const std::string getTypeID() const;
        virtual ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image* image);
};

#endif