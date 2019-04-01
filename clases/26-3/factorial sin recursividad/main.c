#include <stdio.h>
int factorial(int );
void main(void)
{
int valor,result;
printf("\nIngrese numero:");
scanf("%d",&valor);
result=factorial(valor);
printf("\nEl factorial de %d es %d",valor,result);
}

int factorial(int n)
{
int resp=1,i;

for (i=n;i>0;i--){
    resp= resp*i;
}
}
