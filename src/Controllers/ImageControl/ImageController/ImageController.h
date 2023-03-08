#ifndef IMAGE_CONTROLLER_H
#define IMAGE_CONTROLLER_H

#include "../Editor/Editor.h"
#include "../Dithers/Dither/Dither.h"
#include "../ImageFactory/ImageFactory.h"

class ImageController {
    private:
        Dither dither;
        Editor editor;
        ImageFactory image_factory;
    public:
        ImageController();

        

};

#endif