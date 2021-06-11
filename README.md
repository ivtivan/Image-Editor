# Image-Editor
Allows editing PBM, PGM and PPM files.

Supports creating new images, as well as cropping, resizing(scaling) and dithering.

## Resizing Algorithm
The following [resizing algorithm](https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html) is used.

## Dithering Algorithms
The program supports [11 dirhering algorithms](https://tannerhelland.com/2012/12/28/dithering-eleven-algorithms-source-code.html).

## Command Line to Run Program
```
g++ Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/EditException/EditException.cpp CustomExceptions/ExitException/*.cpp CustomExceptions/ImageException/*.cpp CustomExceptions/PixelException/*.cpp CustomExceptions/FileException/*.cpp Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DitherLinear/*.cpp Dithers/DiffusionDithers/DitherAtkinson/*.cpp Dithers/DiffusionDithers/DitherBurkes/*.cpp Dithers/DiffusionDithers/DitherFS/*.cpp Dithers/DiffusionDithers/DitherJJN/*.cpp Dithers/DiffusionDithers/DitherSierra/*.cpp Dithers/DiffusionDithers/DitherSierraLite/*.cpp Dithers/DiffusionDithers/DitherStucki/*.cpp Dithers/DiffusionDithers/DitherTRSierra/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/Dither4Bayer/*.cpp Dithers/OrderedDithers/Dither8Bayer/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp main.cpp
```

## Command Line to Run Tests
```
g++ Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/EditException/EditException.cpp CustomExceptions/ImageException/*.cpp CustomExceptions/ExitException/*.cpp CustomExceptions/PixelException/*.cpp CustomExceptions/FileException/*.cpp Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DitherLinear/*.cpp Dithers/DiffusionDithers/DitherAtkinson/*.cpp Dithers/DiffusionDithers/DitherBurkes/*.cpp Dithers/DiffusionDithers/DitherFS/*.cpp Dithers/DiffusionDithers/DitherJJN/*.cpp Dithers/DiffusionDithers/DitherSierra/*.cpp Dithers/DiffusionDithers/DitherSierraLite/*.cpp Dithers/DiffusionDithers/DitherStucki/*.cpp Dithers/DiffusionDithers/DitherTRSierra/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/Dither4Bayer/*.cpp Dithers/OrderedDithers/Dither8Bayer/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp Tests/*.cpp
```

## Further Ideas
Possible further implementations:
- Change functions in Image class to make it clearer and easier to test
- Implement Color class, which supports:
  - color validation
  - creating color from string
- Implement the file ocnversion in its own class
- Better exception handling


## Link to GitHub Repository
The following is a link to [the GitHub Repository](https://github.com/ivtivan/Image-Editor).