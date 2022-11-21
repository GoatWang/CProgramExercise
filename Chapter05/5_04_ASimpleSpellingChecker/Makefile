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
CFLAGS=$(DEVFLAGS)

# Production Code - no warnings allowed, no sanitizer
5_04_04_main : 5_04_04_main.c
	$(CC) 5_04_04_main.c -o compile/5_04_04_main $(PRODFLAGS) $(LDLIBS)

# Development Code - sanitizer enabled
5_04_04_main_dev : 5_04_04_main.c
	$(CC) 5_04_04_main.c -o compile/5_04_04_main_dev $(DEVFLAGS) $(LDLIBS)

all: 5_04_04_main 5_04_04_main_dev

clean:
	rm -f compile/5_04_04_main compile/5_04_04_main_dev
