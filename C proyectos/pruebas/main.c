
#include <stdio.h>
#include <stdlib.h>
int main(void){

    char matriz[20];

  /*  scanf("%s",matriz);

    printf("%s",matriz);*/

    gets(matriz);

    printf("%s",matriz);

    char letra1 = 'A';
char letra2 = 'B';
char *p = &letra1;
letra1 = 'C';
letra2 = *p;
printf("%c",letra2);

 return 0;

 }

