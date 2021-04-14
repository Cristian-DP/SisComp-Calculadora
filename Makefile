CC=gcc
CFLAGS=-I.

calc:

	nasm -f elf32 resta.asm 
	nasm -f elf32 suma.asm
	$(CC) -m32 -o calc main.c cdecl.h resta.o suma.o 

clean:
	rm *.o *.gch *.out calc
