#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "InputElian.h"
#define CANTIDADAUTORES 10
#define CANTIDADLIBROS 10
#define CANTIDADSOCIOS 100
#define CANTIDADPRESTAMOS 20


int main() {
    //Variables//
    ESTRUCTURA_Autores autores[CANTIDADAUTORES];
    ESTRUCTURA_Libros libros[CANTIDADLIBROS];
    ESTRUCTURA_Prestamos prestamos[CANTIDADPRESTAMOS];
    ESTRUCTURA_Socios socios [CANTIDADSOCIOS];
    str_Fecha auxFecha;

    int auxId = 0 , opcion , seleccion , flagVacio = 0 , falloCarga = 0;

    //INICIALIZACION//
    iniciarIncrementalPrestamos(prestamos,CANTIDADPRESTAMOS);
    iniciarIncrementalSocios(socios,CANTIDADSOCIOS);

    iniciarVacioPrestamos(prestamos,CANTIDADPRESTAMOS,1);
    iniciarVacioSocios(socios,CANTIDADSOCIOS,1);

    //HARDCODE//

    hardCodeAutores(autores);
    hardCodeLibros(libros);
    hardCodeSocios(socios);
    hardCodePrestamos(prestamos);

    //MENU//

    do{
        f_i_PedirIntEntre(&opcion , 1 , 19 , "**Menu**\n"
                          "Ingrese 1 para dar de Alta un socio -\n"
                          "Ingrese 2 para Modificar los datos de un socio -\n"
                          "Ingrese 3 para dar de baja un socio -\n"
                          "Ingrese 4 para listar los socios ordenados por Apellido y Nombre -\n"
                          "Ingrese 5 para listar los libros cargados-\n"
                          "Ingrese 6 para listar los autores cargados-\n"
                          "Ingrese 7 para dar de alta un prestamo-\n"
                          "Ingrese 8 para listar el total general y promedio diario\n"
                          "Ingrese 9 para informar dias que no superan promedio\n"
                          "Ingrese 10 para listar socios que solicitaron un libro determinado\n"
                          "Ingrese 11 para listar los libros prestados a un socio determinado\n"
                          "Ingrese 12 para listar los libros menos solicitados en prestamos\n"
                          "Ingrese 13 para listar socios que realizaron mas de un prestamo\n"
                          "Ingrese 14 para listar libros que se prestaron en una fecha dererminada\n"
                          "Ingrese 15 para listar socios que hicieron un prestamo en una fecha det\n"
                          "Ingrese 16 para listar los libros por nombre de manera descendente\n"
                          "Ingrese 17 para listar los socios por apellido de manera ascendente\n"
                          "Ingrese 18 para listar los prestamos cargados-\n"
                          "\nIngrese 19 para Salir -\n");

        switch (opcion){

        case 1:
            limpiar();

            auxId = buscarPrimerIdVacioSocios(socios,CANTIDADSOCIOS,1);

            if ( auxId != -1 ){
                cargarSocio(socios , auxId);
                limpiar();
            } else {
            printf("\nNo queda espacio\n");
            f_i_continuar();
            limpiar();
            break;
            };

        case 2 :
            limpiar();

            flagVacio = estaTodoVacioSocios(socios,CANTIDADSOCIOS);

            if(flagVacio == 0){

                mostrarTodosSocios(socios,CANTIDADSOCIOS);

                f_i_PedirIntEntre(&auxId , 1  , CANTIDADSOCIOS , "\nIngrese el ID del Socio a modificar:\n");

                auxId = buscarPorIdSocio(socios,CANTIDADSOCIOS,auxId);

                if (auxId != -1){
                    limpiar();
                    mostrarUnSocio( socios , auxId );
                    seleccion = f_i_SioNo("\nEs este el Socio a modificar?\n");

                    if (seleccion == 1){

                        limpiar();
                        modificarSocio(socios , auxId);
                        f_i_continuar();
                        limpiar();

                    } else {
                    printf("\nNo se modifico el socio\n");
                    f_i_continuar();
                    limpiar();
                    }
                } else {
                printf("\nEse id no corresponde a ningun socio activo\n");
                f_i_continuar();
                limpiar();
                }

            } else {
                printf("\nNo hay ningun socio cargado en el sistema\n");
                f_i_continuar();
                limpiar();
            };
            break;

        case 3:
                limpiar();

                flagVacio = (estaTodoVacioSocios( socios , CANTIDADSOCIOS ));

                if (flagVacio == 0){
                    f_i_PedirIntEntre( &auxId , 1 , CANTIDADSOCIOS , "\nIngrese el ID del empleado a dar de baja:\n" );
                    auxId = buscarPorIdSocio(socios , CANTIDADSOCIOS , auxId);

                    if (auxId != -1){
                        mostrarUnSocio( socios , auxId );
                        seleccion = f_i_SioNo("\nEs este el socio a dar de baja?\n");

                        if (seleccion == 1 ){
                            socios[auxId].isEmpty = 1;
                            printf("\nEl socio fue eliminado correctamente\n");
                            f_i_continuar();
                            limpiar();
                            break;

                        } else {
                        printf("\nEl socio no fue eliminado\n");
                        f_i_continuar();
                        limpiar();
                        break;

                        };

                    } else {
                    printf("\nNo se encontro ningun socio con ese id\n");
                    f_i_continuar();
                    limpiar();
                    break;

                    };

                } else {
                printf("\nNo hay socios cargados\n");
                f_i_continuar();
                limpiar();
                break;

                };

        case 4:
                limpiar();

                flagVacio = estaTodoVacioSocios( socios , CANTIDADSOCIOS );

                if(flagVacio == 0){
                    mostrarTodosSocios( socios , CANTIDADSOCIOS );
                    f_i_continuar();
                    limpiar();
                break;

                } else {
                printf("\nNo hay ningun socio cargado\n");
                f_i_continuar();
                limpiar();
                break;

                };

        case 5:
                limpiar();
                mostrarLibros( libros , autores , CANTIDADLIBROS );
                f_i_continuar();
                limpiar();
                break;

        case 6:
                limpiar();
                mostrarAutores( autores , CANTIDADAUTORES );
                f_i_continuar();
                limpiar();
                break;

        case 7:
            limpiar();
            falloCarga = 0;
            auxId = buscarPrimerIdVaciosPrestamos( prestamos , CANTIDADPRESTAMOS , 1 );

            if ( auxId != -1 ){

                falloCarga = cargarPrestamo ( prestamos , auxId , libros , CANTIDADLIBROS , socios , CANTIDADSOCIOS, autores );

                if (falloCarga == -1){
                    printf("\nNo se cargo el prestamo\n");
                    f_i_continuar();
                    limpiar();
                    break;
                } else {
                    printf("\nEl prestamo se cargo con exito\n");
                    f_i_continuar();
                    limpiar();
                    break;

                }
            } else {
            printf("\nNo queda espacio\n");
            f_i_continuar();
            limpiar();
            break;
            };

        case 8:
                sacarTotalYPromedio(prestamos,CANTIDADPRESTAMOS);
                f_i_continuar();
                limpiar();
                break;

        case 9://no
            break;

        case 10:
                f_i_PedirIntEntre(&auxId,1,CANTIDADLIBROS,"\nIngrese el codigo del libro:\n");

                flagVacio = buscarIdLibro(libros,CANTIDADLIBROS,auxId);

                if (flagVacio != -1){
                    listarSociosPorPrestamosLibro(prestamos,CANTIDADPRESTAMOS,socios,auxId);
                    f_i_continuar();
                    limpiar();
                    break;
                } else {
                    printf("\nNo se encontro el libro\n");
                    f_i_continuar();
                    limpiar();
                    break;
                };
        case 11:

               f_i_PedirIntEntre(&auxId,1,CANTIDADSOCIOS,"\nIngrese el codigo del socio:\n");
                flagVacio = buscarPorIdSocio(socios,CANTIDADSOCIOS,auxId);

                if (flagVacio != -1){
                    listarLibrosPorPrestamodSocio (prestamos,CANTIDADPRESTAMOS,libros,auxId);

                    f_i_continuar();
                    limpiar();
                    break;
                } else {
                    printf("\nNo se encontro el libro\n");
                    f_i_continuar();
                    limpiar();
                    break;
                };

        case 12://no
             break;

        case 13://no
            break;
        case 14:

            limpiar ();

            f_i_PedirIntEntre(&auxFecha.dia, 1 , 31 , "\nIngrese el dia de prestamo:");

            f_i_PedirIntEntre(&auxFecha.mes, 1 , 12 , "\nIngrese el mes de prestamo (1 al 12):");

            f_i_PedirIntEntre(&auxFecha.anyo, 1900 , 2020 , "\nIngrese el anyo de prestamo:");

            mostrarLibrosPorFechaPrestamo(prestamos,CANTIDADPRESTAMOS,auxFecha,libros);

            f_i_continuar();

             break;

        case 15:

            limpiar ();

            f_i_PedirIntEntre(&auxFecha.dia, 1 , 31 , "\nIngrese el dia de prestamo:");

            f_i_PedirIntEntre(&auxFecha.mes, 1 , 12 , "\nIngrese el mes de prestamo (1 al 12):");

            f_i_PedirIntEntre(&auxFecha.anyo, 1900 , 2020 , "\nIngrese el anyo de prestamo:");

            mostrarSociosPorFecha(prestamos,CANTIDADPRESTAMOS,auxFecha,socios);

            f_i_continuar();

            break;
        case 16:
                limpiar();
                mostrarLibrosBurbujeo(libros , CANTIDADLIBROS);
                f_i_continuar();
                limpiar();

                break;
        case 17:
                limpiar();
                mostrarSociosInsercion(socios,CANTIDADSOCIOS);
                f_i_continuar();
                limpiar();
                break;

        case 18:
                limpiar();
                flagVacio = estaTodoVacioPrestamos( prestamos , CANTIDADPRESTAMOS );

                if(flagVacio == 0){
                    mostrarPrestamos(  prestamos , CANTIDADPRESTAMOS , socios , libros );
                    f_i_continuar();
                    limpiar();
                    break;

                } else {
                printf("\nNo hay ningun prestamo cargado\n");
                f_i_continuar();
                limpiar();
                break;
                }

        case 19:
                limpiar();
                printf("Adios");
                break;

        default :
                printf("Error");
                break;

        }; //switch

    }while (opcion != 19); // do

    return 0;
}
