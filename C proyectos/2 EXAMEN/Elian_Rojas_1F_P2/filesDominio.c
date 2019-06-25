#include <stdio.h>
#include <stdlib.h>
#include "filesDominio.h"
#include "linkedList.h"
#include "dominio.h"
#include "string.h"
#include "inputElian.h"
//_________________________________________________TEXTO____________________________________________//

int files_CreateFileText(char* file_Path)
{
    int value = 1;
    FILE* ptr_File;

    if ((ptr_File = fopen(file_Path,"r+")) == NULL)
    {
        if ((ptr_File = fopen(file_Path,"w+")) == NULL)
        {
            printf("ERROR F00");
            value = 0;
        }
    }

    fclose(ptr_File);

    return value;
}

//Parser de texto
//__________________________________
int files_Parser_dominioFromText(FILE *ptr_File, LinkedList *linkedList)
{
    char buffer[4][31];
    int value = 1;
    int readElements = 0;
    STR_Dominio* ptr_New_dominio = dominio_new();

    if(ptr_File != NULL && linkedList != NULL && ptr_New_dominio != NULL)
    {

        do
        {
            readElements = fscanf(ptr_File,"%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2]);

            if(readElements == -1)
            {
                printf("Archivo vacio\n");
                break;
            }
            if(readElements != 3 && EOF)
            {
                printf("AAAA");
                break;
            }
            else if (readElements != 7 && !EOF)
            {
                printf("ERROR F01");
                value = 0;
                break;
            }
            else
            {
                ptr_New_dominio = dominio_new();
                if(ptr_New_dominio != NULL)
                {
                    dominio_setId(ptr_New_dominio,atoi(buffer[0]));
                    dominio_setDominio(ptr_New_dominio,buffer[1]);
                    dominio_setAnio(ptr_New_dominio,atoi(buffer[2]));
                    //dominio_setTipo(ptr_New_dominio,'x');
                    ll_add(linkedList,ptr_New_dominio);
                }
                else
                {
                    printf("ERROR_f02");
                    value = 0;
                    break;
                }
            }
        }
        while(!feof(ptr_File));

        fclose(ptr_File);
    }
    else
    {
        printf("ERROR_f03");
        value = 0;
    }

    return value;
}
// Cargar desde texto
int files_LoadFromText(char* file_path, LinkedList* linkedList)
{
    FILE* ptr_File = fopen(file_path,"r");
    int value = 0;

    if (ptr_File != NULL && file_path != NULL && linkedList != NULL)
    {

        value = files_Parser_dominioFromText(ptr_File,linkedList);

        if (value == 0)
        {
            ll_clear(linkedList);
            printf("ERROR_f04");
        }

    }
    else
    {
        value = 0;
        printf("ERROR_f05");
    }

    fclose(ptr_File);

    return value;
}

//____________Guardar en archivos diferentes.

int files_SaveAsText(char* file_path, LinkedList* linkedList)
{
    int value = 1;
    int i;
    FILE *ptr_File;
    STR_Dominio* ptr_dominio;
    ptr_File = fopen(file_path,"w");

    if(ptr_File != NULL && linkedList != NULL && file_path != NULL)
    {
        ptr_dominio = dominio_new();

        //fprintf(ptr_File, "id, nombre, horas, sueldo\n");

        for(i = 0; i < ll_len(linkedList); i++)
        {
            ptr_dominio = (STR_Dominio*) ll_get(linkedList, i);

            fprintf(ptr_File,"%d,%s,%d,%c\n", ptr_dominio->id,ptr_dominio->dominio,ptr_dominio->anio, ptr_dominio->tipo);
        }
    }
    else
    {
        value = 0;
        printf("ERROR_f06");
    }

    fclose(ptr_File);

    return value;
}
