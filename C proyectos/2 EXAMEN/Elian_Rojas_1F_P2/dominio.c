#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "dominio.h"

STR_Dominio* dominio_new()
{
    STR_Dominio* ptr_dominio = (STR_Dominio*)malloc(sizeof(STR_Dominio));

    return ptr_dominio;
}

void dominio_delete (STR_Dominio *ptr_dominio)
{
    if(ptr_dominio != NULL)
    {
        free(ptr_dominio);
    }
    return;
}

void objectA_print(STR_Dominio* ptr_ObjectA)
{
    if(ptr_ObjectA != NULL)
    {
        printf("%5d  %s  %5d   %c\n",ptr_ObjectA->id,ptr_ObjectA->dominio,ptr_ObjectA->anio,ptr_ObjectA->tipo);
    }
}

int controller_ListObjectA(LinkedList* linkedList)
{

    STR_Dominio *ptr_ObjectA;
    int value = 0 ;
    int i;

    ptr_ObjectA = dominio_new();

    if(ptr_ObjectA != NULL && linkedList != NULL && ll_len(linkedList) > 0)
    {
        printf("______________________________\n");
        for(i = 0; i < ll_len(linkedList) ; i++)
        {
            ptr_ObjectA = (STR_Dominio*) ll_get(linkedList,i);

            if(ptr_ObjectA != NULL && ptr_ObjectA->id != -1)
            {
                objectA_print(ptr_ObjectA);
            }
        }
        value = 1;
    }
    else
    {
        printf("La lista esta vacia.\n");
    }
    return value;
}

//____________________________________
int dominio_getId(STR_Dominio* ptr_dominio,int* id)
{
    int value = 0;
    if(ptr_dominio != NULL)
    {
        *id = ptr_dominio->id ;
        value = 1;
    }
    return value;
}

int dominio_setId(STR_Dominio* ptr_dominio,int id)
{
    int value = 0;

    if(ptr_dominio != NULL && id > 0)
    {
        ptr_dominio->id = id;
        value = 1;
    }
    return value;
}
//____
int dominio_getDominio(STR_Dominio* ptr_dominio,char* dominio)
{
    int value = 0;

    if(ptr_dominio != NULL && dominio != NULL)
    {
        strcpy(dominio, ptr_dominio->dominio);
        value = 1;
    }
    return value;
}

int dominio_setDominio(STR_Dominio* ptr_dominio,char* dominio)
{
    int value = 0;

    if(ptr_dominio != NULL && dominio != NULL)
    {
        strncpy(ptr_dominio->dominio, dominio, sizeof(ptr_dominio->dominio));
        value = 1;
    }
    return value;
}
//_______________________

int dominio_getAnio(STR_Dominio* ptr_dominio,int *anio)
{
    int value = 0;

    if(ptr_dominio != NULL)
    {
        *anio = ptr_dominio->anio;
        value = 1;
    }
    return value;
}

int dominio_setAnio(STR_Dominio* ptr_dominio,int anio)
{
    int value = 0;

    if(ptr_dominio != NULL)
    {
        ptr_dominio->anio = anio;
        value = 1;
    }
    return value;

}

//
int dominio_getTipo(STR_Dominio* ptr_dominio,char* tipo)
{
    int value = 0;

    if(ptr_dominio != NULL && tipo != NULL)
    {
        *tipo = ptr_dominio->tipo;
        value = 1;
    }
    return value;
}

int dominio_setTipo(STR_Dominio* ptr_dominio,char tipo)
{
    int value = 0;

    if(ptr_dominio != NULL)
    {
        ptr_dominio->tipo = tipo;
        value = 1;
    }

    return value;
}
//ORDENES

int dominio_setMotoAuto(void* dominio)
{
    int value = 0;
    char bufferA[31];
    dominio_getDominio(dominio,bufferA);

    if (bufferA[0]<'0' || bufferA[0]>'9') //significa que es un auto
    {
        dominio_setTipo(dominio,'A');
        value=1;
    }
    else
    {
        dominio_setTipo(dominio,'M');
        value = 1;
    }
    return value;
}

int dominio_subListaMotos(void* dominio)
{
    int value = 0;
    char auxTipo;

    dominio_getTipo(dominio,&auxTipo);

    if (auxTipo=='M') //significa que es una moto
    {
        value = 1;
    }
    else
    {
        value = 0;
    }
    return value;
}

int dominio_subListaAutos(void* dominio)
{
    int value = 0;
    char auxTipo;
    dominio_getTipo(dominio,&auxTipo);

    if (auxTipo == 'A') //significa que es un auto.
    {
        value = 1;
    }
    else
    {
        value = 0;
    }
    return value;
}
