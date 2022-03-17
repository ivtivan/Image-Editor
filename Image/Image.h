#ifndef IMAGE_H
#define IMAGE_H

#include "../Pixel/Pixel.h"

class PBMImage;
class PGMImage;
class PPMImage;

/**
 * @brief Supports working with images.
 * 
 * Creates an image form parameters or loads one from a PBM/PGM/PPM file.
 */
class Image {
    private:
        Pixel** pixels;
        std::size_t cols;
        std::size_t rows;

        void colorPixels(std::string color);
        const bool isValidColor(std::string color) const;

        const bool isGrey() const;
        const bool isBlackAndWhite() const;

        void toPBMPixels();
        void toPGMPixels();
        void toPPMPixels();
    public:
        Image();
        Image(Pixel** pixels, std::size_t rows, std::size_t cols);
        Image(const Image& image);
        Image& operator=(const Image& image);

        const std::size_t getRows() const;
        const std::size_t getCols() const;
        Pixel** getPixels() const;

        // void setPixels(Pixel** pixels, std::size_t rows, std::size_t cols);
        void setPixels(std::string color, std::size_t rows, std::size_t cols);

        Image* operator*();
        ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

#endif