CC=gcc
CFLAGS=-I.

calc:
	nasm -f elf32 resta.asm
#	$(CC) main.c cdecl.h resta.o
	$(CC) -m32 -o calc main.c cdecl.h resta.o

clean:
	rm *.o calc
