#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "../../../Image/Image.h"
#include "../../../Image/ImageTypes/PBMImage.h"
#include "../../../Image/ImageTypes/PGMImage.h"
#include "../../../Image/ImageTypes/PPMImage.h"

class ImageFactory {
    private:
    public:
        ImageFactory();


        PBMImage* getPBMFromIstream(std::istream src) const;
        PGMImage* getPGMFromIstream(std::istream src) const;
        PPMImage* getPPMFromIstream(std::istream src) const;
        PPMImage* getPPMFromSizeColor(std::size_t rows, std::size_t cols, std::string hexColor) const;
};

#endif