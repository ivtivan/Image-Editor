
generate:
	@g++ -o imageEditor.out Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/CustomExceptions.cpp Dithers/Dither/*.cpp Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/OrderedDithersTypes/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp main.cpp
tests:
	@g++ -0 tests.out Command/*.cpp CommandInterpreter/*.cpp CustomExceptions/CustomExceptions.cpp Dithers/Dither/*.cpp  Dithers/DiffusionDithers/DiffusionDither/*.cpp Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp Dithers/OrderedDithers/OrderedDither/*.cpp Dithers/OrderedDithers/OrderedDithersTypes/*.cpp Editor/*.cpp FileController/*.cpp Image/*.cpp InputReader/*.cpp Pixel/*.cpp Tests/*.cpp
clean:
	@rm imageEditor.out  tests.out