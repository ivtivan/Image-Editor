#include "DiffusionDithersTypes.h"

DitherAtkinson::DitherAtkinson() : DiffusionDither(3, 4, 1) {
    unsigned int src[3][5] = {{ 0, 0, 1, 1 }, 
                              { 1, 1, 1, 0 },
                              { 0, 1, 0, 0 }};
    setDMatrix(src);
    this->distributionDivisor = 8;
}

DitherBurkes::DitherBurkes() : DiffusionDither(2, 5, 2) {
    unsigned int src[2][5] = {{ 0, 0, 0, 8, 4 }, 
                              { 2, 4, 8, 4, 2 }};
    this->distributionDivisor = 32;
    setDMatrix(src);
}

DitherFS::DitherFS() : DiffusionDither(2, 3, 1) {
    unsigned int src[2][5] = {{ 0, 0, 7 }, 
                              { 3, 5, 1 }};
    this->distributionDivisor = 16;
    setDMatrix(src);
}

DitherJJN::DitherJJN() : DiffusionDither(3, 5, 2) {
    unsigned int src[3][5] = {{ 0, 0, 0, 7, 5 }, 
                              { 3, 5, 7, 5, 1 },
                              { 1, 3, 5, 3, 1 }};
    this->distributionDivisor = 48;
    setDMatrix(src);
}

DitherLinear::DitherLinear() : DiffusionDither(1, 2, 0) {
    unsigned int src[1][5] = { { 0, 1 } };
    this->distributionDivisor = 1;
    setDMatrix(src);
}

DitherSierra::DitherSierra() : DiffusionDither(3, 5, 2) {
    unsigned int src[3][5] = {{ 0, 0, 0, 5, 3 }, 
                              { 2, 4, 5, 4, 2 },
                              { 0, 2, 3, 2, 0 }};
    this->distributionDivisor = 32;
    setDMatrix(src);
}

DitherTRSierra::DitherTRSierra() : DiffusionDither(2, 5, 2) {
    unsigned int src[2][5] = {{ 0, 0, 0, 4, 3 }, 
                              { 1, 2, 3, 2, 1 }};
    this->distributionDivisor = 16;
    setDMatrix(src);
}

DitherSierraLite::DitherSierraLite() : DiffusionDither(2, 3, 1) {
    unsigned int src[2][5]= {{ 0, 0, 2 }, 
                             { 1, 1, 0 }};
    this->distributionDivisor = 4;
    setDMatrix(src);
}

DitherStucki::DitherStucki() : DiffusionDither(3, 5, 2) {
    unsigned int src[3][5] = {{ 0, 0, 0, 8, 4 }, 
                              { 2, 4, 8, 4, 2 },
                              { 1, 2, 4, 2, 1 }};
    this->distributionDivisor = 42;
    setDMatrix(src);
}