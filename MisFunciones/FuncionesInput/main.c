#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesInput.h"
#define LARGO 20



int main()
{
    char patente [10];

    f_i_PedirPatenteVieja(patente,"Ingrese la patente del auto:");

    printf("patente:%s",patente);

    printf("pepe");

    f_i_continuar();

        return 0 ;
}
