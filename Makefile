GXX_FLAGS = -Wall -Werror

RUN_SOURCES = $(shell find src -name "*.cpp")

TEST_SOURCES = src/CommandLogic/Command/Command.cpp \
#	src/FileController/FileController.cpp

TEST_FILES = test/testCommand.cpp \ 
#	tests\testFileController.cpp

EXECUTABLE_RUN = imageEditor
EXECUTABLE_TEST = tests


compile_main:
	@g++ -o $(EXECUTABLE_RUN) $(GXX_FLAGS) \
	$(RUN_SOURCES) \
	main.cpp

run: compile
	@./$(EXECUTABLE_RUN)

run_test:
	@g++ -o $(TEST_RUN) $(GXX_FLAGS) \
	$(TEST_SOURCES) \
	$(TEST_FILEES)

	@./$(EXECUTABLE_TEST)

run_test_coverage:
	@g++ -o $(TEST_RUN) $(GXX_FLAGS) --coverage \
	$(TEST_SOURCES) \
	$(TEST_FILEES)

	@./$(EXECUTABLE_TEST)

	gcovr

clear:
	@rm -rf $(EXECUTABLE_RUN) $(EXECUTABLE_TEST)