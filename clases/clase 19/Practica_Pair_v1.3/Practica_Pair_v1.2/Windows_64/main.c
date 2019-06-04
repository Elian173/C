#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <strings.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TOTALEMPLEADOS 50

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/
int parseData(char* fileName,Employee* arrayEmpleados, int len);

int main()
{

    Employee empleado[TOTALEMPLEADOS];
    int r;
    int i;

    r = parseData("data.csv",empleado,TOTALEMPLEADOS);

    for(i=0; i<r; i++){
        printf("id:%4d nombre:%10s apellido:%10s isEmpty:%1d\n", empleado[i].id, empleado[i].name, empleado[i].lastName, empleado[i].isEmpty);
    }

    return 0;
}



int parseData(char* fileName,Employee* arrayEmpleados, int len){

    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];


    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){


            arrayEmpleados[i].id = atoi(var1);
            strncpy(arrayEmpleados[i].name,var2,sizeof(arrayEmpleados[i].name));
            strncpy(arrayEmpleados[i].lastName,var3,sizeof(arrayEmpleados[i].lastName));

            if ( strcmp(var4,"true")==0){
            arrayEmpleados[i].isEmpty = 1;
            } else {
            arrayEmpleados[i].isEmpty = 0;
            }

            i++;
        }
        else
            break;
    }while(!feof(pFile) && i<len);

    fclose(pFile);

    return i;
}

