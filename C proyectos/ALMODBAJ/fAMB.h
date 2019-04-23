#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define CANTIDAD 2

int pedirInt(char mensaje[]){
    int x;
    printf("%s",mensaje);
    scanf("%d",&x);
    return x;
};


int pedirNombre(char mensaje[],char*texto)
{
    int retorno;
    int i;
    int invalido;
    char auxiliar[20];

    printf("%s\n",mensaje);

    do {
        fgets(auxiliar,20,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                invalido = -1;
                printf("\nError, ingrese solo letras y espacios: ");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                invalido = 0;
                retorno = 0;
            }
        }
    } while (invalido);

    strcpy(texto, auxiliar);
    return retorno;
}
/** \brief Pide un texto solo de letras y lo devuelve
 * \param mensaje Es la pregunta que ve el usuario
 * \param texto= Array donde se carga el string ingresado
 * \return 1 si el texto contiene solo letras*/
