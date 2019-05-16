#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

#define NUMERO_DE_ELEMENTOS 20

    void mostrarCadenaPUNTEROMASMAS( char* punteroCadena )
    {
    while(*punteroCadena != '\0')
    {
    printf("%c\n",*punteroCadena);
    punteroCadena++;

    printf("%p\n",punteroCadena);
    }
    }


    void mostrarCadenaNOMODPUNTERO( char *punteroCadena)
    {

    int i = 0;

    while ( *(punteroCadena+i)!= '\0' ){

    printf("%c\n", *(punteroCadena+ i));
    printf("%p\n",punteroCadena);

    i++;
    }
    }


int main ()
{
    char lista[NUMERO_DE_ELEMENTOS];

    char* puntero;

    puntero = lista;

    strcpy (lista,"HOLA QUE TAL");

    printf("-------------CON PUNTERO++ ----------------\n");

    mostrarCadenaPUNTEROMASMAS(puntero);

    printf("-------------CON *(PUNTERO +I) ----------------\n");
    mostrarCadenaNOMODPUNTERO(puntero);

    printf(" \n");

    return 0;

}
