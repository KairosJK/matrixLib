CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -g

# -------------------------------- TESTS --------------------------------
all:
	@echo "COMPILING ALL TARGETS"
	make -s mol.o
	make -s libmol.so
	make -s given_test1
	make -s custom_test1
	make -s playground

given_test1: tests/given_test1.c mol.o
	$(CC) $(CFLAGS) -o bin/given_test1 tests/given_test1.c mol.o

custom_test1: tests/custom_test1.c mol.o
	$(CC) $(CFLAGS) -o bin/custom_test1 tests/custom_test1.c mol.o

playground: tests/playground.c mol.o
	$(CC) $(CFLAGS) -o bin/playground tests/playground.c mol.o

# --------------------------------- LIBS --------------------------------
mol.o: mol.c mol.h
	$(CC) $(CFLAGS) -c -fPIC mol.c

libmol.so: mol.c mol.h
	$(CC) $(CFLAGS) -fPIC -shared -o libmol.so mol.c -lc

# -------------------------------- TOOLS --------------------------------
clean:
	@echo "REMOVING ALL BINARIES, OBJ FILES, LIBRARIES, AND DOTFILES"
	rm -f *.o 
	rm -f *.so 
	rm -f bin/*
	rm -f vgcore.*