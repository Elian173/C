#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// hacer un menu , alta baja (isempty) modificacion listar (listartodos , listar1)  y salir ,
#define ARCH	".\\bin.dat"
#define ESC 27


struct a
{
    char nombre[31];
    int edad;
    int legajo;
    int isEmpty;
};


int main (void)
{
    FILE  *bin;
    struct a pers;
    int cant;
    int legajoAux;
    int opc;


    if ((bin=fopen(ARCH,"rb+"))==NULL)
    {
        if ((bin=fopen(ARCH,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            return 0;
        }
    }


    do
    {
        printf("\n1-ALTA\n2-Baja\n3-MODIF\n4-Listar\n5-Salir\n");
        fflush(stdin);
        opc = getchar();

    switch (opc) {
    case '1':
            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(pers.nombre);

            printf("Ingrese la edad: ");
            fflush(stdin);
            scanf("%d",&pers.edad);

            printf("Ingrese la legajo: ");
            fflush(stdin);
            scanf("%d",&pers.legajo);

            pers.isEmpty = 0;

            fflush(stdin);
            fseek(bin, 0L, SEEK_END);
            fwrite(&pers,sizeof(pers),1,bin);

            break;

        case '3' :

            /* Busqueda */
            system("cls");
            printf("Legajo: ");
            fflush(stdin);
            scanf("%d", &legajoAux);

            //se lleva el indicador de posición al principio para comenzar a leer
            rewind (bin);

            while(!feof(bin))
            {
                cant = fread(&pers,sizeof(pers),1,bin);

                if(cant!=1)
                {
                    if(feof(bin))
                    {
                        break;
                    }
                    else
                    {
                        printf("No leyo el ultimo registro");
                        break;
                    }
                }

                if(legajoAux == pers.legajo)
                {
                    printf("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(pers.nombre);

                    fseek(bin, (long) (-1) * sizeof(pers), SEEK_CUR);
                    fflush(stdin);
                    fwrite(&pers,sizeof(pers),1,bin);
                    break;
                }

                //printf("\n%s\t%d",pers.nombre,pers.edad);
            }
            break;

        case '4':
            //se lleva el indicador de posición al principio para comenzar a leer
            rewind (bin);

            while(!feof(bin))
    {
        cant = fread(&pers,sizeof(pers),1,bin);

            if(cant!=1)
            {
                if(feof(bin))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
                    break;
                }
            }

            printf("\n%s\t%d",pers.nombre,pers.edad);
        }
        break;

        case '5': printf("chau");
        break;

        }//switch

    } while (opc!='5');// do


    fclose(bin);
    getch();

    return 0;
}
