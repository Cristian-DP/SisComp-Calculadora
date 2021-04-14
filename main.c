#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdecl.h"

int binario_entero (char * s);
char * entero_binario(int numero);

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

/**
 * Resuelve para las entradas de forma decimal
*/
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

/*
    Resuelve para las entradas de forma binaria
*/
int operacion_binario (char ** argv)
{
    // identificamos los argumentos
    char* bin1 = argv[2];
    char* bin2 = argv[4];
   
    int int1 = binario_entero (bin1);
    int int2 = binario_entero (bin2);

    // identificamos los simbolos '+' y '-'
    if ((char)argv[3][0] == '+')
    {
        printf ("La suma binaria es: %s", 
            entero_binario( suma_asm(int1, int2)));

    }else if ((char)argv[3][0] == '-')
    {
        printf ("La resta binaria es: %s", 
            entero_binario( resta_asm(int1, int2)));
    }
    
    return 0;
}

/*
    Se obtiene la representacion entera del binario
*/
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

/*
    Se pasa un numero entero a su version en binario
*/
char * entero_binario(int numero){
    
    int tam = 1;
    int leng = 1;
    int num;
    int flag_signed = 0;
    
    /* verifico si es positivo */
    if ( numero < 0){
        num = (-1)*numero;
        flag_signed = 1;
    }
    else{
        num = numero;
        flag_signed = 0;
    }

    /* obtengo el tamaño del binario resultante */
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

    char binario[tam];
    lldiv_t resultadoDeLaDivision;

    /* obtengo la representacion binaria */
    for (int i = tam-1; i >= 0 ; i--)
    {
        resultadoDeLaDivision = lldiv(num, 2);
        binario[i] = resultadoDeLaDivision.rem == 1 ? '1' : '0';
	    num = resultadoDeLaDivision.quot;
    }
    
    /* Representamos el signo del binario*/
    if(flag_signed){
        binario[0] = '1';
    }else{
        binario[0] = '0';
    }

    return strdup (binario);
}