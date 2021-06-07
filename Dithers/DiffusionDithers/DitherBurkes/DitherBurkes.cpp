#include "DitherBurkes.h"

DitherBurkes::DitherBurkes() : DiffusionDither(2, 5, 2) {
    unsigned int src[2][5] = {{ 0, 0, 0, 8, 4 }, 
                              { 2, 4, 8, 4, 2 }};
    this->distributionDivisor = 32;
    setDMatrix(src);
}