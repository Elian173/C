#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesElian.h"
#define TRUE 1
#define FALSE 0
#define LEN 99



/**Funciones de input **/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int continuar(void){

    char r;
    printf( "\n --S-- o --N-- \n");
    r = toupper(getche());

while ( !((r=='S')||(r=='N')) ){

        printf ("\nError, ingrese (S/N)... ");
        r = toupper(getche());
        }

return (r=='S');
};
/** \brief Pregunta al usuario si quiere continuar (S o N) ; no permite otros caracteres
 * \param ()
 * \return Si se ingresa S devuelve int 1 , si se ingresa N devuelve int */

float pedirFloat(char mensaje[]){
    float x;
    printf("%s",mensaje);
    scanf("%f",&x);
    return x;
}
/*** \brief Pide un float
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El float ingresado */

int pedirInt(char mensaje[]){
    int x;
    printf("%s",mensaje);
    scanf("%d",&x);
    return x;
}
/*** \brief Pide un Int
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El Int ingresado */

char pedirChar(char mensaje[]){
    char x;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&x);
    return x;
}
/*** \brief Pide un char
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El char ingresado */

void pedirString(char mensaje[],char x[]){
    printf("%s",mensaje);
    scanf ("%s", x);
}
/*** \brief Pide un string
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El string ingresado */

int pedirNombre(char mensaje[],char*texto)
{
    int retorno;
    int i;
    int invalido;
    char auxiliar[LEN];

    printf("%s\n",mensaje);

    do {
        fgets(auxiliar,LEN,stdin);
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

int perdirStringNumeros(char mensaje[],char*numero[]){
    int i;
    int invalido;
    char auxiliar[LEN];
    fflush(stdin);
    printf("%s\n",mensaje);

    do {
        fgets(auxiliar,LEN,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            if (auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                invalido = TRUE;
                printf("\nError, ingrese solo numeros \n");
                break;
            }
            else
            {
                invalido = FALSE;
            }
        }
    } while (invalido);

    strcpy(numero, auxiliar);
    return 0;
}
/** \brief Pide un texto solo de numeros y lo devuelve
 * \param mensaje Es la pregunta que ve el usuario
 * \param numero = Array donde se carga el string ingresado
 * \return 1 si el texto contiene solo numeros*/

 int pedirEdad (char mensaje[]){
    int edad;
    printf("%s:",mensaje);
    scanf("%d",&edad);

    while (edad>99 || edad<0){
    printf("*Hubo un error *\n%s:",mensaje);
    scanf("%d",&edad);
    };
    return edad;
    }
/** \brief Pide un numero entre 0 y 99
 * \param mensaje Es la pregunta que ve el usuario
 * \return el numero ingresado*/


/**Funciones de Orden e Inicializacion de arrays**/////////////////////////////////////////////////////////////////////////////////////////////////////////

 void iniciarEnMenosUno(int*x[],int cuantosElementos){
    for (int i=0;i<cuantosElementos;i++){
        x[i]= -1;
    };
 };



 int buscarLugar(int elArray[], int cuantosElementos , int lugarLibre){

     for (int i=0;i<cuantosElementos;i++){
        if (elArray [i] == lugarLibre){
            return i;
        }
     }
     return -2;
 };




/**Funciones de alta y baja **/


void darDeAlta (EMP*empleado){

    empleado.nombre[x].nombre=pedirNombre()


}

