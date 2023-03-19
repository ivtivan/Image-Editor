#ifndef PBM_IMAGE_H
#define PBM_IMAGE_H

#include "../Image.h"

class PBMImage : public Image {
    public:
        PBMImage();
        PBMImage(Dimension dimension, Pixel*** pixels);

        const std::string getTypeID() const;

        ~PBMImage();

};

#endif