#include "DitherAtkinson.h"

DitherAtkinson::DitherAtkinson() : DiffusionDither(3, 4, 1) {
    unsigned int src[3][5] = {{ 0, 0, 1, 1 }, 
                              { 1, 1, 1, 0 },
                              { 0, 1, 0, 0 }};
    setDMatrix(src);
    this->distributionDivisor = 8;
}