#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "people.h"
#include "inputs.h"

int main()
{
    /*
    int size = 2;
    int index=0;

    Persona* * lista;
    */
    /*lista = (Persona* * )malloc(sizeof(Persona * )*size);*/

    persona_initLista();
    //if (lista != NULL){
    do
    {
        Persona* persona = persona_newPersona();/* Persona* persona = (Persona*)malloc(sizeof(Persona));*/

        f_i_PedirNombre(persona->nombre,10,"Ingrese nombre:");
        f_i_PedirEdad(&persona->edad,"Ingrese edad:");

        persona_addPersona(persona);
        persona_toString(persona);



        /*f_i_PedirNombre(persona->nombre,10,"Ingrese nombre:");
        f_i_PedirEdad(&persona->edad,"Ingrese edad:");*/
        /*lista[index] = persona;
        index ++;
        printf("\nSIZE: %d\n"ç,size);
        if(index>=size)
        {
        // incrementamos el tamaño del array
            printf("se agranda el array");
            size+=10;
            lista = realloc(lista,sizeof(Persona*)*size);
        }*/

    }
    while(f_i_SioNo("Continuar?")!=0);
    //}


    /*
        for (i=0;i<index;i++){
            printf("\nDir:%p - Peso puntero:%d  Datos :%s  %d Peso 2doPunt: %d \n",lista[i],sizeof(lista[i]),lista[i]->nombre,lista[i]->edad,sizeof(*lista[i]));
        }
    */
    persona_imprimirTodas();
    return 0;
}
