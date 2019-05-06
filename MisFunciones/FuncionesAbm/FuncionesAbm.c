#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesAbm.h"
//#include "FuncionesInput.h"
#include "../FuncionesInput/FuncionesInput.h"

/**Iniciar un parametro de una estructura**/

//"ESTRUCTURA_A_INICIAR_EN" es la estructura.
//"EN_QUE_PARAMETRO_SE_ASIGNA_ESE_NUMERO" = lo que va despues del punto, normalmente poner isEmpty

void f_abm_IniciarEn(ESTRUCTURA_A_INICIAR_EN iniciando[],int cantidadElementos,int numeroQueSeAsigna){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].EN_QUE_PARAMETRO_SE_ASIGNA_ESE_NUMERO = numeroQueSeAsigna;
    }
}


/**INICIAR INCREMENTAL DEL 1 AL XX**/

void f_abm_IniciarIncremental (ESTRUCTURA_A_INICIAR_INCREMENTAL iniciando[],int cantidadElementos){
    int i;
    for(i=0;i < cantidadElementos ; i++)
    {
        iniciando[i].EN_QUE_PARAMETRO_SE_ASIGNA_ESE_NUMERO = i+1;
    }
}


/**Buscar cantidad lugares usados**/
//modificar por el nombre de la estructura donde se vaya a buscar. debe existir "isEmpty dentro de esa estructura"
//"ESTRUCTURA_DONDE_BUSCAR_OCUPADOS_UNO"        .isEmpty

void f_abm_BuscarOcupadosESTRUCTURA_DONDE_BUSCAR_OCUPADOS_UNO(ESTRUCTURA_DONDE_BUSCAR_OCUPADOS_UNO aBuscar[],int cantidadElementos,int indicadorOcupado,int * dondeGuardarCantidadOcupados){

    int i;
    int aux=0;
    for (i=0;i<cantidadElementos;i++){

    if (aBuscar[i].isEmpty == indicadorOcupado){
    aux++;
    };
};

* dondeGuardarCantidadOcupados = aux ;

};


/**obtener id primer luar vacio*//
//"ESTRUCTURA_DONDE_BUSCAR_PRIMER_VACIO_UNO"    .isEmpty
int f_abm_BuscarPrimerVacioESTRUCTURA_DONDE_BUSCAR_PRIMER_VACIO_UNO(ESTRUCTURA_DONDE_BUSCAR_PRIMER_VACIO_UNO aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia){

    int i;
    for (i=0;i<cantidadElementos;i++){

    if (aBuscar[i].isEmpty == indicadorPrimerOcurrencia){

    return i;

    };
};
    return -1;
};


/**Obtener id de estructura en base a un numero , -1 si no existe*/

int findProductByCode(Product productArray[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].code == code && productArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}



/**Ordenar por id**/
//"ESTRUCTURA_A_ORDENAR_POR_ID"    .id
void f_abm_OrdenarPorIdESTRUCTURA_A_ORDENAR_POR_ID (ESTRUCTURA_A_ORDENAR_POR_ID aOrdenar[] , int cantidadElementos){

int i, j;
int tmp;

for (i = 1; i < cantidadElementos; i++){
    tmp = aOrdenar[i].id;
    j = i - 1;

while ((j >= 0) && (tmp < aOrdenar[j].id)){

    aOrdenar[j + 1].id = aOrdenar[j].id;
    j--;
};

aOrdenar[j + 1].id = tmp;

};
};



/**Ordenar alfabeticamente**/

//"ESTRUCTURA_A_ORDENAR_ALFABETICAMENTE"        .STRING_UNO_A
//Debe existir .STRING_UNO_A en la estructura o ser modificado antes.

void f_abm_OrdenarAlfabeticamenteESTRUCTURA_A_ORDENAR_ALFABETICAMENTEPorSTRING_UNO_A(int cantidadElementos,int longitudMaxString,
                       ESTRUCTURA_A_ORDENAR_ALFABETICAMENTE aOrdenar[]){

    char auxiliar[longitudMaxString];

    int i,j;

    for(i=0; i<cantidadElementos-1; i++)
    {
    for(j=i+1; j<cantidadElementos; j++)
    {
    if(strcmp( aOrdenar[i].STRING_UNO_A,aOrdenar[j].STRING_UNO_A)>0){
        strcpy(auxiliar,aOrdenar[j].STRING_UNO_A);
        strcpy(aOrdenar[j].STRING_UNO_A , aOrdenar[i].STRING_UNO_A);
        strcpy(aOrdenar[i].STRING_UNO_A , auxiliar);
    };

};
};
return;
};


/**Listar una struct **/
// "ESTRUCTURA_A_MOSTRAR_UNO" es el tipo de estructura a listar .
void f_abm_MostrarESTRUCTURA_A_MOSTRAR_UNO (ESTRUCTURA_A_MOSTRAR_UNO aListar , int id) {


printf("    " , aListar[id]. );

return;
};

