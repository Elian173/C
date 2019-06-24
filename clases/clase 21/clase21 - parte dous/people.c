#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "people.h"

int size;
int index;
Persona** lista;

Persona* persona_newPersona(void)
{
 Persona* persona = (Persona*)malloc(sizeof(Persona));
 return persona;
}


int persona_getEdad(Persona* pPersona)
{
 return pPersona->edad;
}


char* persona_getNombre(Persona* pPersona)
{
return pPersona->nombre;
}

void persona_toString(Persona* pPersona)
{
 printf("Nombre: %s - Edad: %d \n",persona_getNombre(pPersona),persona_getEdad(pPersona));
}

void persona_initLista(void)
{
    size = 10;
    index=0;
    lista = (Persona**)malloc(sizeof(Persona*)*size);
}


void persona_addPersona(Persona* p)
{

 lista[index]=p;
 index++;
 if(index > size){
 printf("no hay mas lugar, redefinimos el array\r\n");
 size=size+10;
 lista = (Persona**)realloc(lista,sizeof(Persona*)*size);
 }
}

void persona_imprimirTodas(){

    int i=0;

    while (i<index)
    {
        printf("%s , %d\n",persona_getNombre(lista[i]),persona_getEdad(lista[i]));
        i++;
    }

return;

}
