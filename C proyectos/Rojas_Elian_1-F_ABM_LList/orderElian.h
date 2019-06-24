
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/*Funciones de ordenamiento*/
/**\brief Recibe un array de enteros y iguala todos sus elementos a un valor que se le asigne
 * \param var_dondeAsignar es donde se guarda el valor
 * \param asignarleEsteNumero es el numero que se le asigna a todos los elementos del array
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos);
/**\brief Recibe un array de enteros y asigna valores a todos sus elementos de manera creciente de uno en uno (empezando desde 1)
 * \param var_dondeAsignar es donde se guarda el valor
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de enteros y devuelve el indice donde se encuentre la primera ocurrencia que se le asigne a la funcion
 * \param var_dondeAsignar es donde se busca el valor
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param indicadorPrimerOcurrencia es el numero que se busca dentro del array
 * \return el indice de la primer ocurrencia si se encuntra ,  -1 si no se encuentra .
 */
int f_o_BuscarIndicePrimerOcurrencia (int var_dondeAsignar[],int cantidadElementos,int indicadorPrimerOcurrencia);
/**\brief Recibe un array de enteros lo ordena de mayor a menor
 * \param var_dondeAsignar es el array a ordenar
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de enteros lo ordena de menor a mayor
 * \param var_dondeAsignar es el array a ordenar
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de strings y lo ordena alfabeticamente
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param longitudMaxString es la longitud maxima de los string de el array var_dondeAsignar
 * \param var_dondeAsignar es el array a ordenar
 * \return void
 */
void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,
                                     char var_dondeAsignar[cantidadElementos][longitudMaxString]);
/**\brief Recibe un array de strings y deja cada palabra de cada elemento con la primera letra mayuscula y el resto minuscula
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param longitudMaxString es la longitud maxima de los string de el array var_dondeAsignar
 * \param var_dondeAsignar es el array a arreglar mayusculas
 * \return void
 */
void f_o_ArreglarCaps (int cantidadElementos,int longitudMaxString,
                       char var_dondeAsignar[cantidadElementos][longitudMaxString]);

