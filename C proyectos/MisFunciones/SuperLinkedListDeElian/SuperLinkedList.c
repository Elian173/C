#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char Super_StringUno[31];
    char Super_StringDos[31];
    char Super_Char;
    float Super_Float;
    int Super_IntUno;
    int Super_IntDos;
    int Super_isEmpty;
}Super;

/////////Buscar memoria para un nuevo Super//////////////
Super* Super_newSuper(void)
{
Super* Super = (Super*)malloc(sizeof(Super));
return Super;
}
/////////Retorna un puntero a un lugar libre o NULL si no hay//////////////

/////////Iniciar Lista Super////////////////
void Super_initLista(void)
{
int size = 10;
int index=0;
int lista = (Super**)malloc(sizeof(Super*)*size);
}
/////////no retorna nada ////////////////

/////////Añadir un Super , Aumenta el tamaño del array de p* si no hay mas lugar ////////////////
void Super_addSuper(Super* p)
{
Super lista[index]=p;
int index++;
    if(index>=size)
    {
    size = size*2;
    lista = (Super**)realloc(lista,sizeof(Super*)*size);
}
}
//////////No retorna nada  /////////////////////////

/**////Super GETS (devuelven un dato de la estructura , o un puntero que apunte al 1er coso del coso )///////////**/

//Super_StringUno
char* Super_getStringUno(Super* var)
{
return var->Super_StringUno;
}

//char Super_StringDos[31];

char* Super_getStringDos(Super* var)
{
return var->Super_StringDos;
}

//char Super_Char;
char Super_getChar(Super* var)
{
return var->Super_Char;
}

//Float Super_Float;

float Super_getFloat(Super* var)
{
return var->Super_Float;
}

//int Super_IntUno;
int Super_getIntUno(Super* var)
{
return var->Super_IntUno;
}

//int Super_IntDos;
int Super_getIntDos(Super* var)
{
return var->Super_IntDos;
}

//int Super_isEmpty;

int Super_getIsEmpty(Super* var)
{
return var->Super_isEmpty;
}
