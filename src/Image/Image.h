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
    private:
        std::size_t rows;
        std::size_t cols;
        Pixel*** pixels; // not an efficient way of doing this

    protected:
        unsigned int pixelMaxValue;

        virtual void allocatePixels();

        void setPixels(Pixel*** pixels);
    public:
        Image();
        Image(std::size_t rows, std::size_t cols, Pixel*** pixels);


        virtual void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);
        Pixel* const getPixelAt(std::size_t row, std::size_t col) const;
        const std::size_t getRows() const;
        const std::size_t getCols() const;

        virtual const std::string getTypeID() const;
        virtual ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image* image);
};

#endif