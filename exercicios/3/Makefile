CC = gcc
CFLAGS = -Wall -I./src
OBJ = main.o src/disk.o
TARGET = build/fs

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c src/disk.h
	$(CC) $(CFLAGS) -c main.c

src/disk.o: src/disk.c src/disk.h
	$(CC) $(CFLAGS) -c src/disk.c -o src/disk.o

clean:
	rm -rf *.o src/*.o build/
