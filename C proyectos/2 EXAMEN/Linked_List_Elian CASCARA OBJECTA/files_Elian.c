#include <stdio.h>
#include <stdlib.h>
#include "files_Elian.h"
#include "linkedList_Elian.h"
#include "objectA_Elian.h"
#include "string.h"
#include "input_Elian.h"
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

int files_Parser_ObjectAFromText(FILE *ptr_File, LinkedList *linkedList)
{
    char buffer[7][128];
    int value = 1;
    int readElements = 0;
    STR_ObjectA* ptr_New_ObjectA = objectA_new();

    if(ptr_File != NULL && linkedList != NULL && ptr_New_ObjectA != NULL)
    {
        do
        {
            readElements = fscanf(ptr_File,
                                  "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                                  buffer[0],buffer[1],buffer[2],buffer[3],
                                  buffer[4],buffer[5],buffer[6]);
            if(readElements == -1)
            {
                printf("Archivo vacio\n");
                break;
            }
            if(readElements != 7 && EOF)
            {
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
                ptr_New_ObjectA = objectA_new();
                if(ptr_New_ObjectA != NULL)
                {
                    objectA_setId(ptr_New_ObjectA,atoi(buffer[0]));
                    objectA_setName(ptr_New_ObjectA,buffer[1]);
                    objectA_setLastName(ptr_New_ObjectA,buffer[2]);
                    objectA_setSex(ptr_New_ObjectA,buffer[3][0]);
                    objectA_setAge(ptr_New_ObjectA,atoi(buffer[4]));
                    objectA_setPhone(ptr_New_ObjectA,buffer[5]);
                    objectA_setEmail(ptr_New_ObjectA,buffer[6]);

                    ll_add(linkedList,ptr_New_ObjectA);
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

        value = files_Parser_ObjectAFromText(ptr_File,linkedList);

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

// Guardar como texto

int files_SaveAsText(char* file_path, LinkedList* linkedList)
{
    int value = 1;
    int i;
    FILE *ptr_File;
    STR_ObjectA* ptr_ObjectA;
    ptr_File = fopen(file_path,"w");

    if(ptr_File != NULL && linkedList != NULL && file_path != NULL)
    {
        ptr_ObjectA = objectA_new();

        //fprintf(ptr_File, "id, nombre, horas, sueldo\n");

        for(i = 0; i < ll_len(linkedList); i++)
        {
            ptr_ObjectA = (STR_ObjectA*) ll_get(linkedList, i);

            fprintf(ptr_File,"%d,%s,%s,%c,%d,%s,%s\n", ptr_ObjectA->id, ptr_ObjectA->name,ptr_ObjectA->lastName,ptr_ObjectA->sex,
                    ptr_ObjectA->age,ptr_ObjectA->phone,ptr_ObjectA->email);
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

//_________________________________________________BINARIO____________________________________________//


int files_CreateFileBinary(char* file_Path)
{
    int value = 1;
    FILE* ptr_File;

    if ((ptr_File = fopen(file_Path,"rb+")) == NULL)
    {
        if ((ptr_File = fopen(file_Path,"wb+")) == NULL)
        {
            printf("ERROR F07");
            value = 0;
        }
    }

    fclose(ptr_File);

    return value;
}

//cargar binario

int files_LoadFromBinary(char* path, LinkedList* linkedList)
{
    FILE* ptr_File = fopen(path, "rb");
    int value = 0;

    if (ptr_File != NULL && path != NULL && linkedList != NULL)
    {
        value = files_Parser_ObjectAFromBinary(ptr_File, linkedList);
    }
    else
    {
        printf("ERROR F08");
        value = 0;//El archivo no existe
    }

    fclose(ptr_File);

    return value;
}

//parser binario

int files_Parser_ObjectAFromBinary(FILE *ptr_File, LinkedList *linkedList)
{

    int value = 1;
    int readLine ;
    int index_error;
    STR_ObjectA* ptr_ObjectA;

    if(ptr_File != NULL && linkedList != NULL)
    {

        while(!feof(ptr_File))
        {
            ptr_ObjectA = objectA_new();
            readLine = fread(ptr_ObjectA, sizeof(STR_ObjectA),1, ptr_File);

            if(readLine != 1 && !EOF)
            {
                printf("ERRORF09");
                index_error = ll_indexOf(linkedList,ptr_ObjectA);
                ll_remove(linkedList,index_error);
            }

            if(readLine != 1 && EOF)
            {

              break;

            }

            ll_add(linkedList, ptr_ObjectA);


        }
    }
    else
    {
        printf("Archivo vacio\n");
        value = 0 ;
    }

    return value;
}


//guardar binario

int files_SaveAsBinary(char* file_path, LinkedList* linkedList)
{
    int value = 1;
    int i;
    FILE *ptr_File;
    STR_ObjectA* ptr_ObjectA;
    ptr_File = fopen(file_path,"wb");

    if(linkedList != NULL && file_path != NULL && ptr_File != NULL)
    {
        for(i = 0 ; i < ll_len(linkedList); i++)
        {
            ptr_ObjectA = (STR_ObjectA*) ll_get(linkedList, i);
            fwrite(ptr_ObjectA, sizeof(STR_ObjectA), 1, ptr_File );
        }
        fclose(ptr_File);
    }
    else
    {
        value = 0;
    }

    return value;

}



/*
#include <stdio.h>
#include <stdlib.h>

id,first_name,last_name,is_empty
1,Eric,Knight,false

int main()
{

    FILE *pFile,*pFileW;
    int i=0;
    char var1[50],var3[50],var2[50],var4[50];

    pFile = fopen("data.csv","r");
    pFileW = fopen("data2.csv","w");

    if(pFile != NULL)
        printf("SIIIIIIIIIIIIIIIII");

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        fprintf(pFileW,"%s-%s-%s-%s\n",var1,var2,var3,var4);
        i++;
        if(i > 20)
            break;

    }
    return 0;
}
*/
