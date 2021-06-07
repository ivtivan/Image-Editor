#include "DitherSierra.h"

DitherSierra::DitherSierra() : DiffusionDither(3, 5, 2) {
    this->dMatrix = {{ 0, 0, 0, 5, 3 }, 
                     { 2, 4, 5, 4, 2 },
                     { 0, 2, 3, 2, 0 }};
    this->distributionDivisor = 32;
}