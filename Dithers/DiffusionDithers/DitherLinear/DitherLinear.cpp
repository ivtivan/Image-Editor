#include "DitherLinear.h"

DitherLinear::DitherLinear() : DiffusionDither(1, 2, 0) {
    unsigned int src[1][5] = { { 0, 1 } };
    this->distributionDivisor = 1;
    setDMatrix(src);
}