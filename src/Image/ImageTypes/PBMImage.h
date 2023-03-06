#ifndef PBM_IMAGE_H
#define PBM_IMAGE_H

#include "../Image.h"

class PBMImage : public Image {
    private:
    public:
        PBMImage(const std::ifstream& sourceFile);
        ~PBMImage();
};

#endif