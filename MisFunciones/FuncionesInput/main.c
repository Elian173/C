#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesInput.h"


int main()
{

int lol[6]={5,2,1,6,7,90};
int i=0;

f_o_OrdernarArrayMayorAMenor(lol,6);

for (i=0;i<5;i++){
    printf("%d\n",lol[i]);
};
printf("AAA\n");
f_o_OrdernarArrayMenorAMayor(lol,6);

for (i=0;i<5;i++){
    printf("%d\n",lol[i]);
};

return 0;
};
