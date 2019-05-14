#include <stdio.h>
#include <stdlib.h>

void funcionUno (int dato[])
{

    int i;

    for (i=0 ; i<5 ; i++)
    {
        printf("funcion 1 : %d\n",dato[i]);
    }
}

void funcionDos (int dato[])
{

    int i;

    for (i=0 ; i<5 ; i++)
    {

        printf("funcion 2 : %d\n", *(dato+i) );

    }
}

void funcionTres (int *dato)
{

    int i;

    for (i=0 ; i<5 ; i++)
    {

        printf("funcion 3 : %d\n", dato[i] );

    }
}

void funcionCuatro (int *dato)
{

    int i;

    for (i=0 ; i<5 ; i++)
    {

        printf("funcion 4 : %d\n", *(dato+i) );

    }
}

int main()
{
    int dato [5] = {1,2,3,4,5};

    funcionUno(dato);
    printf("\n");
    funcionDos(dato);
    printf("\n");
    funcionTres(dato);
    printf("\n");
    funcionCuatro(dato);


    return 0;
}
