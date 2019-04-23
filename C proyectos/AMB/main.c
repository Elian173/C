#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "AMBfunciones.h"
#define TRUE 1
#define FALSE 0
#define CANTIDAD 5


int main()
{
 /**/struct EMP empleadoNro[CANTIDAD];


    iniciarEnCero(empleadoNro[0].nroLista,CANTIDAD);




    for (int i=0;i<CANTIDAD;i++) {
    printf( "lista : %d\n" , empleadoNro[i].nroLista);
}





    return 0;
}
