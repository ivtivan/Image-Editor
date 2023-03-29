#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include "../Image.h"
#include "../../Pixel/PixelTypes/PPMPixel.h"

class PPMImage : public Image {
    public:
        PPMImage(Dimension dimension, pixel_ptr_vector&& pixels);

        const std::string getTypeID() const override;
        void outputImage(std::ostream& os) const override;

        ~PPMImage();
};

#endif