#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "../../../Image/Image.h"
#include "../../../Image/ImageTypes/PBMImage.h"
#include "../../../Image/ImageTypes/PGMImage.h"
#include "../../../Image/ImageTypes/PPMImage.h"
#include "../../../Pixel/PixelTypes/PBMPixel.h"
#include "../../../Pixel/PixelTypes/PGMPixel.h"
#include "../../../Pixel/PixelTypes/PPMPixel.h"

class ImageFactory {
    private:
        std::ifstream* src;
        const Dimension* dimension;
        unsigned short maxValue;
        Pixel*** pixels;

        std::string readImageTypeIdentificator();
        void saveDimension();
        void saveMaxValue();

        void allocatePixelMatrix();

        void readIntoPBMPixelMatrix();
        void readIntoPGMPixelMatrix();

        void readIntoPPMPixelMatrix();
        void fillPPMPixelMatrixColor(const std::string& hexColor);
    public:
        ImageFactory();


        Image* loadImageFrom(std::ifstream& src);
        PBMImage* loadPBMImageFrom();
        PGMImage* loadPGMImageFrom();
        PPMImage* loadPPMImageFrom();
        PPMImage* getPPMFromSizeColor(const Dimension& dimension, const std::string& hexColor);
};

#endif