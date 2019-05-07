#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "InputElian.h"

//Hardcode//
void hardCodeLibros(ESTRUCTURA_Libros lista[]){
    int i;
    ESTRUCTURA_Libros ejemplos[]=
    {
        {1, "uno", 1},
        {2, "dos", 2},
        {3, "tres", 3},
        {4, "cuatro",4 },
        {5, "cinco" ,5},
        {6, "seis",6},
        {7, "siete",7},
        {8, "ocho", 8},
        {9, "nueve", 9},
        {10, "diez", 10}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
};

void hardCodeAutores(ESTRUCTURA_Autores lista[]){
    int i;
    ESTRUCTURA_Autores ejemplos[]=
    {
        {1, "uno", "uno", 0},
        {2, "dos","dos", 0},
        {3, "tres","tres", 0},
        {4, "cuatro","cuatro",0 },
        {5, "cinco" ,"cinco" ,0},
        {6, "seis","seis",0},
        {7, "siete","siete",0},
        {8, "ocho","ocho", 0},
        {9, "nueve","nueve", 0},
        {10, "diez","diez", 0}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}


//Funciones de mostrar//

void mostrarAutores (ESTRUCTURA_Autores autor[] , int cantidadElementos) {
    int i;
    printf("Id:  Nombre Autor:  Apellido: \n\n");
        for(i=0;i<cantidadElementos;i++){
        if (autor[i].isEmpty == 0){
            printf("%d  %s %s\n", autor[i].id,autor[i].nombre,autor[i].apellido);
        };
        };
    return;
}

void mostrarLibros (ESTRUCTURA_Libros libro[] , int cantidadElementos) {
    int i;
    printf("Id:  Nombre libro:  idAutor: \n\n");
        for(i=0;i<cantidadElementos;i++){
            printf("%d  %s %d\n", libro[i].id,libro[i].nombre,libro[i].idAutor);
        };
    return;
}


void mostrarTodosSocios (ESTRUCTURA_Socios socio[] , int cantidadElementos) {
    int i;

    printf("Id--Nombre Apellido--sexo--telefono--email-- \n\n");
        for(i=0;i<cantidadElementos;i++){
            if (socio[i].isEmpty == 0){
            printf("%d - %s %s - %c - %s - %s\n", socio[i].id,socio[i].nombre,socio[i].apellido,socio[i].sexo,socio[i].telefono,socio[i].email);
        };
        };
    return;
}

void mostrarUnSocio (ESTRUCTURA_Socios socio[] , int id) {
    printf("Id--Nombre Apellido--sexo--telefono--email-- \n\n");
    printf("%d - %s %s - %c - %s - %s\n", socio[id].id,socio[id].nombre,socio[id].apellido,socio[id].sexo,socio[id].telefono,socio[id].email);
    return;
};



//Funciones inicializacion//

void iniciarIncrementalSocios (ESTRUCTURA_Socios iniciando[],int cantidadElementos){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    }
};

void iniciarIncrementalPrestamos (ESTRUCTURA_Prestamos iniciando[],int cantidadElementos){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    };
}

void iniciarVacioSocios(ESTRUCTURA_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }
}

void iniciarVacioPrestamos(ESTRUCTURA_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }
};


//Funciones de busqueda//

//-1 si no encuentra//

int buscarPrimerIdVacioSocios (ESTRUCTURA_Socios aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia){

    int i;
    for (i=0;i<cantidadElementos;i++){

    if (aBuscar[i].isEmpty == indicadorPrimerOcurrencia){

    return i;

    };
};
    return -1;
};

int buscarPrimerIdVaciosPrestamos(ESTRUCTURA_Prestamos aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia){

    int i;
    for (i=0;i<cantidadElementos;i++){

    if (aBuscar[i].isEmpty == indicadorPrimerOcurrencia){

    return i;

    };
};
    return -1;
};

int estaTodoVacioSocios(ESTRUCTURA_Socios list[] , int len){
int i;
    for(i=0;i < len ; i++)
    {
        if (list[i].isEmpty != 1){
            return 0;
        };
    };
    return 1;
};

int estaTodoVacioPrestamos(ESTRUCTURA_Prestamos list[] , int len){
int i;
    for(i=0;i < len ; i++)
    {
        if (list[i].isEmpty != 1){
            return 0;
        };
    };
    return 1;
};

int buscarPorIdSocio(ESTRUCTURA_Socios socio[],int cantidadElementos,int id){
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(socio[i].id == id && socio[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorIdprestamo(ESTRUCTURA_Prestamos prestamo[],int cantidadElementos,int id){
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(prestamo[i].id == id && prestamo[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}


//CARGAS//

void cargarSocio (ESTRUCTURA_Socios elSocio[] , int id){

    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];

    f_i_PedirNombre(auxName , 31 , "\nIngrese el Nombre del socio:");

    f_i_PedirNombre(auxLastName , 31 , "\nIngrese el Apellido del socio:");

    f_i_PedirSexo(&auxSexo , "\nIngrese el sexo del socio:");

    f_i_PedirTelefono(auxTelef,16,"\nIngrese el telefono del socio:");

    f_i_PedirEmail(auxEmail , 31 , "\nIngrese el email del socio:");

    //falta la fecha
    elSocio[id].isEmpty = 0;
    strcpy(elSocio[id].nombre , auxName);
    strcpy(elSocio[id].apellido , auxLastName);
    elSocio[id].sexo = auxSexo;
    strcpy(elSocio[id].telefono , auxTelef);
    strcpy(elSocio[id].email , auxEmail);

    //falta la fecha

    printf("\nSocio cargado correctamente\n");

    f_i_continuar();
};

void modificarSocio (ESTRUCTURA_Socios elSocio[] , int id ){

    int opcion;
    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];

    f_i_PedirIntEntre(&opcion,1,5,"\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Sexo\n"
                      "4-Modificar Telefono\n5-Modificar Email\n6-Modificar Fecha de asociado\n7-Salir\nOpcion : ");

    switch (opcion){
    case 1 :f_i_PedirNombre(auxName,31,"\nIngrese el Nombre del Socio:\n");
            strcpy(auxName,elSocio[id].nombre);
        break;
    case 2 :f_i_PedirNombre(auxLastName,31,"\nIngrese el Apellido del Socio:\n");
            strcpy(auxLastName,elSocio[id].apellido);
        break;
    case 3 :f_i_PedirSexo(&auxSexo,"\nIngrese el sexo del Socio:\n");
            elSocio[id].sexo = auxSexo;
        break;
    case 4 :f_i_PedirTelefono(auxTelef,16,"\nIngrese el Telefono del Socio:\n");
            strcpy(auxTelef,elSocio[id].telefono);
        break;
    case 5 :f_i_PedirEmail(auxEmail,31,"\nIngrese el Email del Socio:\n");
            strcpy(auxEmail,elSocio[id].email);
        break;
    case 6 : //FALTA FECHA
        break;
}
printf("\n*Socio Modificado Correctamente*\n");
}


