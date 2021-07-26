#ifndef DIFFUSION_DITHERS_TYPES_H
#define DIFFUSION_DITHERS_TYPES_H

/**
 * @brief Child class that supports different diffusion dithering algorithms
*/

#include "../DiffusionDither/DiffusionDither.h"

class DitherAtkinson : public DiffusionDither {
    public:
        DitherAtkinson();
};

class DitherBurkes : public DiffusionDither {
    public:
        DitherBurkes();
};

class DitherFS : public DiffusionDither {
    public:
        DitherFS();
};

class DitherJJN : public DiffusionDither {
    public:
        DitherJJN();
};

class DitherLinear : public DiffusionDither {
    public:
        DitherLinear();
};

class DitherSierra : public DiffusionDither {
    public:
        DitherSierra();
};

class DitherTRSierra : public DiffusionDither {
    public:
        DitherTRSierra();
};

class DitherSierraLite : public DiffusionDither {
    public:
        DitherSierraLite();
};

class DitherStucki : public DiffusionDither {
    public:
        DitherStucki();
};

#endif
