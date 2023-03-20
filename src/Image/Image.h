#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "../Pixel/Pixel.h"
#include "ImageHelpers/Dimension/Dimension.h"
#include "ImageHelpers/Point/Point.h"

/**
 * @brief Supports working with images.
 * 
 * Creates an image form parameters or loads one from a PBM/PGM/PPM file.
 */
class Image {
    private:
        Dimension dimension;
        Pixel*** pixels; // not an efficient way of doing this
        void freePixels();
    protected:
        void setPixels(Pixel*** pixels);
    public:
        Image();
        Image(Dimension dimension, Pixel*** pixels);


        virtual void updatePixels(Pixel*** srcPixels, const Dimension srcDimension);
        Pixel* getPixelAt(const Point& point) const;
        std::size_t getRows() const;
        std::size_t getCols() const;

        virtual const std::string getTypeID() const;
        virtual ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image* image);
};

#endif