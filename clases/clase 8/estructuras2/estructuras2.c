#include <stdio.h>
#include <stdlib.h>
#include "estructuras2.h"
// sin terminar
typedef struct {
char apellido [30];
char nombre [30];
int edad;
int isEmpty;
}ePersona;


void carga(ePersona datos[])
{
    for (int i=0;i<3;i++){
	printf("Ingrese el apellido del alumno [%i]: ",i);
	scanf("%s",&datos[i].apellido);
	printf("Ingrese la edad del alumno [%i]: ",i);
	scanf("%d",&datos[i].apellido);
};
};
