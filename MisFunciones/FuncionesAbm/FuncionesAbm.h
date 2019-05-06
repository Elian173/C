#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*empleado?*/

typedef struct{
    int id;
    char STRING_UNO_A[20];
    char STRING_UNO_B[20];
    char CHAR_UNO_A;
    float FLOAT_UNO_A;
    int TIPO_ESTRUCTURA_UNO_CONECTOR_ID_TIPO_ESTRUCTURA_DOS;
    int isEmpty;
}TIPO_ESTRUCTURA_UNO;

/*sector*/

typedef struct
{
    int id;
    char STRING_DOS_A[20];

}TIPO_ESTRUCTURA_DOS;

/*Fecha*/

typedef struct
{
    int dia;
    int mes;
    int anyo;

}str_Fecha;

/*otro sector*/

typedef struct
{
    int id;
    char STRING_TRES_A[20];

}TIPO_ESTRUCTURA_TRES;

/*almuerzo*/

typedef struct
{
    int id;

    int TIPO_ESTRUCTURA_CUATRO_CONECTOR_ID_TIPO_ESTRUCTURA_TRES;
    int TIPO_ESTRUCTURA_CUATRO_CONECTOR_ID_TIPO_ESTRUCTURA_UNO;
    str_Fecha str_CUATRO_fecha;

    int isEmpty;

}TIPO_ESTRUCTURA_CUATRO;
