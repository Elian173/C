#include <stdio.h>
#include <stdlib.h>

int main()
{
/* PARTE 1

    int n[3] = {1,2,3};

    int *ptr ;

    int i ;

    ptr = n ;

    for ( i = 0 ; i<3 ; i++)
    {
        printf("%d", n[i]) ;
    }



    for ( i = 0 ; i<3 ; i++)
    {
        printf("%d", *( ptr + i )) ;
    }

PARTE 1*/

/*PARTE 2                       SE PUEDE TRABAJAR UN PUNTERO COMO ARRAY , O UN ARRAY COMO PUNTERO
    int n[3] = {1,2,3};

    int *ptr ;

    int i ;

    ptr = n ;

    for ( i = 0 ; i<3 ; i++)
    {
        printf("%d", ptr[i]) ;
    }



    for ( i = 0 ; i<3 ; i++)
    {
        printf("%d", *( n + i )) ;
    }

                                            PARTE 2 */
/*                                              PARTE 3

    int a = 5 ;
    int *punteroInt;
    int **punteroPuntero;

    punteroInt = &a;

    punteroPuntero = &punteroInt;


    printf("%d\n", **punteroPuntero);

    printf("%d\n", * punteroInt);

    printf("%d\n", a);

    **punteroPuntero = 12;

    printf("%d\n", **punteroPuntero);

    printf("%d\n", * punteroInt);

    printf("%d\n", a);

                                                        PARTE 3*/

                                                    /*PARTE 4*/



    return 0;

}
