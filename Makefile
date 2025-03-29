CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = main
OBJ = binarymaxheap.o demo.o test.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

binarymaxheap.o: binarymaxheap.cpp binarymaxheap.h
	$(CC) $(CFLAGS) -c binarymaxheap.cpp

demo.o: demo.cpp binarymaxheap.h
	$(CC) $(CFLAGS) -c demo.cpp

test.o: test.cpp binarymaxheap.h
	$(CC) $(CFLAGS) -c test.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) test_binarymaxheap_output.txt
