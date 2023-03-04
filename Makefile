GXX_FLAGS = -Wall -Werror
 
run:
	@g++ -o edit $(GXX_FLAGS) \
	Command/*.cpp \
	CommandInterpreter/*.cpp \
	CustomExceptions/CustomExceptions.cpp \
	Dithers/Dither/*.cpp \
	Dithers/DiffusionDithers/DiffusionDither/*.cpp \
	Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp \
	Dithers/OrderedDithers/OrderedDither/*.cpp \
	Dithers/OrderedDithers/OrderedDithersTypes/*.cpp \
	Editor/*.cpp \
	FileController/*.cpp \
	Image/*.cpp \
	src/InputReader/*.cpp \
	Pixel/*.cpp \
	main.cpp

	@./edit
test:
	@g++ -o test \
	Command/*.cpp \
	CommandInterpreter/*.cpp \
	CustomExceptions/CustomExceptions.cpp \
	Dithers/Dither/*.cpp \
	Dithers/DiffusionDithers/DiffusionDither/*.cpp \
	Dithers/DiffusionDithers/DiffusionDithersTypes/*.cpp \
	Dithers/OrderedDithers/OrderedDither/*.cpp \
	Dithers/OrderedDithers/OrderedDithersTypes/*.cpp \
	Editor/*.cpp \
	FileController/*.cpp \
	Image/*.cpp \
	src/InputReader/*.cpp \
	Pixel/*.cpp \
	Tests/test_Command.cpp

	@./tests

clean:
	@rm edit tests