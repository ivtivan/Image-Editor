
run:
	g++ -o edit \
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
	InputReader/*.cpp \
	Pixel/*.cpp \
	main.cpp

	./edit
tests:
	g++ -o tests \
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
	InputReader/*.cpp \
	Pixel/*.cpp \
	Tests/*.cpp

	./tests