#ifndef ORDERED_DITHERS_TYPES_H
#define ORDERED_DITHERS_TYPES_H

/**
 * @brief Child class that supports different ordered dithering algorithms
*/

#include "../OrderedDither/OrderedDither.h"

class Dither4Bayer : public OrderedDither {
    public:
        Dither4Bayer();
};

class Dither8Bayer : public OrderedDither {
    public:
        Dither8Bayer();
};

#endif