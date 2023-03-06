#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include "../Image.h"

class PGMImage : public Image {
    private:
    public:
        PGMImage(const std::ifstream& sourceFile);
        ~PGMImage();
};

#endif