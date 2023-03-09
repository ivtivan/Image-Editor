#ifndef IMAGE_CONTROLLER_H
#define IMAGE_CONTROLLER_H

#include "../Editor/Editor.h"
#include "../Dithers/Dither/Dither.h"
#include "../ImageFactory/ImageFactory.h"

class ImageController {
    private:
        Editor editor;
        ImageFactory imageFactory;
        Image* image;
    public:
        ImageController();

        const Image* getImage();

        const bool cropImage(std::size_t xUpLeft, std::size_t yUpLeft,
            std::size_t xDownRight, std::size_t yDownRight) const;
        const bool resizeImage(std::size_t destRows, std::size_t destCols) const;
        const bool ditherImage(std::string algorithmName) const;
};

#endif