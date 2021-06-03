#ifndef PBM_EDITOR_H
#define PBM_EDITOR_H

#include "../../Image/Image.h"

class PBMEditor {
    private:
    public:
        // x1 <= x2, y1 <= y2
        void cropImage(Image* image, std::size_t x1 = 0, std::size_t y1 = 0, std::size_t x2 = 0, std::size_t y2 = 0);
        void scaleImage(Image* image);
        void ditherImage(Image* image);
};

#endif