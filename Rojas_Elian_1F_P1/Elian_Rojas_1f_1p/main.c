#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "InputElian.h"
#define CANTIDADAUTORES 10
#define CANTIDADLIBROS 10
#define CANTIDADSOCIOS 20
#define CANTIDADPRESTAMOS 20


int main()
{
    //Variables//
    ESTRUCTURA_Autores autores[CANTIDADAUTORES];
    ESTRUCTURA_Libros libros[CANTIDADLIBROS];
    ESTRUCTURA_Prestamos prestamos[CANTIDADPRESTAMOS];
    ESTRUCTURA_Socios socios[CANTIDADSOCIOS];

    int auxId=0 , opcion , seleccion , flagVacio=0;

    //INICIALIZACION//
    iniciarIncrementalPrestamos(prestamos,CANTIDADPRESTAMOS);
    iniciarIncrementalSocios(socios,CANTIDADSOCIOS);

    iniciarVacioPrestamos(prestamos,CANTIDADPRESTAMOS,1);
    iniciarVacioSocios(socios,CANTIDADSOCIOS,1);

    //HARDCODE//

    hardCodeAutores(autores);
    hardCodeLibros(libros);

    //MENU//

    do{
        f_i_PedirIntEntre(&opcion , 1 , 8 , "**Menu**\n"
                          "Ingrese 1 para dar de Alta un socio -\n"
                          "Ingrese 2 para Modificar los datos de un socio -\n"
                          "Ingrese 3 para dar de baja un socio -\n"
                          "Ingrese 4 para listar los socios ordenados por Apellido y Nombre -\n"
                          "Ingrese 5 para listar los libros cargados-\n"
                          "Ingrese 6 para listar los autores cargados-\n"
                          "Ingrese 7 para dar de alta un prestamo-\n"
                          "Ingrese 8 para Salir -\n");

        switch (opcion){

        case 1:

            auxId = buscarPrimerIdVacioSocios(socios,CANTIDADSOCIOS,1);

            if ( auxId != -1 ){

            cargarSocio(socios , auxId);

            } else {

            printf("\nNo queda espacio\n");

            break;
            };

        break;

        case 2 :
            f_i_PedirIntEntre(&auxId , 1  , CANTIDADSOCIOS , "\nIngrese el ID del Socio a modificar:\n");

            auxId = buscarPorIdSocio(socios,CANTIDADSOCIOS,auxId);

            if (auxId != -1){
                    mostrarUnSocio(socios,auxId);
                    seleccion = f_i_SioNo("\nEs este el empleado a modificar?\n");
                if (seleccion == 1){
                modificarSocio(socios , auxId);
                break;
                } else {
                printf("\nNo se modifico el socio\n");
                break;
                }

            }

        case 3:
                flagVacio = (estaTodoVacioSocios(socios,CANTIDADSOCIOS);

                if (flagVacio == 0){

                f_i_PedirIntEntre(&auxId ,1, CANTIDADSOCIOS,"\nIngrese el ID del empleado a dar de baja:\n");

                auxId = buscarPorIdSocio(socios , CANTIDADSOCIOS , auxId);

                if (auxId != -1){
                mostrarUnSocio(socios,auxId);
                seleccion = f_i_SioNo("\nEs este el socio a dar de baja?\n");
                    if (seleccion == 1 ){
                        socios[auxId].isEmpty = 1;
                        printf("\nEl socio fue eliminado correctamente\n");
                        break;
                    }else{
                    printf("\nEl socio no fue eliminado\n");
                    break;
                    };
                }else{
                printf("\nNo hay socios cargados\n");
                break;

                };



            break;


        case 4:
            flagVacio = estaTodoVacioSocios(socios,CANTIDADSOCIOS);

            if(flagVacio == 0){
            mostrarTodosSocios(socios , CANTIDADSOCIOS);
            break;
            } else {
            printf("\nNo hay ningun socio cargado\n");
            break;
            };

        case 5: mostrarLibros(libros , CANTIDADLIBROS );

        break;

        case 6: mostrarAutores(autores , CANTIDADAUTORES );

        break;

        case 8: printf("Adios");
        break;

        default : printf("Error");
        break;
        };

        } while (opcion != 8);


return 0;

}
