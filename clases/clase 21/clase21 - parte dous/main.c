#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "people.h"
#include "inputs.h"

int main()
{
    persona_initLista();
    do
    {
        Persona* persona = persona_newPersona();/* Persona* persona = (Persona*)malloc(sizeof(Persona));*/

        f_i_PedirNombre(persona->nombre,10,"Ingrese nombre:");
        f_i_PedirEdad(&persona->edad,"Ingrese edad:");

        persona_addPersona(persona);
        persona_toString(persona);

    }
    while(f_i_SioNo("Continuar?")!=0);
    persona_imprimirTodas();

    return 0;
}
