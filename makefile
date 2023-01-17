CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -g

HEADER_COL:=$(shell tput setaf 6)
HEADER_RESET:=$(shell tput sgr0)

LIBFILE_PATH := src/
TESTFILE_PATH := tests/

LIBFILES := matrix_io.c matrix_init.c matrix_edit.c matrix_arithmetic.c
OBJFILES := matrix_io.o matrix_init.o matrix_edit.o matrix_arithmetic.o

TESTBINARYS := from_console identity zeroed from_file

##################################################################
######################## collective rules ########################
##################################################################

all: testbin staticlib dynamiclib

staticlib: libmatrix.a
dynamiclib: libmatrix.so
testbin: 
	$(info $(HEADER_COL)PRODUCING TEST EXECUTABLES$(HEADER_RESET))
	@make $(TESTBINARYS)

##################################################################
########################### test rules ###########################
##################################################################

$(TESTBINARYS): %: $(TESTFILE_PATH)%.c $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $< $(OBJFILES)

##################################################################
######################### library rules ##########################
##################################################################

%.o: $(LIBFILE_PATH)%.c
	$(CC) $(CFLAGS) -c -o $@ $^

libmatrix.a: $(OBJFILES)
	$(info $(HEADER_COL)PRODUCING STATIC LIBRARY$(HEADER_RESET))
	ar rcs $@ $^

libmatrix.so: $(OBJFILES)
	$(info $(HEADER_COL)PRODUCING DYNAMIC LIBRARY$(HEADER_RESET))
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ -lc

##################################################################
####################### orginization rules #######################
##################################################################

clean:
	$(info $(shell tput setaf 1)REMOVING ALL BINARIES, OBJ FILES, LIBRARIES, AND DOTFILES$(HEADER_RESET))
	rm -f $(OBJFILES)
	rm -f $(TESTBINARYS)
	rm -f *.so
	rm -f *.a
	rm -f vgcore.*