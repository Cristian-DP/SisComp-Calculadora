#include <stdio.h>
#include <stdlib.h>

#include "cdecl.h"

int suma_asm( int , int ) __attribute__ ((cdecl));
//int PRE_CDECL resta_asm( int, int ) POST_CDECL;
int resta_asm( int , int ) __attribute__ ((cdecl));

int main (int arg, char ** argv){
    
    int int1, int2; 

    // identificamos los argumentos
    int1 = atoi (argv[1]);
    int2 = atoi (argv[3]);

    // identificamos los simbolos '+' y '-'
    if ((char)argv[2][0] == '+')
    {
       printf("La suma es: %d\n", suma_asm  (int1, int2));
       // printf("OK suma, %d, %d", int1, int2);

    }else if ((char)argv[2][0] == '-')
    {
        printf("La resta es: %d\n", resta_asm (int1, int2));
        //printf("OK resta, %d, %d", int1, int2);

    }
  
    return 0;
}

/*  Pruebas
    ./app 2 + 4
    ./app 2 - 4
    */