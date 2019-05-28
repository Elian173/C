/*
#include <stdio.h>
#include <stdlib.h>

int main()
{

    struct persona *p //2 byte

    scanf ("%d", &p->fecha.dia) // no puedo sin asignar el puntero

    //void* malloc(unsigned int numBytes);

    struct persona *p //2 byte

    // pido memoria dinamica del tamaño de la estructura y casteo el malloc al tipo de estructura
    //despues asigno esa memoria a p,

    p = (struct persona) malloc (sizeof (struct persona)) // un bloque
    p = (struct persona) malloc (sizeof (struct persona) * 5) //5 bloques


    //si el sistema no encuentra memoria disponible malloc retorna NULL (direccion de memoria nula)
    //veo si hay memoria en el sistema

    if(p!=NULL)

    //ahora si puedo
    p->fecha.dia;
    p->nombre;


    //void *calloc(unsigned int numElementos,unsigned int numBytesElemento);
    //es lo mismo pero a los datos numericos los inicia en 0 y los string a \0




    //REDIMENSIONAR MEMORIA (Pido mas memoria si la necesito) realoc.

    //void* realloc(void* ptr, unsigned int size);

    // en el segundo parametro tengo que pedir lo que necesito MAS lo que estoy usando

    //ponele que necesito 10 y ya tengo ocupados 5.

    p = (struct persona) realloc (p,sizeof (struct persona) * 10) // 10 bloques (5 de antes mas 5 de ahora)

    //si no hay memoria disponible para asignar , devuelve null
    //entonces P ahora vale NULL
    //asi que perdi los primero5 datos que tenia guardados

    //entonces cuando hago realloc , la variable donde guardo la direccion , tiene que ser una auxiliar. tonce>

    pAux= (struct persona) realloc (p,sizeof (struct persona) * 10)

    if(pAux!=NULL){ //tengo memoria disponible
        p = pAux;
    } else // no hay memoria disponible.

    //asi no pierdo la data .-.

    //ahora hay que liberar la memoria si no la necesito mas
    // funcion FREE void free(void* p);

    free (p);
    free (pAux);

    //ahora el puntero tiene NULL
    // no puedo liberar algo que no esta ocupado
    free (p)
    ttatata cosas cosas
    free(p)
    listo ahi se rompio todo
    // no puedo hacer free de un puntero que apunta a NULL




    return 0;




}
*/
