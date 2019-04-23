#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "../FuncionesElian/FuncionesElian.h"
#define TRUE 1
#define FALSE 0
#define CANTIDAD 5

int main()
{

struct EMP empleado[CANTIDAD];
int opcion;

/**
strcpy(empleado[1].nombre,"Elian");
strcpy(empleado[1].apellido,"ROJAS");
empleado[1].edad= 19;
empleado[1].legajo= 100;
empleado[1].estado= 1;

printf("%s  %s  %d   %d    %d",empleado[1].nombre,empleado[1].apellido,empleado[1].edad,empleado[1].legajo,empleado[1].estado);

**/
    iniciarEnMenosUno(empleado.legajo[],CANTIDAD);


    printf("------------MENU--------------\n");
    printf("Presione 1 para dar de alta una persona\n"
           "Presione 2 para mostrar\n"
           "Presione 3 para dar de baja una persona\n"
           "Presione 4 para salir\n");

    opcion = pedirInt("Opcion: ");


    switch (opcion){
    case 1: darDeAlta();

    case 2: for (int i=0;i<CANTIDAD;i++){
    printf( "%d", empleado[i].legajo);
    };

    };


    return 0;

}

