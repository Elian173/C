#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "increible.h"

//funcion menu

void menu (){
int respuesta=1;

while(respuesta!=0)
{
    system("CLS");
    printf("\n Apreta 1 para SUMAR \n");
    printf("\n Apreta 2 para RESTAR \n");
    printf("\n Apreta 3 para MULTIPLICAR \n");
    printf("\n Apreta 4 para DIVIDIR \n");
    printf("\n Apreta 0 para SALIR \n");
    fflush(stdin);
    scanf("%d", &respuesta);

    switch(respuesta)
    {
    case 1:sumame();break;
    case 2:restame();break;
    case 3:multiplicame();break;
    case 4:dividime();break;
    case 5:
    case 0 :return printf("\n \n CHAU JAJA \n \n" );break;
    default:system("CLS"); printf ("\n\n- Error -\n\n") ; break ;
    };

    printf("\n\ Volver al menu? \n");
    respuesta=continuar();
}
}



//funcion de sumar

void sumame(int a, int b){
    int total;
    system("CLS");
    printf("--------SUMA--------");
    printf("\n\n Ingrese el primer numero a SUMAR \n\n ");
    fflush(stdin);
    scanf("%d",&a);
    printf("\n\n Ingrese el segundo numero a SUMAR \n\n");
    fflush(stdin);
    scanf("%d",&b);
    total=(a+b);

printf("\n\nEl total de la SUMA es :  %d\n\n",total);
};

//funcion de restar

void restame(int a ,int b){
    int total;
    system("CLS");
    printf("--------RESTA--------");
    printf("\n\n Ingrese el primer numero \n\n ");
    fflush(stdin);
    scanf("%d",&a);
    printf("\n\n Ingrese la cantidad a RESTARLE \n\n");
    fflush(stdin);
    scanf("%d",&b);
    total=(a-b);

printf("\n\nEl total de la RESTA es :  %d\n\n",total);
};

//funcion de dividir

void dividime(int a,int b){
    int total;
    system("CLS");
    printf("--------DIVISION--------");
    printf("\n\n Ingrese el numero a dividir \n\n ");
    fflush(stdin);
    scanf("%d",&a);
    printf("\n\n Ingrese el divisor \n\n");
    fflush(stdin);
    scanf("%d",&b);

    if(b==0){ printf("\n\n No es posible dividir por 0 \n\n"); }
    else {
    total=(a/b);
    printf("\n\nEl resultado de la DIVISION es :  %d\n\n",total);
} return 0;
};

//funcion de multiplicar

void multiplicame(int a,int b){
    int total;
    system("CLS");
    printf("--------MULTIPLICACION--------");
    printf("\n\n Ingrese el numero que quiere multiplicar \n\n ");
    fflush(stdin);
    scanf("%d",&a);
    printf("\n\n Ingrese por cuanto quiere multiplicar ese numero \n\n");
    fflush(stdin);
    scanf("%d",&b);
    total=(a*b);
    printf("\n\nEl producto de esa multiplicacion es :  %d\n\n",total);
};





//funcion Pregunta si o no , devuelve n=0 o s=1;
int continuar(void){

    char r;
    printf( "\n -S o N- \n");
    r = toupper( getche() );

while ( !((r=='S')||(r=='N')) ){

        printf ("\nInvalido, ingrese (S/N)... ");
        r = toupper( getche() );}

return (r=='S');
};
