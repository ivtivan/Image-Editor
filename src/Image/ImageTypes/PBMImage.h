#ifndef PBM_IMAGE_H
#define PBM_IMAGE_H

#include "../Image.h"

class PBMImage : public Image {
    public:
        PBMImage();
        PBMImage(Dimension dimension, pixel_ptr_vector&& pixels);

        const std::string getTypeID() const override;

        ~PBMImage();

};

#endif