#ifndef IMAGE_H
#define IMAGE_H

#include <memory>
#include <string>
#include <vector>
#include "../Pixel/Pixel.h"
#include "ImageHelpers/Dimension/Dimension.h"
#include "ImageHelpers/Point/Point.h"

using pixel_ptr_vector = std::vector<std::shared_ptr<Pixel>>;

/**
 * @brief Supports working with images.
 * 
 * Creates an image form parameters or loads one from a PBM/PGM/PPM file.
 */
class Image {
    private:
        Dimension dimension;
        pixel_ptr_vector pixels; // not an efficient way of doing this
        void freePixels();
    protected:
        void setPixels(pixel_ptr_vector&& pixels);
    public:
        Image();
        Image(Dimension dimension, pixel_ptr_vector&& pixels);


        void movePixelsFromWith(pixel_ptr_vector&& src, const Dimension& srcDimension);
        std::shared_ptr<Pixel>& getPixelAt(const Point& point);
        std::size_t getRows() const;
        std::size_t getCols() const;

        virtual const std::string getTypeID() const;
        virtual ~Image();

        friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Image> image);
        friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Image> image);
};

#endif