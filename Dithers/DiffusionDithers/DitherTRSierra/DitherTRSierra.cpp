#include "DitherTRSierra.h"

DitherTRSierra::DitherTRSierra() : DiffusionDither(2, 5, 2) {
    this->dMatrix = {{ 0, 0, 0, 4, 3 }, 
                     { 1, 2, 3, 2, 1 }};
    this->distributionDivisor = 16;
}