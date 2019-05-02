#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*empleado?*/

typedef struct{
    int str_UNO_ID;
    char str_UNO_STRING_A[20];
    char str_UNO_STRING_B[20];
    char str_UNO_CHAR;
    float str_UNO_FLOAT;
    int str_UNO_CONECTOR_ID_str_DOS;
    int str_UNO_isEmpty;

}str_UNO;

/*sector*/

typedef struct
{
    int str_DOS_ID;
    char str_DOS_STRING_A[20];

} str_DOS;

/*Fecha*/

typedef struct
{
    int dia;
    int mes;
    int anyo;

} str_Fecha;

/*otro sector*/

typedef struct
{
    int str_TRES_ID;
    char str_TRES_STRING_A[20];

} str_TRES;

/*almuerzo*/

typedef struct
{
    int str_CUATRO_ID;

    int str_CUATRO_CONECTOR_ID_str_TRES;
    int str_CUATRO_CONECTOR_ID_str_UNO;
    str_Fecha str_CUATRO_fecha;

    int str_CUATRO_isEmpty;

} str_CUATRO;
