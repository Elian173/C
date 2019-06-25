#include <stdio.h>
#include <stdlib.h>
#include "controller_Elian.h"
#include "linkedList_Elian.h"
#include "objectA_Elian.h"
#include "files_Elian.h"
#include "input_Elian.h"
#include "string.h"
//_____________________________________________________________LISTA_________________________________________________
//Listar objectA
int controller_ListObjectA(LinkedList* linkedList)
{
    STR_ObjectA *ptr_ObjectA;
    int value = 0 ;
    int i;

    ptr_ObjectA = objectA_new();

    if(ptr_ObjectA != NULL && linkedList != NULL && ll_len(linkedList) > 0)
    {
        printf("Id Nombre          S  Edad  Email Telefono\n");
        for(i = 0; i < ll_len(linkedList) ; i++)
        {
            ptr_ObjectA = (STR_ObjectA*) ll_get(linkedList,i);

            if(ptr_ObjectA != NULL && ptr_ObjectA->id != -1)
            {
                objectA_print(ptr_ObjectA);
            }
        }
        value = 1;
    }
    else
    {
        printf("La lista esta vacia.\n");
    }
    return value;
}

//__________________________________________ordenar______________________________________

int controller_sortObjectA(LinkedList* linkedList)
{
    int value = 0;
    int opcion;
    int criterio;
    if(linkedList != NULL)
    {
        opcion = menuOrden();

        switch (opcion)
        {
        case 1 :
            criterio = menuCriterio();
            ll_sort(linkedList,objectA_orderBy_Id,criterio);
            value = 1;
            break;
        case 2 :
            criterio = menuCriterio();
            ll_sort(linkedList,objectA_orderBy_Name,criterio);
            value = 1;
            break;
        case 3 :
            criterio = menuCriterio();
             //ll_sort(linkedList,objectA_orderBy_ ,criterio);
            value = 1;
            break;
        case 4 :
            criterio = menuCriterio();
            //ll_sort(linkedList,objectA_orderBy_ ,criterio);
            value = 1;
            break;
        case 5:
            value = 0;
            break;
        }
    }
    return value;
}

//________________________________________Altas bajas mod

/*
int controller_AddObjectA(LinkedList* linkedList)
{
    STR_ObjectA* ptr_NewObjectA;
    ptr_NewObjectA = employee_new();
    STR_ObjectA* ptr_UltimoEmpleado;

    int lastId;
    int devuelve = 0;
    char *buffer = (char*) malloc(sizeof(char)*31);

    if(pArrayListEmployee != NULL && ptr_NewObjectA != NULL)
    {
        //Genero un id que vale 1 mas que el mas grande asi no se repite

        //ordeno por id para que el id mas grande quede a lo ultimo
        ll_sort(pArrayListEmployee,empleado_ordenarPorId,0);

        //tomo el ultimo empleado , que tiene el id mas grande
        ptr_UltimoEmpleado = ll_get(pArrayListEmployee,ll_len(pArrayListEmployee)-1);

        //agarro su id
        employee_getId(ptr_UltimoEmpleado,&lastId);

        //le sumo 1 a ese id y se lo asigno al nuevo empleado
        employee_setId(ptr_NewObjectA,lastId + 1);

        // pido los demas datos

        f_i_PedirNombre(buffer,31,"Ingrese el nombre del empleado");
        employee_setNombre(ptr_NewObjectA, buffer);

        f_i_PedirStringSoloNumeros(buffer,4,"Ingrese las horas trabajadas del empleado:");
        employee_setHorasTrabajadas(ptr_NewObjectA, atoi(buffer));

        f_i_PedirStringSoloNumeros(buffer,6,"Ingrese el sueldo del empleado:");
        employee_setSueldo(ptr_NewObjectA,atoi(buffer));

        //lo agrego al final de la lista
        if(ll_add(pArrayListEmployee, ptr_NewObjectA) == 0)
        {
            devuelve = 1;
        }
    }
    else
    {
        printf("Error, no se puede cargar el empleado\n");
    }

    free (buffer);

    return devuelve;
}
*/
