#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void f_i_PedirEdad (int * var_dondeAsignar,char mensaje[])
{
    int edad;
    fflush(stdin);
    printf("\n%s:\n",mensaje);
    scanf("%d",&edad);

    while (edad>99 || edad<0)
    {
        fflush(stdin);
        printf("\n**Edad Invalida**\n%s",mensaje);
        scanf("%d",&edad);
    };

    *var_dondeAsignar=edad;

    return;
}

void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[])
{
    int i;
    int no_es_un_nombre;
    char auxiliar[longitudMaxString];

    do
    {
        fflush(stdin);
        printf("%s\n",mensaje);

        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                no_es_un_nombre = -1;
                printf("\n**Error, ingrese solo letras y espacios**\n");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                no_es_un_nombre = 0;
            }
        }
    }
    while (no_es_un_nombre);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar, auxiliar);
    return;
}

int f_i_SioNo(char mensaje[])
{
    char r;
    printf("\n%s\n",mensaje);
    printf( "\n --S-- o --N-- \n");
    fflush(stdin);
    r = toupper(getche());
    printf("\n");

    while ( !((r=='S')||(r=='N')) )
    {
        printf ("\nError, ingrese (S/N)... \n");
        fflush(stdin);
        r = toupper(getche());
        printf("\n");
    };
    return (r=='S'); /*Devuelve 1 si se ingresa 'S'*/
}

