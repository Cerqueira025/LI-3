# Specifies the directory where header files are located
IDIR = include
# Specifies the compiler to be used
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Wextra -pedantic -O0 -I$(IDIR)

# Default target
all: main

ODIR = src/obj

LIBS = -lm -lcurses

DEPS = $(wildcard $(IDIR)/*.h)

OBJ = $(patsubst src/%.c, $(ODIR)/%.o, $(wildcard src/*.c))

$(info $$OBJ is [${OBJ}])

# Build the executable
$(ODIR)/%.o: src/%.c $(DEPS)
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Compile source files into object files
main: $(OBJ)
	$(CC) -o prog $^ $(CFLAGS) $(LIBS)

.PHONY: clean

# Clean generated files
clean:
	rm -f $(ODIR)/*.o prog
