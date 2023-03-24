GXX_FLAGS = -Wall  -Wextra -Wpedantic -Werror

RUN_SOURCES = $(shell find src -name "*.cpp")
TEST_SOURCES = $(shell find tests -name "*.cpp")

EXECUTABLE_RUN = imageEditor
EXECUTABLE_TEST = test


compile_main:
	@g++ -o $(EXECUTABLE_RUN) $(GXX_FLAGS) \
	$(RUN_SOURCES) \
	main.cpp

run: compile
	@./$(EXECUTABLE_RUN)

run_tests:
	@g++ -o $(EXECUTABLE_TEST) $(GXX_FLAGS) \
	$(RUN_SOURCES) \
	$(TEST_SOURCES)

	@./$(EXECUTABLE_TEST)

run_test_coverage:
	@g++ -o $(TEST_RUN) $(GXX_FLAGS) --coverage \
	$(RUN_SOURCES) \
	$(TEST_SOURCES)

	@./$(EXECUTABLE_TEST)

	@gcovr

clear:
	@rm -rf $(EXECUTABLE_RUN) $(EXECUTABLE_TEST)