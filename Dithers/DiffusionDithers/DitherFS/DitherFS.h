#ifndef DITHER_FS_H
#define DITHER_FS_H

#include "../DiffusionDither/DiffusionDither.h"

/**
 * @brief Child class that supports Floyd-Steinberg Dithering
 */
class DitherFS : public DiffusionDither {
    public:
        DitherFS();
};

#endif