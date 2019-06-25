#include <stdio.h>
#include <stdlib.h>
#include "filesDominio.h"
#include "inputElian.h"
#include "dominio.h"
#include "linkedList.h"


int main()
{
    int option;
    files_CreateFileText("datos.csv");
    files_CreateFileText("auto.csv");
    files_CreateFileText("moto.csv");
    LinkedList* listaDominios;
    listaDominios = ll_newLinkedList();
    LinkedList* listaMotos = NULL;
    LinkedList* listaAutos = NULL;
    int chargedText = 0;
    int setted = 0;

    char nombreArchivo[31];

    do
    {
        limpiar();
        printf("1-Cargar los archivos desde datos.csv\n"
               "2-Setear tipos\n"
               "3-Filtrar motos y autos en 2 listas\n"
               "4-Generar archivos auto.csv y moto.csv\n"
               "5-Mostrar datos cargados\n"
               "6-Salir\n");

        f_i_PedirIntEntre(&option,1,6,"");

        switch(option)
        {
        case 1:
            f_i_PedirStringAlfaNumerico(nombreArchivo,31,"Ingrese el nombre del archivo");

            if(listaDominios != NULL)
            {
                if(files_LoadFromText(nombreArchivo,listaDominios) != 0)
                {
                    printf("Se cargaron todos los datos\n");
                    chargedText = 1;
                }
                else
                {
                    printf("No se pudieron cargar los datos\n");
                }
            }
            else
            {
                printf("Error al crear lista");
            }
            //files_LoadFromText(nombreArchivo,listaDominios);
            f_i_continuar();
            break;

        case 2:
            if(chargedText != 0)
            {
            if(ll_map(listaDominios,dominio_setMotoAuto) != 0)
                {
                    printf("Se setearon los tipos\n");
                    setted = 1;
                }
                else
                {
                    printf("No se pudieron setear los tipos\n");
                }
            }
            else
            {
                printf("Primero hay que cargar los datos\n");
            }
            f_i_continuar();
            //ll_map(listaDominios,dominio_setMotoAuto);
            break;

        case 3:
            if(chargedText != 0 && setted != 0)
            {
                listaMotos = ll_filter(listaDominios,dominio_subListaMotos);
                listaAutos = ll_filter(listaDominios,dominio_subListaAutos);

                if(listaAutos!=NULL || listaMotos!=NULL)
                {
                    printf("Se filtraron las listas\n");
                }
                else
                {
                    printf("No se filtraron las listas \n");
                }
            } else
            {
                printf("Primero hay que cargar y setear los datos\n");
            }
            f_i_continuar();
            break;

        case 4:
            files_SaveAsText("auto.csv",listaAutos);
            files_SaveAsText("moto.csv",listaMotos);
            printf("Se guardaron los datos");
            f_i_continuar();
            break;

        case 5:
            controller_ListObjectA(listaDominios);
            f_i_continuar();
            break;

        default:
            break;
        }


    }while (option !=6);


    return 0;
}
