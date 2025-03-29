# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS =

# Executables
MAIN_EXEC = main
TEST_EXEC = test

# Source files
MAIN_SRC = demo.cpp
TEST_SRC = test.cpp
HEAP_SRC = binarymaxheap.cpp

# Object files
MAIN_OBJ = demo.o binarymaxheap.o
TEST_OBJ = test.o binarymaxheap.o

# All targets
all: $(MAIN_EXEC)

# Main executable build
$(MAIN_EXEC): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -o $(MAIN_EXEC) $(LDFLAGS)

# Test executable build
$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -o $(TEST_EXEC) $(LDFLAGS)

# Main program object files
$(MAIN_OBJ): $(MAIN_SRC) binarymaxheap.h
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC)

# Test program object files
$(TEST_OBJ): $(TEST_SRC) binarymaxheap.h
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC)

# Run the main program
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Build and run the main program
build_run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Build the test executable
test_build: $(TEST_EXEC)

# Run the test executable
test_run: $(TEST_EXEC)
	./$(TEST_EXEC)

# Build and run the test executable
test_build_run: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean generated files
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC) $(MAIN_OBJ) $(TEST_OBJ) test_binarymaxheap_output.txt
