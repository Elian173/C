/**ifdef y endif poner**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesInput.h"
#define LARGO 20

int main(){
int i=0;
char arraystrings [5][LARGO]={"aaa","ccc","BBB","la puta madreeee","123"};

for(i=0;i<5;i++){
strlwr(arraystrings[i]);
};

f_o_OrdenarArrayAlfabeticamente(5,LARGO,arraystrings);

for(i=0;i<5;i++){
printf("%s\n",arraystrings[i]);
}

printf("Fiin");

return 0;
};
