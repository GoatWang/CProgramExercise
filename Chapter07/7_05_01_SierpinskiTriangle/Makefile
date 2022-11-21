# Use clang, but could be gcc
CC=clang

# Our 'core' set of flags used for everything
BASEFLAGS=-Wall -Wextra -Wpedantic -std=c99 -Wvla -Wfloat-equal

# Optimise code, but allow no warnings during compilation
PRODFLAGS=$(BASEFLAGS) -O1
# Be super tough - fail to compile if *any* errors
# PRODFLAGS=$(BASEFLAGS) -O1 -Werror

# Not optimisation, add in Sanitizer code -> huge executable file but will tell you if an array goes out-of-bounds etc.
DEVFLAGS=$(BASEFLAGS) -fsanitize=address -fsanitize=undefined -g3 
LDLIBS= -lm

# Production Code - no warnings allowed, no sanitizer
main : main.c
	$(CC) main.c -o compile/main $(PRODFLAGS) $(LDLIBS)

# Development Code - sanitizer enabled
main_dev : main.c
	$(CC) main.c -o compile/main_dev $(DEVFLAGS) $(LDLIBS)

all: main main_dev

clean:
	rm -f main main_dev
