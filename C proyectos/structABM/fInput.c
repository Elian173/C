#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>


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

int getSexo(void){

    char r;
    printf("Ingrese el sexo :");
    printf( "\n --F-- o --M-- \n");
    r = toupper(getche());

while ( !((r=='F')||(r=='M')) ){

        printf ("\nError, ingrese (F/M)... \n");
        r = toupper(getche());
        }

return r;
};


int getInt(char mensaje[]){
    int x;
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%d",&x);
    return x;
};


int getNombre(char mensaje[],char*nombre)
{
    int retorno;
    int i;
    int is_not_valid_name;
    char auxiliar[50];
    printf("%s\n",mensaje);
    do {
        fgets(auxiliar,50,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                is_not_valid_name = -1;
                printf("\nError en formato, ingrese solo letras y espacios: ");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                is_not_valid_name = 0;
                retorno = 0;
            }
        }
    } while (is_not_valid_name);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n'){

    auxiliar[len-1]='\0';

    };

    strcpy(nombre, auxiliar);
    return retorno;
}
