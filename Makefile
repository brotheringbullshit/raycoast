CC = gcc
CFLAGS = `sdl2-config --cflags` -Iinclude
LDFLAGS = `sdl2-config --libs` -lSDL2_image
PREFIX = /usr/local

# Target library name
TARGET_LIB = build/libraycoast.a

# Source files
SRC = src/raycoast.c
OBJ = $(SRC:.c=.o)

# Example source files
EXAMPLE_SRC = examples/example.c
EXAMPLE_OBJ = $(EXAMPLE_SRC:.c=.o)
EXAMPLE_BIN = build/example

# Default target
all: $(TARGET_LIB) $(EXAMPLE_BIN)

# Build the static library
$(TARGET_LIB): $(OBJ)
	mkdir -p build
	ar rcs $@ $^

# Build the example
$(EXAMPLE_BIN): $(EXAMPLE_OBJ) $(TARGET_LIB)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Install headers and library
install: all
	mkdir -p $(PREFIX)/include/raycoast
	cp include/raycastlib.h $(PREFIX)/include/raycoast/
	mkdir -p $(PREFIX)/lib
	cp $(TARGET_LIB) $(PREFIX)/lib/

# Uninstall headers and library
uninstall:
	rm -f $(PREFIX)/include/raycastlib/raycoast.h
	rm -f $(PREFIX)/lib/raycoast.a

# Clean up
clean:
	rm -rf $(OBJ) $(EXAMPLE_OBJ) build

.PHONY: all clean install uninstall
