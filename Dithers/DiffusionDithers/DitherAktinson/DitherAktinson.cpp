#include "DitherAktinson.h"

DitherAktinson::DitherAktinson() : DiffusionDither(3, 4, 1) {
    this->dMatrix = {{ 0, 0, 1, 1 }, 
                     { 1, 1, 1, 0 },
                     { 0, 1, 0, 0 }};
    this->distributionDivisor = 8;
}