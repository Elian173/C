#include <stdlib.h>
#include <stdio.h>
#include "calcu.h"

//EL MENU

menu() {

int p=1 , a , b , respuesta=1, opcion;

while (respuesta!=0)
    {
    if (p==1) {
        p=0;
        system("CLS");
        printf("Porfavor ingrese el PRIMER operando:\n");
        a = pedirNum();
        printf("\nPorfavor ingrese el SEGUNDO operando: \n");
        b = pedirNum();
    }

    system("CLS");
    printf("----------------MENU----------------\n"
           "A=%d----------------------------B=%d\n", a,b);

    printf("\n\nIngrese 1 para sumar   (%d + %d)."
           "\n\nIngrese 2 para restar   (%d - %d)."
           "\n\nIngrese 3 para multiplicar   (%d * %d)."
           "\n\nIngrese 4 para dividir   (%d / %d)."
           "\n\nIngrese 5 para calcular el factorial de  %d  y  %d."
           "\n\nIngrese 6 para modificar los operandos."
           "\n\nIngrese 0 para salir.\n\n"
           ,a,b  ,a,b  ,a,b  ,a,b  ,a,b);

    opcion = pedirNum();

    switch (opcion)
    {
    case 1:system("CLS");
    printf("La Suma de %d y %d es: %d\n\n",a,b,suma(a,b));
    printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
    break;
    case 2:system("CLS");
    printf("La Resta de %d y %d dio %d\n\n",a,b,resta(a,b)) ;
    printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
    break;
    case 3:system("CLS");
    printf("El Producto de %d y %d es %d\n\n",a,b,multiplicacion(a,b)) ;
    printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
    break;
    case 4: system("CLS"); printf("La Division de %d entre %d dio %.2f\n\n",a,b,division(a,b));
    printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
    break;respuesta = continuar();
    case 5:system("CLS");
    printf("\nEl factorial de %d dio : %d \n\nEl factorial de %d dio: %d \n\n",a,factorizacion(a),b,factorizacion(b));
    printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
    break;
    case 6:system("CLS");p=1;
    break;
    case 0:respuesta=0 ; break ;
    default:system("CLS");
    printf("Opcion invalida , Volver al menu?\n") ; respuesta = continuar();
    break ;

} // switch
} // while
}; // menu


//pedir numero

int pedirNum(){
int n;
fflush(stdin);
scanf("%d", & n);

return n;
};


//continuar funcion Pregunta si o no , devuelve n=0 o s=1;
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



//suma

int suma (int a , int b){
int total;
total = (a+b);

return total;
};

//resta

int resta (int a , int b){
int total;
total = (a-b);

return total;
};

//multiplicacion

int multiplicacion (int a , int b){
int total;
total = (a*b);

return total;
};

//factorial

int factorizacion(int x)
{
int total=1,i;

for (i=x;i>0;i--){
    total = total*i;
    }

    return total;
};

//division

double division(int a ,int b){

if (b==0) {
        system("CLS");printf("\n\nNo se puede dividir por 0 \n\n");
        return 0;
        }
else {
double total;
total = (double)a / (double)b;

return total ;
}
};


