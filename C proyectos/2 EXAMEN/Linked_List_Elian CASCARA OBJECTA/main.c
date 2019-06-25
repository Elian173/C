#include <stdio.h>
#include <stdlib.h>
#include "input_Elian.h"
#include "objectA_Elian.h"
#include "files_Elian.h"
#include "linkedList_Elian.h"
#include "controller_Elian.h"

/****************************************************
    Menu:
 -   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 -   2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 -   3. Alta de empleado
 -   4. Modificar datos de empleado
 -   5. Baja de empleado
 -   6. Listar empleados
 -   7. Ordenar empleados
 -   8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 -   9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 -   10. Salir
*****************************************************/

#define ARCHIVOT "dataa.csv"//dataaTEST.csv
#define ARCHIVOB "bin.csv"

int main()
{
    int option;
    int chargedText = 0;
    int chargedBinary = 0;
    int saved = 1;
    int opcC;


    LinkedList* listaObjectA;
    listaObjectA = ll_newLinkedList();
    files_CreateFileText(ARCHIVOT);

    //MENU
    do
    {
        limpiar();

        printf("1- carga 2 lista 3 savetext 4 ordenarNombre,  5 ordenarid:\n");

        f_i_PedirIntEntre(&option,1,10,"");

        switch(option)
        {
        case 1:
            limpiar();
            f_i_PedirIntEntre(&opcC,1,2,"1 Texto\n2Binario\n");

            if(opcC == 1)
            {

                if(listaObjectA != NULL)
                {
                    if(files_LoadFromText(ARCHIVOT,listaObjectA) != 0)
                    {
                        printf("Se cargaron todos los datos desde texto\n");
                        chargedText = 1;
                    }
                    else
                    {
                        printf("No se pudieron cargar los datos\n");
                    }
                }
                else
                {
                    printf("Error en la lista\n");
                }
                f_i_continuar();
            }
            else
            {

                if(listaObjectA != NULL)
                {
                    if(files_LoadFromBinary(ARCHIVOB,listaObjectA) != 0)
                    {
                        printf("Se cargaron todos los datos desde binario\n");
                        chargedText = 1;
                    }
                    else
                    {
                        printf("No se pudieron cargar los datos\n");
                    }
                }
                else
                {
                    printf("Error en la lista\n");
                }
                f_i_continuar();
            }

            break;
        case 2:
            limpiar();

            controller_ListObjectA(listaObjectA);

            f_i_continuar();
            break;

        case 3:
            limpiar();
            f_i_PedirIntEntre(&opcC,1,2,"1SaveTexto\n2SaveBinario");
            if(opcC == 1)
            {
                files_SaveAsText(ARCHIVOT,listaObjectA);
            }
            else
            {
                files_SaveAsBinary(ARCHIVOB,listaObjectA);
            }
            f_i_continuar();
            break;

        case 4:
            limpiar();
            ll_sort(listaObjectA,objectA_orderBy_Name,menuCriterio());
            f_i_continuar();
            break;
        case 5:
            limpiar();
            ll_sort(listaObjectA,objectA_orderBy_Id,menuCriterio());
            f_i_continuar();
            break;
        case 6:
            break;

        case 10:
            limpiar();

            if (saved == 0)
            {
                if(f_i_SioNo("Hay datos sin guardar , salir de todas formas?") == 0)
                {
                    option = 0;
                }
                else
                {
                    ll_deleteLinkedList(listaObjectA);
                }
            }
            break;

        default:
            printf(":-)");
            break;
        }
    }
    while(option != 10);

    return 0;

}
