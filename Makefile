CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Files and Targets
SRC = binarymaxheap.cpp demo.cpp test.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = demo
testEXEC = test

# Default target (build everything)
all: build

# Build targets
build: $(EXEC)

$(EXEC): binarymaxheap.o demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test_build: $(testEXEC)

$(testEXEC): binarymaxheap.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run targets
run: build
	./$(EXEC)

test_run: test_build
	./$(testEXEC)

# Combined build and run
build_run: build run

test_build_run: test_build test_run

# Object files
%.o: %.cpp binarymaxheap.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean
clean:
	rm -f $(OBJ) $(EXEC) $(testEXEC)