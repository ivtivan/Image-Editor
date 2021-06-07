#include "DitherSierraLite.h"

DitherSierraLite::DitherSierraLite() : DiffusionDither(2, 3, 1) {
    unsigned int src[2][5]= {{ 0, 0, 2 }, 
                             { 1, 1, 0 }};
    this->distributionDivisor = 4;
    setDMatrix(src);
}