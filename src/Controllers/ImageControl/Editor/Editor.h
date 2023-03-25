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
        Pixel*** allocatePixelMatrix(std::size_t rows, std::size_t cols) const;
    public:
        Editor();

        void setTargetImage(Image* targetImage);

        bool cropImage(const Point& upLeft, const Point& downRight) const;
        bool resizeImage(const Dimension& dst) const;
        bool ditherImage(std::string algorithmName) const;
};

#endif