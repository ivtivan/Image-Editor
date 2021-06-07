#include "DitherJJN.h"

DitherJJN::DitherJJN() : DiffusionDither(3, 5, 2) {
    this->dMatrix = {{ 0, 0, 0, 7, 5 }, 
                     { 3, 5, 7, 5, 1 },
                     { 1, 3, 5, 3, 1 }};
    this->distributionDivisor = 48;
}