#ifndef PGM_EDITOR_H
#define PGM_EDITOR_H

#include "../../Image/Image.h"

class PGMEditor {
    private:
    public:
        void cropImage(Image* image);
        void scaleImage(Image* image);
        void ditherImage(Image* image);
};

#endif