#include "DitherStucki.h"

DitherStucki::DitherStucki() : DiffusionDither(3, 5, 2) {
    this->dMatrix = {{ 0, 0, 0, 8, 4 }, 
                     { 2, 4, 8, 4, 2 },
                     { 1, 2, 4, 2, 1 }};
    this->distributionDivisor = 42;
}