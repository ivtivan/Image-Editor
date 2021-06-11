#ifndef DITHER_8_BAYER_H
#define DITHER_8_BAYER_H

#include "../OrderedDither/OrderedDither.h"

/**
 * @brief Child class that supports dithering with 8x8 Bayer matrix
 */
class Dither8Bayer : public OrderedDither {
    public:
        Dither8Bayer();
};

#endif