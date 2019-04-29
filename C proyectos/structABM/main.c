#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>

#include "structABM.h"
#include "fInput.h"

#define CANTIDAD_EMPLEADOS 20

typedef struct fecha{
    int dia;
    int mes;
    int anio;
    int id;
}fecha;

typedef struct menu{
    int id;
    int codigoMenu;
    float importe;
}menu;

typedef struct almuerzo{
    int id;
    int codigoAlmuerzo;
    int codigoMenu;
    int id_Empleado;
    struct fecha fecha;
}almuerzo;

typedef struct empleado{
    char nombre [51];
    char apellido[51];
    int ocup;
    int legajo;
    char sexo;
    float salario;
    fecha fechaIngreso;
}empleado;

typedef struct empleado_sector{
    int id_Empleado;
    int id_Sector;
}empleado_sector;

typedef struct sector{
    int id;
    char definicion;
}sector;

int main()
{
    /**Variables**/
    empleado emp[CANTIDAD_EMPLEADOS];
    int aux,flag=1,seleccion;
    int i=0;

    sector sec [5]= {1,'a',2,'b',3,'c',4,'d',5,'e'};


    /**Inicio todos los id de la variable de empleados en -1**/

    for (i=0;i<CANTIDAD_EMPLEADOS;i++){
    emp[i].ocup = -1;
    };


    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char apellidos[][50]={"Mar","Ped","Je","Pe","Pab","Mat"};
    char sexo[]={'F','M','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000,6000};

    for(i=0; i<6; i++)
    {
        strcpy(emp[i].nombre, nombres[i]);
        strcpy(emp[i].apellido, apellidos[i]);
        emp[i].sexo = sexo[i];
        emp[i].salario = sueldosBruto[i];
        emp[i].ocup = 1;
    };
/**Inicio los legajos de 1 a X**/

    for (i=0;i<CANTIDAD_EMPLEADOS;i++){
    emp[i].legajo=i;
    };

/**Menu principal**/

while (flag==1){
/**Menu**/

    printf("------------MENU--------------\n");
    printf("Presione 1 para dar de alta una persona\n"
           "Presione 2 para dar de baja una persona\n"
           "Presione 3 para mostrar\n"
           "Presione 4 para salir\n");

    seleccion = getInt("\n Opcion : ");

    switch (seleccion) {
        /**Alta**/
        case 1 :
            /**Busco el primer indice vacio**/
            aux = -2;
            for(i=0 ; i<CANTIDAD_EMPLEADOS ; i++){
            if (emp[i].ocup == -1){
            aux = i;
            break;
            };
            };
        /**Si hay un indice vacio doy de alta, sino informo que no hay lugar**/
            if (aux != -2) {
            darDeAltaEmpleado(&emp,aux);
            } else {
            printf("**No quedan lugares** \n") ;
            };
        break;

        /**BAJA**/
        case 2:
            aux = getInt("Ingrese el legajo del empleado a dar de baja\n");
            if (emp[aux].ocup == -1 || aux>CANTIDAD_EMPLEADOS){
            printf("No se encontro el legajo de ese empleado\n");
            break;
            };

            mostrarEmpleado(emp,aux);
            printf("Es este el empleado a dar de baja?");
            seleccion = continuar();
            if (seleccion == 1){
            emp[aux].ocup = -1;
            printf("\nSe dio de baja el empleado\n");
            break;
            }
            else {
            break;
            };

        break;

        /**Listar**/
        case 3 :
        listarEmpleados (emp,CANTIDAD_EMPLEADOS);
        break;

        case 4: flag=0;
        break;

        case 5:ordenarEmpleados(emp,CANTIDAD_EMPLEADOS);break;
};



}




    return 0;
}
