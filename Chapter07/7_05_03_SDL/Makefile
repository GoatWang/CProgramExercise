# Use clang, but could be gcc
CC=clang

# Our 'core' set of flags used for everything
BASEFLAGS=-Wall -Wextra -Wpedantic -std=c99 -Wvla -Wfloat-equal

# Optimise code, but allow no warnings during compilation
# pkg-config is accesible after you install SDL2 - on my machine it's equaivalent to the flags : -I/usr/include/SDL2 -D_REENTRANT
PRODFLAGS=$(BASEFLAGS) -O1 -Werror `pkg-config sdl2 --cflags`

# Not optimisation, add in Sanitizer code -> huge executable file but will tell you if an array goes out-of-bounds etc.
DEVFLAGS=$(BASEFLAGS) -fsanitize=address -fsanitize=undefined -g3 
LDLIBS= -lm

# Library linking : maths and SDL2
# pkg-config is accesible after you install SDL2 - on my machine it's equaivalent to the flags : -lSDL2
LIBS =  -lm `pkg-config sdl2 --libs`

all: main

main: main.c neillsdl2.c neillsdl2.h
	$(CC) main.c neillsdl2.c -o compile/main $(PRODFLAGS) $(LIBS)

clean:
	rm -f compile/main

run: main
	./compile/main
