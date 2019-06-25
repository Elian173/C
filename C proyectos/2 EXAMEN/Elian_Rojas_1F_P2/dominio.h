#ifndef dominio_H_INCLUDED
#define dominio_H_INCLUDED

typedef struct
{
    int id;
    char dominio[31];
    int anio;
    char tipo;
} STR_Dominio;

//control
STR_Dominio* dominio_new();
void dominio_delete(STR_Dominio* this);
void objectA_print(STR_Dominio* ptr_ObjectA);
void dominio_printALL(STR_Dominio* this);
//
int dominio_getId(STR_Dominio* this,int* id);
int dominio_setId(STR_Dominio* this,int id);
//
int dominio_getDominio(STR_Dominio* this,char* dominio);
int dominio_setDominio(STR_Dominio* this,char* dominio);
//
int dominio_getAnio(STR_Dominio* this,int *anio);
int dominio_setAnio(STR_Dominio* this,int anio);
//
int dominio_getTipo(STR_Dominio* this,char* tipo);
int dominio_setTipo(STR_Dominio* this,char tipo);
//

int controller_ListObjectA(LinkedList* linkedList);
int dominio_setMotoAuto(void* dominio);
int dominio_subListaMotos(void* dominio);
int dominio_subListaAutos(void* dominio);
//
#endif
