# Image-Editor
Allows editing PBM, PGM and PPM files.

Supports creating new images, as well as cropping, resizing (scaling) and dithering.

## Resizing Algorithm
The following [resizing algorithm](https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html) is used.

## Dithering Algorithms
The program supports [11 dirhering algorithms](https://tannerhelland.com/2012/12/28/dithering-eleven-algorithms-source-code.html).

It creates a black and white image of the same file type as the original one.

## Command Line to Run Program
```
g++ Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/CustomExceptions.cpp Dithers/Dither/*.cpp Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/OrderedDithersTypes/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp main.cpp
```

## Command Line to Run Tests
```
g++ Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/CustomExceptions.cpp Dithers/Dither/*.cpp  Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/OrderedDithersTypes/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp Tests/*.cpp
```