#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);

static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* ptr_Aux_Node = NULL;

    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {

        ptr_Aux_Node = this->pFirstNode;

        while (nodeIndex > 0)
        {
            ptr_Aux_Node = ptr_Aux_Node->pNextNode;
            nodeIndex -- ;
        }

    }
    return ptr_Aux_Node;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    // NO VALIDAR pELEMENT != NULL xq anda mal.
    int retorno = -1;

    Node* ptr_New_Node = (Node*)malloc(sizeof(Node)*1);
    Node* ptr_Before_Node;
    Node* ptr_Current_Node;

    if( this!= NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )
    {
        if( nodeIndex == 0 )//Se realiza el add en el primer lugar, estando vacio o no
        {
            ptr_Before_Node = this->pFirstNode;//Se copia el primer nodo en variable auxiliar
            this->pFirstNode = ptr_New_Node;//Se enlaza NUEVO NODO al comienzo de la LinkedList

            ptr_New_Node->pNextNode = ptr_Before_Node;//Se enlaza el viejo primer nodo al next del nuevo nodo
            ptr_New_Node->pElement = pElement;

            this->size = ll_len(this) + 1;

            retorno = 0;
        }
        else if((this->pFirstNode != NULL || this->pFirstNode == NULL)
                && (nodeIndex > 0 && nodeIndex <= ll_len(this)))//Se realiza el add en el index
        {
            ptr_Current_Node = getNode(this,nodeIndex);  //Get del NODO a reemplazar
            ptr_Before_Node = getNode(this,nodeIndex-1); //Get del NODO anterior al que reemplazo

            ptr_New_Node->pNextNode = ptr_Current_Node; //Muevo el NODO del INDICE al siguiente del NUEVO NODO
            ptr_New_Node->pElement = pElement;          //Asigno elemento
            ptr_Before_Node->pNextNode = ptr_New_Node;//Asigno al NODO ANTERIOR el NUEVO NODO como siguiente

            this->size = ll_len(this) + 1;

            retorno = 0;
        }
    }
    return retorno;
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
        addNode(this,ll_len(this),pElement);
        retorno = 0;
    }
    return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;
    Node* ptr_Aux_Node = NULL;

    if(this != NULL && ll_len(this) > 0 && index >= 0 && index < ll_len(this))
    {
        ptr_Aux_Node = getNode(this,index);
        retorno = ptr_Aux_Node->pElement;
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    //NO VERIF pElement != NULL

    int retorno = -1;

    Node* ptr_Aux_Node = NULL;

    if( this != NULL  && index >= 0 && index < ll_len(this) )
    {
        ptr_Aux_Node = getNode(this,index);
        ptr_Aux_Node->pElement = pElement;
        retorno = 0;

    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    Node* ptr_Delete_Node = NULL;
    Node* ptr_Previous_Node = NULL;
    Node* ptr_Next_Node = NULL;

    if(this != NULL  && index >= 0 && index < ll_len(this))
    {
        ptr_Delete_Node = getNode(this,index);

        if(ptr_Delete_Node != NULL) // el nodo existe

        {
            if(index == 0)
            {
                this->pFirstNode = ptr_Delete_Node->pNextNode;
                free(ptr_Delete_Node);
                retorno = 0;
            }
            else
            {
                ptr_Previous_Node = getNode(this, (index - 1));
                ptr_Next_Node = getNode(this,(index + 1));

                ptr_Previous_Node->pNextNode = ptr_Next_Node;
                free(ptr_Delete_Node);
                retorno = 0;
            }

            this->size = (ll_len(this)-1);
        }
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;
    int i;

    if(this != NULL)
    {
        Node* ptr_First_Node = this->pFirstNode;

        if(ptr_First_Node != NULL)
        {

            for(i=0 ; i<ll_len(this) ; i++)
            {
                ll_remove(this,i);
            }

            retorno = 0;

        }
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free (this);
        retorno = 0;
    }

    return retorno;
}


/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int i = 0; //el index
    Node* ptr_Aux_Node;

    if (this != NULL ) //&pElement != NULL )
    {
        ptr_Aux_Node = this->pFirstNode;

        for (i=0 ; i<ll_len(this) ; i++)
        {
            if (ptr_Aux_Node->pElement == pElement)
            {
                retorno = i;
                break;
            }

            ptr_Aux_Node = getNode(this,i);

        }

    }

    return retorno;
}


/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
    }

    return retorno;
}


/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)) // && pElement != NULL)
    {
        addNode(this,index,pElement);
        retorno = 0;
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this)) // && pElement != NULL)
    {
        retorno = ll_get(this,index);
        ll_remove(this,index);
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{

    int retorno = -1;
    int i;

    Node* ptr_Aux_Node = NULL;

    if(this != NULL)
    {
        retorno = 0;
        for (i=0 ; i<ll_len(this) ; i++)
        {
            ptr_Aux_Node = getNode(this,i);

            if(ptr_Aux_Node->pElement == pElement)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;

}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int i;
    int retorno = -1;
    Node* ptr_AuxNode;

    if(this != NULL && this2 != NULL)
    {
        retorno = 1;

        for (i=0 ; i<ll_len(this) ; i++)
        {
            ptr_AuxNode = getNode(this2,i);

            if(ll_contains(this,ptr_AuxNode->pElement) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* ptr_AuxNode = NULL;

    if (this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        for (i = from ; i <= to ; i++)
        {
            ptr_AuxNode = ll_get(this,i);
            ll_add(cloneArray,ptr_AuxNode);
        }
    }
    else
    {
        cloneArray = NULL;
    }

    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* ptr_AuxNode = NULL;
    int i;

    if (this != NULL)
    {
        cloneArray = ll_newLinkedList();

        for (i = 0 ; i <= ll_len(this) ; i++)
        {
            ptr_AuxNode = ll_get(this,i);
            ll_add(cloneArray,ptr_AuxNode);
        }
    }

    return cloneArray;

}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i = 0;
    void* pAux;
    int j= 0;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }
    return returnAux;
}

//_________________Parcial


int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno = 0;
    int i=0;
    void* ptr_elemento;
    Node* ptr_auxNode;

    if(this != NULL && pFunc != NULL)
    {
        do
        {
            ptr_auxNode = getNode(this,i);

            ptr_elemento = ptr_auxNode->pElement;

            if(pFunc(ptr_elemento) == 1)
            {
                retorno = 1;
            }

            i++;

        }
        while(ptr_auxNode->pNextNode != NULL);
    }

    return retorno;
}


//crea una sublista segun el criterio que devuelva la funcion

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* new_list = NULL;
    int i;
    void* ptr_elemento;

    if(this != NULL && pFunc != NULL)
    {
        new_list = ll_newLinkedList();

        for(i=0; i < ll_len(this)-1 ; i++)
        {
            ptr_elemento = ll_get(this,i);

            if(pFunc(ptr_elemento) == 1)
            {
                ll_add(new_list,ptr_elemento);
            }
        }
    }
    return new_list;
}
