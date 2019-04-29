#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
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


void listarEmpleados (empleado losEmpleados[],int cantidad){
    ordenarEmpleados(losEmpleados,cantidad);
    int i=0;
    for (i=0;i<cantidad;i++){
    if (losEmpleados[i].ocup != -1 ){
    printf("Legajo:%d Nombre:%s %s Sexo:%c Salario:%f \n",losEmpleados[i].legajo,losEmpleados[i].nombre,losEmpleados[i].apellido,
           losEmpleados[i].sexo,losEmpleados[i].salario);
    };
    };
    };

void darDeAltaEmpleado(empleado*elEmpleado, int lugar){

    elEmpleado[lugar].ocup= 1;
    getNombre("Ingrese el nombre: ",elEmpleado[lugar].nombre);
    getNombre("Ingrese el apellido: ",elEmpleado[lugar].apellido);
    elEmpleado[lugar].sexo = getSexo();
    printf("\nIngrese el salario del empleado:\n");
    scanf("%f",&elEmpleado[lugar].salario);

};

int buscarLugar(int id, int cantidad , int lugar /*que numero se busca*/){
    int i=0;
    for (i=0;i<cantidad;i++){
     if (id == lugar){
     return i;
     };
     };
     return -2;
 };

void mostrarEmpleado(empleado elEmpleado[], int lugar)
{
    printf("Legajo:%d\nNombre:%s\nApellido:%s\nSexo:%c\nSalario:%f\n",elEmpleado[lugar].legajo,
           elEmpleado[lugar].nombre,elEmpleado[lugar].apellido,elEmpleado[lugar].sexo,elEmpleado[lugar].salario);
};

void ordenarEmpleados(empleado*losEmpleados,int cant){
    int i,aux,j,x;
    /*Cuantos empleados hay*/
    for(i=0;i<cant;i++)
    {
        if (losEmpleados[i].ocup!=-1)
        {
            x++;
        }
    };
    cant = x;
    for (i = 0 ; i < cant - 1; i++)
   {
    for (j = 0 ; j < cant - i ; j++)
    {
      if (losEmpleados[j].legajo > losEmpleados[j+1].legajo) /* For decreasing order use < */
      {
        aux       = losEmpleados[j].legajo;
        losEmpleados[j].legajo   = losEmpleados[j+1].legajo;
        losEmpleados[j+1].legajo = aux;
      }
    }
  }
}

int contarEmpleados (empleado losEmpleados[],int cantidad)
{
    int i,x;
    for(i=0;i<cantidad;i++)
    {
        if (losEmpleados[i].ocup!=-1)
        {
            x++;
        }
    }
    return x;
}
