#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "cdecl.h"

int suma_asm( int , int ) __attribute__ ((cdecl));
int suma_binaria_asm( int , int ) __attribute__ ((cdecl));
int resta_asm( int , int ) __attribute__ ((cdecl));
//int resta_binaria_asm( int , int ) __attribute__ ((cdecl));

int operacion_int (char ** argv)
{
    int int1, int2; 

    // identificamos los argumentos
    int1 = atoi (argv[1]);
    int2 = atoi (argv[3]);

    // identificamos los simbolos '+' y '-'
    if ((char)argv[2][0] == '+')
    {
       printf("La suma es: %d\n", suma_asm  (int1, int2));

    }else if ((char)argv[2][0] == '-')
    {
        printf("La resta es: %d\n", resta_asm (int1, int2));
    }

    return 0;
}

int operacion_binario (char ** argv)
{
    int int1, int2; 

    // identificamos los argumentos
    int1 = atoi (argv[2]);
    int2 = atoi (argv[4]);

    // identificamos los simbolos '+' y '-'
    if ((char)argv[3][0] == '+')
    {
       printf("La suma binaria es: %d\n", suma_binaria_asm  (int1, int2));
       //printf("La suma binaria es: %d", int1);

    }else if ((char)argv[3][0] == '-')
    {
        //printf("La resta binaria es: %d\n", resta_binaria_asm (int1, int2));
        printf("La resta binaria es: %d", int1);

    }
    return 0;
}

int main (int argc, char * argv[]){
    int numero = 3;
    int tam = 1;
    int leng = 1;

    int num;

    if ( numero < 0)
        num = (-1)*numero;
    else
        num = numero;

    for (int i = 0; ; i++)
    {
        if ( num >= leng)
        {
            tam++;
            leng *= 2;
        }else{
            break;
        }
        
    }
    

    int binario[tam]; // | | |0|0|1| 

    for (int i = tam-1; i >= 0 ; i--)
    {
        binario[i] = (num % 2);
        num /= 2;
        if (num == 1 || num == 0){
            binario [i-1] = num;
        }
    }
    
    if(numero >= 0){
        binario[0] = 0;
    }else{
        binario[0] = 1;
    }
    
    char binario_char[tam];
    for (size_t i = 0; i < tam; i++)
    {
        binario_char[0] = (char)binario[0];
    }
    
    /* verificamos opcion binaria */
    // if (strcmp (argv[1], "-b") == 0)
    //    operacion_binario (argv);
    //else 
    //    operacion_int (argv);
  
  
    return 0;
}