#include <stdio.h>
#include <stdlib.h>
#include "inputElian.h"
typedef struct
{
    int dia;
    int mes;
    int anyo;
} str_Fecha;

typedef struct
{

    int id; //empieza en 1000
    char descripcion[20];

} STR_Marca;

typedef struct
{

    int id; // empieza en 5000
    char nombreColor[20];

} STR_Color;

typedef struct
{

    int id;
    char patente[10];
    int idMarca; //validar
    int idColor; // validar
    int modelo; // anyo de fabricacion
    int isEmpty;

} STR_Auto;

typedef struct
{

    int id; // empieza en 20000
    char descripcion[25];
    int precio;

} STR_Servicio;

typedef struct
{

    int id; // incremental
    char patente[10];// debe existir validar
    int idServicio;// debe existir validar
    str_Fecha fecha; // validar dia mes anyo
    int isEmpty;
} STR_Trabajo;


void hardcodearMarca (STR_Marca aCargar []);
void hardcodearColor (STR_Color aCargar[]);
void hardcodearServicio(STR_Servicio aCargar[]);
void hardcodeAutos (STR_Auto aCargar[]);



void iniciarAutosIsEmpty (STR_Auto iniciando[],int cantidadElementos,int numeroQueSeAsigna);
void inciarIncrementalIdAutos (STR_Auto iniciando[], int cantidadElementos);

void iniciarTrabajosIsEmpty(STR_Trabajo iniciando[], int cantidadElementos, int numeroQueSeAsigna);
void inciarIncrementalIdTrabajos (STR_Trabajo iniciando[], int cantidadElementos);


void altaTrabajo (STR_Trabajo trabajos[],int cantidadTrabajos, STR_Auto autos[],int cantidadAutos,STR_Servicio servicios[]);
void darDeAltaAuto(STR_Auto losAutos[],int cantidadAutos);


void dardeBajaAuto(STR_Auto losAutos[], int cantidadAutos);


void modificarAuto (STR_Auto losAutos[],int cantidadAutos);



void mostrarAutos (STR_Auto losAutos[], STR_Color colores[], STR_Marca marcas [], int cantidadAutos);
void mostrarMarcas (STR_Marca marca[], int cantidadElementos);
void mostrarColores (STR_Color color[], int cantidadElementos);
void mostrarServicios (STR_Servicio servicio[], int cantidadElementos);
void mostrarTrabajos (STR_Trabajo trabajos[],int cantidadTrabajos, STR_Auto autos[],STR_Servicio servicios[]);
