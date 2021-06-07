#include "DitherStucki.h"

DitherStucki::DitherStucki() : DiffusionDither(3, 5, 2) {
    unsigned int src[3][5] = {{ 0, 0, 0, 8, 4 }, 
                              { 2, 4, 8, 4, 2 },
                              { 1, 2, 4, 2, 1 }};
    this->distributionDivisor = 42;
    setDMatrix(src);
}