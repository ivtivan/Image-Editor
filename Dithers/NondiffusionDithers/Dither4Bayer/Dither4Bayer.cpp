#include "Dither4Bayer.h"

Dither4Bayer::Dither4Bayer() : NondiffusionDither(4) {
    this->tMatrix = {{  0,  8,  2, 10 }, 
                     { 12,  4, 14,  6 },
                     {  3, 11,  1,  9 },
                     { 15,  7, 13,  5}};
}