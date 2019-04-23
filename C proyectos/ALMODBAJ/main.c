#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "fAMB.h"
#define TRUE 1
#define FALSE 0
#define CANTIDAD 2

typedef struct {
    char nombre [20];
    char apellido[20];
    int estado;
    int edad;
    int legajo;
    int indice;
}emp;


void listar (emp empleado[]){
     for (int i=0; i<=CANTIDAD ;i++) {
        if (empleado[i].legajo != -1 ){

        printf("Indice:\tLegajo:\tEdad:\tEstado\tNombre y apellido:\n");
        printf("[%d]\t[no]\t[no]\t[%d]\t %s %s\n",
        empleado[i].indice ,empleado[i].legajo,
        empleado[i].edad ,empleado[i].estado,
        empleado[i].nombre ,empleado[i].apellido);
        };
        };}


void alta (emp A[] , int i) {
    int auxiliar=-2;

    /**Valido que no se repita el legajo**/

    while(auxiliar==-2) {
    auxiliar = pedirInt("Ingrese el legajo del empleado:\n");

    for (int i=0;i<CANTIDAD;i++){
        if ( A[i].legajo == auxiliar) {
            printf("Error, el legajo ya existe\n");
            auxiliar=-2;
        };
        };
    };
    if (auxiliar!=-2){
        A[i].legajo = auxiliar;
    };

    pedirNombre("Ingrese el Nombre de el empleado",A[i].nombre);
    pedirNombre("Ingrese el Apellido de el empleado",A[i].apellido);

};



int main () {

emp empleado[CANTIDAD];
int opcion , i ;
int continuar=1;
int auxIndice=-2;

/**Inicio los indices**/
    for (i=0; i<=CANTIDAD ;i++) {
        empleado[i].indice = i;
    };
/**Inicio los legajos en -1**/
    for (i=0; i<=CANTIDAD ;i++) {
        empleado[i].legajo = -1;
    };


while (continuar==1){
/**Menu**/

       printf("------------MENU--------------\n");
    printf("Presione 1 para dar de alta una persona\n"
           "Presione 2 para dar de baja una persona\n"
           "Presione 3 para mostrar\n"
           "Presione 4 para salir\n");

    opcion = pedirInt("\n Opcion : ");

    switch (opcion) {
        /**Alta**/
        case 1 :

        /**Busco el primer indice vacio**/
            auxIndice=-2;
            for(i=0 ; i<CANTIDAD ; i++){
                if (empleado[i].legajo == -1) {
                    auxIndice = empleado[i].indice;
                };
            };
        /**Si hay un indice vacio doy de alta, sino informo que no hay lugar**/
            if (auxIndice!=-2) {
            alta(empleado, auxIndice);
            } else {
            printf("**No quedan lugares** \n") ;
            };

            break;


        /**BAJA**/
        case 2: listar(empleado) ;
        printf("Ingrese el indice del empleado a dar de baja");
        auxIndice = pedirInt("\nIndice: ");
        empleado[auxIndice].legajo=-1;

        break;

        /**Listar**/
        case 3 : listar (empleado);
        break;

        case 4:break;
};

}



return 0;

}


