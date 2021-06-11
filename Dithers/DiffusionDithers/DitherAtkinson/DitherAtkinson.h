#ifndef DITHER_AKTINSON_H
#define DITHER_AKTINSON_H

#include "../DiffusionDither/DiffusionDither.h"

/**
 * @brief Child class that supports Atkinson Dithering
 */
class DitherAtkinson : public DiffusionDither {
    public:
        DitherAtkinson();
};

#endif