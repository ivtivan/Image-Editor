#ifndef DITHER_4_BAYER_H
#define DITHER_4_BAYER_H

#include "../OrderedDither/OrderedDither.h"

/**
 * @brief Child class that supports dithering with 4x4 Bayer matrix.
 */
class Dither4Bayer : public OrderedDither {
    public:
        Dither4Bayer();
};

#endif