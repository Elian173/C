#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Autos.h"
#include "inputElian.h"

#define CANTIDADMARCAS 5
#define CANTIDADCOLORES 5
#define CANTIDADSERVICIOS 4

#define CANTIDADAUTOS 100
#define CANTIDADTRABAJOS 100

int main()
{
    //Variables//

    STR_Color colores[CANTIDADCOLORES];
    STR_Marca marcas[CANTIDADMARCAS];
    STR_Servicio servicios[CANTIDADSERVICIOS];

    STR_Auto autos[CANTIDADAUTOS];
    STR_Trabajo trabajos[CANTIDADTRABAJOS];

    //-----

    char seleccion;

    ///////////
    //Iniciacion//
    iniciarAutosIsEmpty ( autos,CANTIDADAUTOS, 1);// 1 Significa que NO hay un auto cargado
    inciarIncrementalIdAutos (autos, CANTIDADAUTOS);  // pongo los id del 0 al -> CANTIDADAUTOS de uno en uno

    iniciarTrabajosIsEmpty(trabajos,CANTIDADTRABAJOS,1);
    inciarIncrementalIdTrabajos(trabajos,CANTIDADTRABAJOS);


    //Hardcode//
    hardcodearColor(colores);
    hardcodearMarca(marcas);
    hardcodearServicio(servicios);
    hardcodeAutos(autos);
    hardcodeTrabajos (trabajos);
    //Menu//

    do
    {
        limpiar();
        printf("Ingrese A para dar de alta un auto\n"
               "Ingrese B para modificar un auto\n"
               "Ingrese C para dar de baja un auto\n"
               "Ingrese D para listar Autos\n"
               "Ingrese E para listar marcas\n"
               "Ingrese F para listar colores\n"
               "Ingrese G para listar Servicios\n"
               "Ingrese H para dar de alta un trabajo\n"
               "Ingrese I para listar trabajos\n");

        //////////
        //Switch//

        fflush(stdin);
        seleccion = getchar();
        seleccion = tolower(seleccion);

        switch(seleccion)
        {


        case 'a':
            limpiar();
            darDeAltaAuto(autos,CANTIDADAUTOS);
            f_i_continuar();
            break;

        case 'b':
            limpiar();
            modificarAuto(autos,CANTIDADAUTOS);
            f_i_continuar();
            break;

        case 'c':
            limpiar();
            dardeBajaAuto(autos,CANTIDADAUTOS);
            f_i_continuar();
            break;

        case 'd':
            limpiar();
            mostrarAutos( autos, colores, marcas, CANTIDADAUTOS);
            f_i_continuar();
            break;


        case 'e':
            limpiar();
            mostrarMarcas(marcas,CANTIDADMARCAS);
            f_i_continuar();
            break;

        case 'f':
            limpiar();
            mostrarColores(colores,CANTIDADCOLORES);
            f_i_continuar();
            break;

        case 'g':
            limpiar();
            mostrarServicios(servicios,CANTIDADSERVICIOS);
            f_i_continuar();
            break;

        case 'h':
            limpiar();
            altaTrabajo (trabajos,CANTIDADTRABAJOS,autos,CANTIDADAUTOS,servicios);
            f_i_continuar();
            break;

        case 'i':
            limpiar();
            mostrarTrabajos(trabajos,CANTIDADTRABAJOS,autos,servicios,CANTIDADSERVICIOS);
            f_i_continuar();
            break;

        case 'x':
            limpiar();
            break;

        default :
            limpiar();
            printf("**Opcion Invalida**\n");
            f_i_continuar();
            break;
        } //switch
    }
    while (seleccion != 'x');    // do

    printf("Chau");

    return 0;
}
