#ifndef EDITOR_H
#define EDITOR_H

#include "../Image/Image.h"
/**
 * @brief Allows cropping, resizing and dithering an image.
 * 
 * Singleton class.
 */
class Editor {
    private:
        Pixel** allocatePixelMatrix(std::size_t rows, std::size_t cols) const;
    public:
        Editor();

        const bool cropImage(Image* image, std::size_t xUpLeft, std::size_t yUpLeft,
            std::size_t xDownRight, std::size_t yDownRight) const;
        const bool resizeImage(Image* image, std::size_t destRows, std::size_t destCols) const;
        const bool ditherImage(Image* image, std::string algorithmName) const;
};

#endif