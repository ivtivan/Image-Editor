#include "DitherFS.h"

DitherFS::DitherFS() : DiffusionDither(2, 3, 1) {
    this->dMatrix = {{ 0, 0, 7 }, 
                     { 3, 5, 1 }};
    this->distributionDivisor = 16;
}