CC=gcc
CFLAGS=-I.

calc:
	nasm -f elf32 suma.asm
	$(CC) -m32 -o calc main.c cdecl.h suma.o

clean:
	rm *.o calc
