
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>



/*Funciones de ordenamiento*/


void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos)
{
    int i;
    for (i=0; i<cantidadElementos; i++)
    {
        var_dondeAsignar[i]= asignarleEsteNumero;
    };
    return;
}


void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos)
{
    int i;
    for (i=0; i<cantidadElementos; i++)
    {

        var_dondeAsignar[i]= i+1;

    };
    return;
}


int f_o_BuscarIndicePrimerOcurrencia (int var_dondeAsignar[],int cantidadElementos,int indicadorPrimerOcurrencia)
{

    int i;
    for (i=0; i<cantidadElementos; i++)
    {

        if (var_dondeAsignar[i]==indicadorPrimerOcurrencia)
        {

            return i;

        };

    };
    return -1;
}


void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos)
{

    int i, j, aux;
    for(i=0; i<cantidadElementos-1; i++)
    {
        for(j=0; j<cantidadElementos-1; j++)
        {
            if(var_dondeAsignar[j] < var_dondeAsignar[j+1])
            {
                aux = var_dondeAsignar[j];
                var_dondeAsignar[j] = var_dondeAsignar[j+1];
                var_dondeAsignar[j+1] = aux;
            };
        };
    };
    return;
}


void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[], int cantidadElementos)
{
    int i, j;
    int tmp;

    for (i = 1; i < cantidadElementos; i++)
    {
        tmp = var_dondeAsignar[i];
        j = i - 1;

        while ((j >= 0) && (tmp < var_dondeAsignar[j]))
        {

            var_dondeAsignar[j + 1] = var_dondeAsignar[j];
            j--;
        };

        var_dondeAsignar[j + 1] = tmp;

    };
}


void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,
                                     char var_dondeAsignar[cantidadElementos][longitudMaxString])
{

    char auxiliar[longitudMaxString];

    int i,j;

    for(i=0; i<cantidadElementos-1; i++)
    {
        for(j=i+1; j<cantidadElementos; j++)
        {
            if(strcmp( var_dondeAsignar[i],var_dondeAsignar[j])>0)
            {
                strcpy(auxiliar,var_dondeAsignar[j]);
                strcpy(var_dondeAsignar[j], var_dondeAsignar[i]);
                strcpy(var_dondeAsignar[i], auxiliar);
            };
        };
    };
    return;
}


void f_o_ArreglarCaps (int cantidadElementos,int longitudMaxString,
                       char var_dondeAsignar[cantidadElementos][longitudMaxString])
{
    int i=0;
    for (i=0; i<cantidadElementos; i++)
    {
        strlwr(var_dondeAsignar[i]);
        var_dondeAsignar[i][0]= toupper(var_dondeAsignar[i][0]);
    };
    return;
}

