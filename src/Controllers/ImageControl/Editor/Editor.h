#ifndef EDITOR_H
#define EDITOR_H

#include "../../../Image/Image.h"
/**
 * @brief Allows cropping, resizing and dithering an image.
 * 
 * Singleton class.
 */
class Editor {
    private:
        Image* targetImage;
        Pixel** allocatePixelMatrix(std::size_t rows, std::size_t cols) const;
    public:
        Editor();

        void setTargetImage(Image* targetImage);

        const bool cropImage(std::size_t xUpLeft, std::size_t yUpLeft,
            std::size_t xDownRight, std::size_t yDownRight) const;
        const bool resizeImage(std::size_t destRows, std::size_t destCols) const;
        const bool ditherImage(std::string algorithmName) const;
};

#endif