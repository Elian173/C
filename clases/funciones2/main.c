#include <stdio.h>

//esto da 3 porque solo utilizamos la variable global y al llamar a la funcion carga , la modifica

int var;
void carga(void);
void main(void)
{
int x,y,z;
var=5;
carga();
printf("%d",var);
}
void carga(void)
{
var=3;
}






/*int var;
void carga(void);
void main(void)
{
int x,y,z;
var=5;
carga();
printf("%d",var);
}
void carga(void)
{
int var;
var=3;
}
//esto da 5 porque var se asigna como local en carga ademas de global , asi que al
//llamar a la funcion carga , no se modifica var global , sino var local (de carga) ,y no interfiere  */
