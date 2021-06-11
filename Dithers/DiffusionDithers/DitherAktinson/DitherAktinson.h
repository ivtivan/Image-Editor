#ifndef DITHER_AKTINSON_H
#define DITHER_AKTINSON_H

#include "../DiffusionDither/DiffusionDither.h"

/**
 * @brief Child class that supports Atkinson Dithering
 */
class DitherAktinson : public DiffusionDither {
    public:
        DitherAktinson();
};

#endif