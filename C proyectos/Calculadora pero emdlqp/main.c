#include <stdio.h>
#include <stdlib.h>
#include "CalcFunciones.h"

int main()
{
float a=0, b=0;
int inicio=1 , opcion , respuesta=1;

while(respuesta==1){


while (inicio==1)
    {

    printf("--------------------MENU--------------------\n"
           "A=%.2f--------------------------------B=%.2f\n", a,b);

    printf("\nIngrese 1 para modificar el primer operando (A)\n"
           "\nIngrese 2 para modificar el primer operando (B)\n"
           "\nIngrese 3 para calcular todas las operaciones\n"
           "\n-Ingrese 0 para salir.\n\n"
           "\n\nOpcion : ");

    opcion= pedirNum();

    switch(opcion){
        case 1:printf("\n-Ingrese el valor de A :") ; a = pedirNum() ; system("CLS") ; break;
        case 2:printf("\n-Ingrese el valor de B :") ; b= pedirNum() ; system("CLS") ; break;
        case 3:system("CLS") ; inicio=0 ; break;
        case 0:return 0;
        default:system("CLS");printf("\n*** La ultima opcion igresada no fue valida ***\n\n");
    };
    };//while "inicio"

    system("CLS");

    printf("--------------------MENU--------------------\n"
           "A=%.2f--------------------------------B=%.2f\n", a,b);

    printf(
           "\n-Ingrese 1 para sumar         (%.2f + %.2f).\n"
           "\n-Ingrese 2 para restar        (%.2f - %.2f).\n"
           "\n-Ingrese 3 para multiplicar   (%.2f x %.2f).\n"
           "\n-Ingrese 4 para dividir       (%.2f / %.2f).\n"
           "\n-Ingrese 5 para calcular el factorial de  %.0f y %.0f\n"
           "\n-Ingrese 6 para volver atras\n"
           "\n-Ingrese 0 para salir.\n\n"
           "\n\nOpcion : "
            ,a,b  ,a,b  ,a,b  ,a,b  ,a,b);

    opcion = pedirNum();

    switch (opcion){

        case 1:system("CLS");
        printf("La Suma de %.2f y %.2f es: %.2f\n\n",a,b,suma(a,b));
        printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
        break;

        case 2:system("CLS");
        printf("La Resta de %.2f y %.2f dio %.2f\n\n",a,b,resta(a,b)) ;
        printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
        break;

        case 3:system("CLS");
        printf("El Producto de %.2f y %.2f es %.2f\n\n",a,b,multiplicacion(a,b)) ;
        printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
        break;

        case 4:system("CLS");

        if (b==0){
            printf("No se puede dividir por 0\n");
            printf("\n\Volver al menu?\n\n") ; respuesta = continuar(); break ;}
        else {
            printf("La Division de %.2f entre %.2f dio %.2f\n\n",a,b,division(a,b));
            printf("\n\Volver al menu?\n\n") ; respuesta = continuar() ; break ;};

        case 5:system("CLS");
        if (a<0){
            printf("\nNo se puede calcular el factorial de (%.0f) porque es un numero negativo\n",a);}
        else{
            printf("\nEl factorial de %.0f dio: %d \n",a,factorizacion(a));};
        if (b<0){
            printf("\nNo se puede calcular el factorial de (%.0f) porque es un numero negativo\n",b);}
        else{
            printf("\nEl factorial de %.0f dio : %d \n",b,factorizacion(b));};

        printf("\n\Volver al menu?\n\n") ; respuesta = continuar();
        break;

        case 6:system("CLS"); inicio=1 ; break ;

        case 0:respuesta=0 ; break ;

        default:system("CLS");
        printf("Opcion invalida , Volver al menu?\n\n") ; respuesta = continuar();
        break ;
    }//switch opcion




};//1er while respuesta

return 0;

}//main
