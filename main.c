#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdecl.h"


int binario_entero (char * s);
int* entero_binario(int numero, int** arreglo);

int suma_asm( int , int ) __attribute__ ((cdecl));
int resta_asm( int , int ) __attribute__ ((cdecl));

int operacion_binario (char ** argv);
int operacion_int (char ** argv);


int main (int argc, char * argv[]){

    /* verificamos opcion binaria */
    if (strcmp (argv[1], "-b") == 0)
        operacion_binario (argv);
    else 
        operacion_int (argv);
  
  
    return 0;
}

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
    // identificamos los argumentos
    char* bin1 = argv[2];
    char* bin2 = argv[4];

    int int1 = binario_entero (bin1);
    int int2 = binario_entero (bin2);

    int* arreglo;

    // identificamos los simbolos '+' y '-'
    if ((char)argv[3][0] == '+')
    {
        printf("La suma binaria es: ");
        int* binario = entero_binario( suma_asm(int1, int2), &arreglo);
        
        for (int i = 0; i < (sizeof(binario)/4); i++)
        {
            printf ("%d",binario[i]);
        }

    }else if ((char)argv[3][0] == '-')
    {
        printf("La resta binaria es: ");
        int* binario = entero_binario( resta_asm(int1, int2), &arreglo);
        
        for (int i = 0; i < (sizeof(binario)/4); i++)
        {
            printf ("%d",binario[i]);
        }
    }
    
    return 0;
}


int binario_entero (char * s){
    
    int size = strlen(s);
    int entero = 0;

    for (int i = 0; i < size; i++){
        int potencia = 1;

        if (s[i] == '1')
        {
            for(int j = 0; j < (size-i-1); j++)
                potencia *= 2;

            entero += potencia;   
        }
    }
    return entero;
}



int* entero_binario(int numero, int** arreglo){
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
    
    *arreglo = binario;
    return *arreglo;
}