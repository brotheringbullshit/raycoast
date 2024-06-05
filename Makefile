CC = gcc
CFLAGS = `sdl2-config --cflags` -Iinclude
LDFLAGS = `sdl2-config --libs` -lm
PREFIX = /usr/local

# Source files
SRC = src/raycoast.c
OBJ = $(SRC:.c=.o)

# Example program
EXAMPLE_SRC = examples/main.c
EXAMPLE_OBJ = $(EXAMPLE_SRC:.c=.o)
EXAMPLE_BIN = build/example

# Default target
all: $(OBJ) libraycoast.a example

# Compile C files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Link library
libraycoast.a: $(OBJ)
	ar rcs build/$@ $^

# Build example program
example: $(EXAMPLE_OBJ) libraycoast.a
	$(CC) -o $(EXAMPLE_BIN) $(EXAMPLE_OBJ) build/libraycoast.a $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXAMPLE_OBJ) build/libraycoast.a $(EXAMPLE_BIN)

install: libraycoast.a
	mkdir -p $(PREFIX)/lib
	cp -f build/libraycoast.a $(PREFIX)/lib

uninstall:
	rm -f $(PREFIX)/lib/libraycoast.a
