#ifndef PPM_EDITOR_H
#define PPM_EDITOR_H

#include "../../Image/Image.h"

class PPMEditor {
    private:
    public:
        void cropImage(Image* image);
        void scaleImage(Image* image);
        void ditherImage(Image* image);
};

#endif