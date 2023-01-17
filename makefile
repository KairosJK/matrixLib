CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -g
LIBFILE_PATH := src/
TESTFILE_PATH := tests/
LIBFILES := matrix_io.c matrix_init.c matrix_edit.c matrix_arithmetic.c
OBJFILES := matrix_io.o matrix_init.o matrix_edit.o matrix_arithmetic.o
TESTFILES := from_console.c identity.c zeroed.c
TESTBINARYS := from_console identity zeroed

##################################################################
######################## collective rules ########################
##################################################################

all: testbin staticlib dynamiclib

staticlib: libmatrix.a
dynamiclib: libmatrix.so
testbin: $(TESTFILE_PATH)$(TESTFILES) $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^

##################################################################
########################### test rules ###########################
##################################################################

#%: $(test)

#$(TESTBINARYS): $(TESTFILE_PATH)$(TESTFILES) $(OBJFILES)
#	$(CC) $(CFLAGS) -o $@ $^

#from_console: tests/from_console.c $(OBJFILES)
#	$(CC) $(CFLAGS) -o $@ $^

#identity: tests/from_console.c $(OBJFILES)
#	$(CC) $(CFLAGS) -o $@ $^

##################################################################
######################### library rules ##########################
##################################################################

%.o: $(LIBFILE_PATH)%.c
	$(CC) $(CFLAGS) -c -o $@ $^

libmatrix.a: $(OBJFILES)
	@echo "PRODUCING STATIC LIBRARY"
	ar rcs $@ $^

libmatrix.so: $(OBJFILES)
	@echo "PRODUCING DYNAMIC LIBRARY"
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ -lc

##################################################################
####################### orginization rules #######################
##################################################################

clean:
	@echo "REMOVING ALL BINARIES, OBJ FILES, LIBRARIES, AND DOTFILES"
	rm -f $(OBJFILES)
	rm -f $(TESTBINARYS)
	rm -f *.so
	rm -f *.a
	rm -f vgcore.*