#ifndef DITHER_TR_SIERRA_H
#define DITHER_TR_SIERRA_H

#include "../DiffusionDither/DiffusionDither.h"

/**
 * @brief Child class that supports Two-Row Sierra Dithering
 */
class DitherTRSierra : public DiffusionDither {
    public:
        DitherTRSierra();
};

#endif