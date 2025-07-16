CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/main.c
OBJ = build/main.o
TARGET = build/fs

all: build_dir $(TARGET)

build_dir:
	mkdir -p build

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -rf build