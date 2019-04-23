#include <stdio.h>
#include <stdlib.h>




//continuar
/** \brief Pregunta al usuario si quiere continuar (S o N) ; no permite otros caracteres
 * \param ()
 * \return Si se ingresa S devuelve int 1 , si se ingresa N devuelve int 0
 */
int continuar(void){

    char r;
    printf( "\n --S-- o --N-- \n");
    r = toupper(getche());

while ( !((r=='S')||(r=='N')) ){

        printf ("\nError, ingrese (S/N)... ");
        r = toupper(getche());
        }

return (r=='S');
};
