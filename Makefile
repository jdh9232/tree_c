MAKE=make
COMPILER=gcc
LINKER=gcc
PROGRAM=tree

INCLUDES=-I./
CFLAGS=-g -Wall --std=c11 -O0 $(INCLUDES)

CFILES = $(notdir $(wildcard *.c))
HEADERS = $(notdir $(wildcard *.h))
OBJ_EXT=.o

OBJ = $(CFILES:.c=$(OBJ_EXT))

all:
	make -j8 $(PROGRAM)

%$(OBJ_EXT) : %.c $(HEADERS) ../build.config
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJ)
	$(LINKER) $(CFLAGS) $(OBJ) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) *.o
	rm -rf $(PROGRAM).dSYM

