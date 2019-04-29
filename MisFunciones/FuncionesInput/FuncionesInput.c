#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/*Funciones para obtener valores*/

void f_i_PedirInt (int * var_dondeAsignar , char mensaje[]){
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf("%d",var_dondeAsignar);
    return;
};

void f_i_PedirFloat (float * var_dondeAsignar , char mensaje[]){
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf("%f",var_dondeAsignar);
    return;
};

void f_i_PedirChar (char * var_dondeAsignar , char mensaje[]){
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf(" %c",var_dondeAsignar);
    return;
};

void f_i_PedirString(char var_dondeAsignar[], int longitudMaxString , char mensaje[]){
    char aux[longitudMaxString];

    printf("\n%s\n",mensaje);
    fgets(aux,longitudMaxString,stdin);

    //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n'){
    aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
};

void f_i_PedirIntEntre(int * var_dondeAsignar , int min , int max , char mensaje[]){
    int aux;
    do
    {
    printf("\n%s\n" , mensaje);
    fflush(stdin);
    scanf("%d" , &aux);

    if (aux > max || aux < min) {
    printf("\n**Error,opcion invalida**");

    };
    }
    while (aux > max || aux < min);
    *var_dondeAsignar = aux;
    return;
};


/*Funciones para obtener datos especificos*/

void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString , char mensaje[]){
    int i;
    int no_es_un_nombre;
    char auxiliar[longitudMaxString];

    do {
        printf("%s\n",mensaje);
        fgets(auxiliar,longitudMaxString,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                no_es_un_nombre = -1;
                printf("\n**Error, ingrese solo letras y espacios**\n");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                no_es_un_nombre = 0;
            }
        }
    } while (no_es_un_nombre);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n'){

    auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar, auxiliar);
    return;
};

void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString ,char mensaje[]){

    int i;
    int invalido;
    char auxiliar[longitudMaxString];

    fflush(stdin);

    printf("%s\n",mensaje);

    do {
        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            if (auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                invalido = 1;
                printf("\nError, ingrese solo numeros \n");
                break;
            }
            else
            {
                invalido = 0;
            }
        }
    } while (invalido);
    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n'){

    auxiliar[len-1]='\0';

    };
    strcpy(var_dondeAsignar,auxiliar);
    return;
};

void f_i_PedirStringSoloLetras(char var_dondeAsignar[],int longitudMaxString ,char mensaje[]){

    char aux[longitudMaxString];
    int esSoloLetras=1;
    int i=0;
    printf("\n%s\n",mensaje);

    do{
    fgets(aux,longitudMaxString,stdin);
    for (i=0;i<strlen(aux)-1;i++)
    {
       if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')){
       esSoloLetras = 0;
       printf("\nError, ingrese solo Letras y Espacios\n");
       printf("\n%s\n",mensaje);
       break;
       }else{
       esSoloLetras=1;
       };
    };
   } while (esSoloLetras == 0 );


    //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n'){
    aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
}

void f_i_PedirStringAlfaNumerico(char var_dondeAsignar[],int longitudMaxString ,char mensaje[]){
    char aux[longitudMaxString];
    int esAlfaNumerico = 1;
    int i = 0;
    printf("\n%s\n",mensaje);

    do{
    fgets(aux,longitudMaxString,stdin);
    for (i=0;i<strlen(aux)-1;i++){
    if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z') && (aux[i] < '0' || aux[i] > '9')){
       esAlfaNumerico = 0;
       printf("\nError, ingrese solo Letras , Numeros y Espacios\n");
       printf("\n%s\n",mensaje);
       break;
       }else{
       esAlfaNumerico = 1;
       };
       };
   } while (esAlfaNumerico == 0 );

   //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n'){
    aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
};

void f_i_PedirSexo(char * var_dondeAsignar , char mensaje[]){
    char r;
    printf("%s",mensaje);
    printf( "\n --F-- o --M-- \n");
    r = toupper(getche());
while ( !((r=='F')||(r=='M')) ){

        printf ("\nError, ingrese (F/M)... \n");
        r = toupper(getche());
        };
    fflush(stdin);
    *var_dondeAsignar=r;
return;
};

void f_i_PedirEdad (int * var_dondeAsignar ,char mensaje[]){
    int edad;

    printf("\n%s:\n",mensaje);
    scanf("%d",&edad);

    while (edad>99 || edad<0){
    printf("\n**Edad Invalida**\n%s",mensaje);
    scanf("%d",&edad);
    };

    *var_dondeAsignar=edad;

    return;
    }


/*Funciones para Menus */

int f_i_continuar(char mensaje[]){
    char r;
    printf("\n%s\n",mensaje);
    printf( "\n --S-- o --N-- \n");

    r = toupper(getche());
    printf("\n");

while ( !((r=='S')||(r=='N')) ){
        printf ("\nError, ingrese (S/N)... \n");

        r = toupper(getche());
        printf("\n");
        };
        fflush(stdin);

return (r=='S'); /*Devuelve 1 si se ingresa 'S'*/
};

/*Funciones de ordenamiento*/

void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos){
    int i;
    for (i=0;i<cantidadElementos;i++){
        var_dondeAsignar[i]= asignarleEsteNumero;
    };
return;
};

void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos){
    int i;
    for (i=0;i<cantidadElementos;i++){

        var_dondeAsignar[i]= i;

    };
return;
};

void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,char var_dondeAsignar[longitudMaxString][cantidadElementos]){
/*NO FUNCIONA PERO SE PUEDE COPIAR EL CODIGO*/

char auxiliar[longitudMaxString];

int i,j;

for(i=0; i<cantidadElementos-1; i++)
{
for(j=i+1; j<cantidadElementos; j++)
{

if(strcmp(var_dondeAsignar[i],var_dondeAsignar[j])>0)
{
strcpy(auxiliar, var_dondeAsignar[i]);
strcpy(var_dondeAsignar[i], var_dondeAsignar[j]);
strcpy(var_dondeAsignar[j], auxiliar);
}
}
}

};

void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos){

    int i , j , aux;
    for(i=0; i<cantidadElementos-1; i++)
    {
    for(j=0; j<cantidadElementos-1; j++)
    {
    if(var_dondeAsignar[j] < var_dondeAsignar[j+1]){
        aux = var_dondeAsignar[j];
        var_dondeAsignar[j] = var_dondeAsignar[j+1];
        var_dondeAsignar[j+1] = aux;
    };
};
};
};

void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[],int cantidadElementos){

    int i , j , aux;
    for(i=0; i<cantidadElementos-1; i++)
    {
    for(j=0; j<cantidadElementos-1; j++)
    {
    if(var_dondeAsignar[j] < var_dondeAsignar[j+1]){
        aux = var_dondeAsignar[j+1];
        var_dondeAsignar[j+1] = var_dondeAsignar[j];
        var_dondeAsignar[j] = aux;
    };
};
};
};
