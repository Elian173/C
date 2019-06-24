#include <stdio.h>
#include <stdlib.h>
#include "SuperLinkedList.h"

//Prototipo masomenos //

int main()
{

    Super_initLista();
    do
    {
        Super* variable_Super = Super_newSuper();
        char nombreAux[20];
        preguntarNombre(nombreAux);
        if(Super_setName(variable_Super,nombreAux))
            printf("El nombre no es valido");
        int edadAux = preguntarEdad();
        if(Super_setEdad(variable_Super,edadAux))
            printf("La edad no es válida");
        Super_addSuper(variable_Super);
    }
    while(preguntarSalir()!='S');
    return 0;
}
