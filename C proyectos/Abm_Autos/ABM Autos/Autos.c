#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "Autos.h"

//hardcode//


void hardcodearMarca (STR_Marca aCargar [])
{

    int i;
    STR_Marca aux[]=
    {

        {1000,"Renault"},
        {1001,"Fiat"},
        {1002,"Ford"},
        {1003, "Chevrolet"},
        {1004,"Peugeot"}

    };


    for( i=0 ; i < 5 ; i++)
    {
        aCargar[i] = aux[i];
    }
}

void hardcodearColor (STR_Color aCargar[])
{
    int i;

    STR_Color aux[] =
    {

        {5000,"Negro"},
        {5001,"Blanco"},
        {5002,"Gris"},
        {5003, "Rojo"},
        {5004,"Azul"}

    };


    for(i=0 ; i < 5 ; i++)
    {
        aCargar[i] = aux[i];
    }

}

void hardcodearServicio(STR_Servicio aCargar[])
{
    int i;

    STR_Servicio aux[4] =
    {

        {20000,"Lavado",250},
        {20001,"Pulido",300},
        {20002,"Encerado",400},
        {20003, "Completo",600},

    };


    for(i=0 ; i < 4 ; i++)
    {
        aCargar[i] = aux[i];
    }

}


void hardcodeAutos (STR_Auto aCargar[])
{
    int i;

    STR_Auto aux[] =
    {

        {1,"XAX 288",1000,5000,1990,0},
        {2,"JOJ 220",1001,5001,1991,0},
        {3,"LOE 400",1002,5002,1992,0},
        {4,"WQA 544",1003,5003,1993,0},
        {5,"SSE 230",1004,5004,1994,0},
        {6,"LOR 550",1004,5002,1995,0},
        {7,"FFE 920",1004,5002,1996,0},
        {8,"XXA 010",1003,5002,1997,0},
        {9,"OKJ 662",1001,5003,1998,0},
        {10,"APE 555",1001,5000,1999,0},
    };



    for(i=0 ; i < 10 ; i++)
    {
        aCargar[i] = aux[i];
    }
}

void hardcodeTrabajos (STR_Trabajo aCargar[])
{
    int i;
    str_Fecha fe = { 1,2,3000 };

    STR_Trabajo aux[]=
    {
        {1,"JOJ 220",20000,fe,0},
        {2,"BIG 101",20001,fe,0},
        {3,"LOE 400",20001,fe,0},
        {4,"WQA 544",20001,fe,0},
        {5,"SSE 230",20001,fe,0},
        {6,"LOR 550",20003,fe,0},
        {7,"FFE 920",20001,fe,0},
        {8,"XXA 010",20000,fe,0},
        {9,"OKJ 662",20000,fe,0},
        {10,"APE 555",20001,fe,0}
    };


    for(i=0 ; i < 10 ; i++)
    {
        aCargar[i] = aux[i];
    }
}

//inicia//

void iniciarAutosIsEmpty (STR_Auto iniciando[],int cantidadElementos,int numeroQueSeAsigna)
{
    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }
}

void inciarIncrementalIdAutos (STR_Auto iniciando[], int cantidadElementos)
{

    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i;
    }
}



void iniciarTrabajosIsEmpty(STR_Trabajo iniciando[], int cantidadElementos, int numeroQueSeAsigna)
{

    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }
}


void inciarIncrementalIdTrabajos (STR_Trabajo iniciando[], int cantidadElementos)
{

    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i;
    }
}



//ALTA

void darDeAltaAuto(STR_Auto losAutos[],int cantidadAutos)
{

    int i;
    int index = -2;
    int aux, invalido;
    char auxPatente[10];

    //Busco el primer lugar vacio y saco su id ( que seria la posicion en el array)//

    for (i=0 ; i<cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty == 1 )
        {

            index = losAutos[i].id;

            break;

        };
    }

    //Si no hay lugar sale esto//
    if (index == -2)
    {
        printf("\n**No queda lugar**");
        return;
    };

    //Si hay lugar se empieza a cargar esto//

    //Se ocupa el lugar.

    losAutos[index].isEmpty = 0;

    //pido la patente

    f_i_PedirPatenteVieja(auxPatente,"Ingrese la patente del auto:");

    //veo si la patente ya existe//

    invalido = 0;

    for (i=0; i<cantidadAutos; i++)
    {

        if(strcmp(auxPatente,losAutos[index].patente)==0)
        {
            invalido = 1;
        }

    }

    //Si ya existe
    if (invalido == 1)
    {
        printf("\nEsa patente ya fue registrada,pruebe modificandola o dandola de baja\n");
        return;
    };

    //Si NO existe la copio al original y continuo

    strcpy(losAutos[index].patente,auxPatente);

    //Pido la marca

    printf("Ingrese la marca del auto\n"
           "1-Renault\n"
           "2-Fiat\n"
           "3-Ford\n"
           "4-Chevrolet\n"
           "5-Peugeot\n");

    f_i_PedirIntEntre(&aux,1,5,"Opcion:");

    //Sumo 999 porque los id de las marcas incian en 1000 , para que el usuario no tenga que escribir el "1000"
    aux = (aux -1 ) + 1000 ;

    losAutos[index].idMarca = aux;

    //pido color

    printf("Ingrese el color del auto\n"
           "1-Negro\n"
           "2-Blanco\n"
           "3-Gris\n"
           "4-Rojo\n"
           "5-Azul\n");

    f_i_PedirIntEntre(&aux,1,5,"Opcion:");

    //Sumo 5000 porque los id de los colores incian en 5000 , para que el usuario no tenga que escribir el "5000"
    aux = (aux -1) + 5000 ;
    losAutos[index].idColor = aux;

    //pido el modelo

    f_i_PedirIntEntre(&aux, 1900, 2020,"Ingrese el modelo del auto:");

    losAutos[index].modelo = aux;

    printf("Modelo cargado correctamente");

    return;
}

void altaTrabajo (STR_Trabajo trabajos[],int cantidadTrabajos, STR_Auto autos[], int cantidadAutos,STR_Servicio servicios[])
{

    STR_Trabajo auxTrabajo;
    str_Fecha auxfecha;

    int aux, i ;
    char auxPatente[10];
    int invalido;
    int index;

    //Veo si hay autos cargados//

    invalido = 1;

    for (i=0 ; i< cantidadAutos ; i++)
    {
        if (autos[i].isEmpty==0)
        {
            invalido = 0;
        };
    };
    //Si NO hay autos cargados
    if (invalido == 1)  //significa que no hay autos cargados
    {
        printf("\nNo hay autos cargados , no se puede cargar un trabajo\n");
        return;
    };

    //Si SI hay autos cargados
    //Busco primer index donde guardar el trabajo
    for (i=0 ; i<cantidadTrabajos ; i++)
    {
        if (trabajos[i].isEmpty == 1 )
        {
            index = trabajos[i].id;  // Se que los id equivalen a los index porque inicie incrementalmente los id desde 0
            break;
        };
    }
    //Si no hay lugar sale esto//
    if (index == -2)
    {
        printf("\n**No queda lugar**");
        return;
    };


    //Muestro las patentes cargadas//
    printf("Pantentes cargadas");

    for (i=0 ; i<cantidadAutos ; i++)
    {
        if (autos[i].isEmpty==0)
        {
            printf("%-10s\n",autos[i].patente);
        }
    }



    //Pido una patente y valido que exista//

    fflush(stdin);
    f_i_PedirPatenteVieja(auxPatente,"\nIngrese la patente del vehiculo:");
    invalido = 1;

    for (i=0 ; i<cantidadAutos ; i++)
    {
        if(strcmp(autos[i].patente,auxPatente)==0)
        {
            invalido = 0;
            break;
        }
    }
    //Si NO existe//
    if ( invalido == 1)
    {
        printf("\nEsa patente no esta registrada.No se puede cargar el trabajo\n");
        return;
    };


    //Si SI existe->//

    //pido fecha

    pedirFecha(&auxfecha.dia,&auxfecha.mes,&auxfecha.anyo,"Se realizo el trabajo","Se realizo el trabajo","Se realizo el trabajo");

    auxTrabajo.fecha = auxfecha;

    //pido servicio

    printf("\nIngrese el servicio que se le realizo al auto\n");
    printf("1-Lavado\n"
           "2-Pulido\n"
           "3-Encerado\n"
           "4-Completo\n");

    f_i_PedirIntEntre(&aux,1,4,"Opcion:");

    //Sumo 19999 porque los ID de los servicios empiezan en 20000 , para que el usuario no tenga que ingresar 20000

    aux = (aux-1)+20000;
    auxTrabajo.idServicio = aux;


    //copio los valores del auxiliar al original (array trabajos posicion index) , pongo ocupado el index//

    strcpy(auxTrabajo.patente,auxPatente);

    trabajos[index] = auxTrabajo ;
    trabajos[index].isEmpty = 0;

    printf("\nTrabajo cargado correctamente ");

    return;

}


//BAJA
void dardeBajaAuto(STR_Auto losAutos[], int cantidadAutos)
{

    char auxPatente [10];
    int opcion;
    int i, invalido;


//Veo si hay autos cargados//

    invalido = 1;

    for (i=0 ; i< cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty==0)
        {
            invalido = 0;
        };
    };

    //si NO hay autos
    if (invalido == 1)  //significa que no hay autos cargados
    {
        printf("\nNo hay autos cargados\n");
        return;
    };

    //Si SI hay autos//
    //Muestro las patentes cargadas//
    printf("Pantentes cargadas");

    for (i=0 ; i<cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty==0)
        {
            printf("%-10s\n",losAutos[i].patente);
        }
    }
    //Pido que elija una patente a modificar

    fflush(stdin);

    f_i_PedirPatenteVieja(auxPatente,"Ingrese la patente del auto:");

    for ( i = 0 ; i < cantidadAutos ; i ++ )
    {
        //Si ingresa una patente valida
        if (strcmp(losAutos[i].patente,auxPatente)==0 )
        {

            printf("\nSeguro que quiere dar de baja el auto %s?",losAutos[i].patente);
            opcion = f_i_SioNo("");

            if (opcion == 1 )
            {
                losAutos[i].isEmpty = 1;
                printf("\nSe dio de baja el auto");
            }
            else
            {
                printf("\nNo se dio de baja el auto");
            }
            return;
        }

    };
    //Si ingresa una patente invalida
    printf("\nNo se encontro el auto");
    return;
}


//MODIFICAR

void modificarAuto (STR_Auto losAutos[],int cantidadAutos)
{

    char auxPatente[10];
    int aux,i,invalido;

    //Veo si hay autos cargados//

    invalido = 1;

    for (i=0 ; i< cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty==0)
        {
            invalido = 0;
        };
    };

    //si NO hay autos
    if (invalido == 1)  //significa que no hay autos cargados
    {
        printf("\nNo hay autos cargados\n");
        return;
    };

    //Si SI hay autos//
    //Muestro las patentes cargadas//

    printf("Pantentes cargadas\n");

    for (i=0 ; i<cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty==0)
        {
            printf("%-10s\n",losAutos[i].patente);
        }
    }
    //Pido que elija una patente a modificar
    fflush(stdin);
    f_i_PedirPatenteVieja(auxPatente,"Ingrese la patente del auto , o una patente no cargada para salir:");

    for ( i = 0 ; i < cantidadAutos ; i ++ )
    {
        //Si ingreso una patente que existe ->
        if (strcmp(losAutos[i].patente,auxPatente) == 0 && losAutos[i].isEmpty == 0 )
        {
            printf("\nIngrese el color del auto\n"
                   "1-Negro\n"
                   "2-Blanco\n"
                   "3-Gris\n"
                   "4-Rojo\n"
                   "5-Azul\n");

            f_i_PedirIntEntre(&aux,1,5,"Opcion:");
            aux = (aux -1) + 5000 ;
            losAutos[i].idColor = aux;

            f_i_PedirIntEntre(&aux, 1900, 2020,"Ingrese el modelo del auto:");
            losAutos[i].modelo = aux;

            printf("\nAuto modificado correctamente\n");

            return;
        }

    };
    //Si ingreso una patente que NO existe ->
    printf("\nNo se encontro el auto");
    return;
}



//mostrar //

void mostrarAutos (STR_Auto losAutos[], STR_Color colores[], STR_Marca marcas [], int cantidadAutos)
{

    int i,invalido;

    //Veo si hay autos cargados//

    invalido = 1;

    for (i=0 ; i< cantidadAutos ; i++)
    {
        if (losAutos[i].isEmpty==0)
        {
            invalido = 0;
        };
    };

    //si NO hay autos
    if (invalido == 1)  //significa que no hay autos cargados
    {
        printf("\nNo hay autos cargados\n");
        return;
    };

    //Si SI hay autos//
    //Muestro los autos cargados//

    printf("Autos:\n");
    printf("Patente:         Marca:   Color:    Modelo:\n\n");

    for(i=0; i<cantidadAutos; i++)
    {

        if (losAutos[i].isEmpty != 1)
        {

            printf("%10s - %10s - %10s - %4d\n",losAutos[i].patente, marcas[losAutos[i].idMarca - 1000].descripcion,
                   colores[losAutos[i].idColor-5000].nombreColor, losAutos[i].modelo);
            ;
        };
    }

    return;
}


void mostrarMarcas (STR_Marca marca[], int cantidadElementos)
{
    int i;

    printf("Marcas:\n");
    printf("Codigo: Descripcion\n\n");

    for(i=0; i<cantidadElementos; i++)
    {
        printf("%4d %s\n",marca[i].id,marca[i].descripcion);
    };
    return;
}


void mostrarColores (STR_Color color[], int cantidadElementos)
{

    int i;

    printf("Colores:\n");
    printf("Codigo: Descripcion\n\n");

    for(i=0; i<cantidadElementos; i++)
    {
        printf("%4d %s\n",color[i].id,color[i].nombreColor);
    };

    return;
}

void mostrarServicios (STR_Servicio servicio[], int cantidadElementos)
{
    int i;

    printf("Servicios:\n");
    printf("Codigo: Precio: Descripcion:\n\n");

    for(i=0; i<cantidadElementos; i++)
    {
        printf("%4d %4d %s\n",servicio[i].id,servicio[i].precio,servicio[i].descripcion);
    };

    return;
}


void mostrarTrabajos (STR_Trabajo trabajos[],int cantidadTrabajos, STR_Auto autos[],STR_Servicio servicios[], int cantidadServicios)
{

    int i,j,indexServ;

    printf("-----Servicios----\n");
    printf("Patente : Servicio: Precio:\n\n");

    //recorro array de trabajos
    for(i=0; i < cantidadTrabajos; i++)
    {
        // busco los index de servicio , en base al id guardado en array trabajo , para obtener el precio y la descripcion
        for(j=0;j<cantidadServicios;j++){

            if (trabajos[i].idServicio == servicios[j].id){
                indexServ = j;
            }
        }


            //Imprimo los datos

            if (trabajos[i].isEmpty == 0)
            {

            printf("%10s-%10s-%4d\n",trabajos[i].patente, servicios[indexServ].descripcion, servicios[indexServ].precio );

            };

        }

    return;
}
