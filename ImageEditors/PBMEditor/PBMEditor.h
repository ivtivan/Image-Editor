#ifndef PBM_EDITOR_H
#define PBM_EDITOR_H

#include "../../Image/Image.h"

class PBMEditor {
    private:
    public:
        void cropImage(Image* image);
        void scaleImage(Image* image);
        void ditherImage(Image* image);
};

#endif