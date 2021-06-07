# Image-Editor
Allows editing PBM, PGM and PPM files.

Supports cropping, resizing(scaling) and dithering.

## Resizing algorithm
Resizeing algorithm described: https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html

## Dithering algorithms
The 11 supported dirhering algorithms: https://tannerhelland.com/2012/12/28/dithering-eleven-algorithms-source-code.html

## Command Line
```
g++ Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/ExitException/*.cpp CustomExceptions/FileException/*.cpp Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DitherLinear/*.cpp Dithers/DiffusionDithers/DitherAktinson/*.cpp Dithers/DiffusionDithers/DitherBurkes/*.cpp Dithers/DiffusionDithers/DitherFS/*.cpp Dithers/DiffusionDithers/DitherJJN/*.cpp Dithers/DiffusionDithers/DitherSierra/*.cpp Dithers/DiffusionDithers/DitherSierraLite/*.cpp Dithers/DiffusionDithers/DitherStucki/*.cpp Dithers/DiffusionDithers/DitherTRSierra/*.cpp Dithers/NondiffusionDithers/NondiffusionDither/*.cpp Dithers/NondiffusionDithers/Dither4Bayer/*.cpp Dithers/NondiffusionDithers/Dither8Bayer/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp main.cpp
```