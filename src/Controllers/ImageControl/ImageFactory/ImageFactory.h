#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "../../../Image/Image.h"
#include "../../../Image/ImageTypes/PBMImage.h"
#include "../../../Image/ImageTypes/PGMImage.h"
#include "../../../Image/ImageTypes/PPMImage.h"

class ImageFactory {
    private:
        std::size_t getCommentIndex(const std::string& line);
        std::string removeComment(const std::string& src);

    public:
        ImageFactory();


        Image* loadImageFrom(std::ifstream& src) const;
        PBMImage* loadPBMImageFrom(std::ifstream& src) const;
        PGMImage* loadPGMImageFrom(std::ifstream& src) const;
        PPMImage* loadPPMImageFrom(std::ifstream& src) const;
        PPMImage* getPPMFromSizeColor(std::size_t rows, std::size_t cols, std::string hexColor) const;
};

#endif