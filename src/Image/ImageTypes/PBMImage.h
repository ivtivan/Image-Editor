#ifndef PBM_IMAGE_H
#define PBM_IMAGE_H

#include "../Image.h"

class PBMImage : public Image {
    private:
        void allocatePixels();
    public:
        PBMImage();
        PBMImage(std::size_t rows, std::size_t cols, Pixel*** pixels);

        const std::string getTypeID() const;

        void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);
        ~PBMImage();

};

#endif