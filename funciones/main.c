#include <stdio.h>
#include <stdlib.h>

int suma (int,int);

int main()
{
    int a,b,resultado;


    printf("\nnumero 1\n ");
    scanf ("%d",&a);
    fflush(stdout);
    printf("\nnumero 2\n");
    scanf("%d",&b);
    fflush(stdout);
    resultado=suma(a,b);

    printf("\nla suma es : %d\n",resultado);
    return 0;



}
int suma (int n1, int n2 ){
    int resLocal;
    resLocal=n1+n2;
    return resLocal;
}



