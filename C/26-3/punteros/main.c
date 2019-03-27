#include <stdio.h>
#include <stdlib.h>

void mostrar(int *x, int y);

int main()
{
    int x ,y;
    printf("Ingrese x");
    scanf ("%d", &x);
    printf("Ingrese y");
    scanf ("%d", &y);

     mostrar(&x,y);

};
void mostrar (int *x , int y)
{
*x=y;
printf ("%d %d", *x , y);
}
