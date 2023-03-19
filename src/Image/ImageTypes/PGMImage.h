#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include "../Image.h"

class PGMImage : public Image {
    public:
        PGMImage();
        PGMImage(Dimension dimension, Pixel*** pixels);

        const std::string getTypeID() const;
        
        ~PGMImage();
};

#endif