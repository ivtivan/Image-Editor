#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include "../Image.h"

class PGMImage : public Image {
    public:
        PGMImage();
        PGMImage(Dimension dimension, pixel_ptr_vector&& pixels);

        const std::string getTypeID() const override;
        
        ~PGMImage();
};

#endif