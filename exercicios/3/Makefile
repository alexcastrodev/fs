CC = gcc
CFLAGS = -Wall -I./src
SRC = main.c src/disk.c
OBJ = main.o src/disk.o
TARGET = build/fs

all: release

release: CFLAGS += -O2 -s
release: clean $(TARGET)

debug: CFLAGS += -g -O0
debug: clean $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c src/disk.h
	$(CC) $(CFLAGS) -c main.c

src/disk.o: src/disk.c src/disk.h
	$(CC) $(CFLAGS) -c src/disk.c -o src/disk.o

clean:
	rm -rf *.o src/*.o build/
