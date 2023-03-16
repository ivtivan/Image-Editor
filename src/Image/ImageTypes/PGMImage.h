#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include "../Image.h"

class PGMImage : public Image {
    private:
        void allocatePixels();
    public:
        PGMImage();
        
        const std::string getTypeID() const;

        void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);
        
        ~PGMImage();
};

#endif