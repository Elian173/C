#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_Elian.h"
#include "objectA_Elian.h"

STR_ObjectA* objectA_new()
{
    STR_ObjectA* ptr_ObjectA = (STR_ObjectA*)malloc(sizeof(STR_ObjectA));

    return ptr_ObjectA;
}

void objectA_delete (STR_ObjectA *ptr_ObjectA)
{
    if(ptr_ObjectA != NULL)
    {
        free(ptr_ObjectA);
    }
    return;
}

void objectA_print(STR_ObjectA* ptr_ObjectA)
{
    if(ptr_ObjectA != NULL)
    {
        printf("%4d %-10s %-10s %c %2d %15s %-31s\n", ptr_ObjectA->id, ptr_ObjectA->name,ptr_ObjectA->lastName,ptr_ObjectA->sex,
               ptr_ObjectA->age,ptr_ObjectA->phone,ptr_ObjectA->email);
    }
}
//___________________________________________________________SET Y GET______________________________________________________//

int objectA_setId(STR_ObjectA* ptr_ObjectA, int id)
{
    int value = 0;

    if(ptr_ObjectA != NULL && id > 0)
    {
        ptr_ObjectA->id = id;
        value = 1;
    }
    return value;
}

int objectA_getId(STR_ObjectA* ptr_ObjectA, int* id)
{

    int value = 0;
    if(ptr_ObjectA != NULL)
    {
        *id = ptr_ObjectA->id ;
        value = 1;
    }
    return value;
}

//

int objectA_setName(STR_ObjectA* ptr_ObjectA, char* name)
{
    int value = 0;

    if(ptr_ObjectA != NULL && name != NULL)
    {
        strncpy(ptr_ObjectA->name, name, sizeof(ptr_ObjectA->name));
        value = 1;
    }
    return value;
}

int objectA_getName(STR_ObjectA* ptr_ObjectA, char* name)
{
    int value = 0;

    if(ptr_ObjectA != NULL && name != NULL)
    {
        strcpy(name, ptr_ObjectA->name);
        value = 1;
    }
    return value;
}

//

int objectA_setLastName(STR_ObjectA* ptr_ObjectA, char* lastName)
{
    int value = 0;

    if(ptr_ObjectA != NULL && lastName != NULL)
    {
        strncpy(ptr_ObjectA->lastName, lastName, sizeof(ptr_ObjectA->lastName));
        value = 1;
    }
    return value;
}

int objectA_getLastName(STR_ObjectA* ptr_ObjectA, char* lastName)
{
    int value = 0;

    if(ptr_ObjectA != NULL && lastName != NULL)
    {
        strcpy(lastName, ptr_ObjectA->lastName);
        value = 1;
    }
    return value;
}

//

int objectA_setSex(STR_ObjectA* ptr_ObjectA, char sex)
{
    int value = 0;

    if(ptr_ObjectA != NULL)
    {
        ptr_ObjectA->sex = sex;
        value = 1;
    }
    return value;
}

int objectA_getSex(STR_ObjectA* ptr_ObjectA, char* sex)
{
    int value = 0;

    if(ptr_ObjectA != NULL && sex != NULL)
    {
        *sex = ptr_ObjectA->sex;
        value = 1;
    }
    return value;
}

//

int objectA_setPhone(STR_ObjectA* ptr_ObjectA, char* phone)
{
    int value = 0;

    if(ptr_ObjectA != NULL && phone != NULL)
    {
        strncpy(ptr_ObjectA->phone, phone, sizeof(ptr_ObjectA->phone));
        value = 1;
    }
    return value;
}

int objectA_getPhone(STR_ObjectA* ptr_ObjectA, char* phone)
{
    int value = 0;

    if(ptr_ObjectA != NULL && phone != NULL)
    {
        strcpy(phone, ptr_ObjectA->phone);
        value = 1;
    }
    return value;
}

//

int objectA_setEmail(STR_ObjectA* ptr_ObjectA, char* email)
{
    int value = 0;

    if(ptr_ObjectA != NULL && email != NULL)
    {
        strncpy(ptr_ObjectA->email, email, sizeof(ptr_ObjectA->email));
        value = 1;
    }
    return value;
}

int objectA_getEmail(STR_ObjectA* ptr_ObjectA, char* email)
{
    int value = 0;

    if(ptr_ObjectA != NULL && email != NULL)
    {
        strcpy(email, ptr_ObjectA->email);
        value = 1;
    }
    return value;
}

//

int objectA_setAge(STR_ObjectA* ptr_ObjectA, int age)
{
    int value = 0;

    if(ptr_ObjectA != NULL)
    {
        ptr_ObjectA->age = age;
        value = 1;
    }
    return value;
}

int objectA_getAge(STR_ObjectA* ptr_ObjectA, int* age)
{
    int value = 0;

    if(ptr_ObjectA != NULL)
    {
        *age = ptr_ObjectA->age;
        value = 1;
    }
    return value;
}
//___________________________________________________________ORDEN______________________________________________________//

int objectA_orderBy_Name(void* ptr_ObjectA_A, void* ptr_ObjectA_B)
{
    int value;

    char* bufferA = (char*) malloc (sizeof(char)*128);
    char* bufferB = (char*) malloc (sizeof(char)*128);

    objectA_getName(ptr_ObjectA_A,bufferA);
    objectA_getName(ptr_ObjectA_B,bufferB);

    if(strcmp(bufferA,bufferB) < 0)
    {
        value = 1;
    }
    else if(strcmp(bufferA,bufferB) > 0)
    {
        value = -1;
    }
    else
    {
        value = 0;
    }

    free(bufferA);
    free(bufferB);

    return value;
}

//

int objectA_orderBy_Id(void* ptr_ObjectA_A, void* ptr_ObjectA_B)
{
    int value;
    int bufferA;
    int bufferB;

    objectA_getId(ptr_ObjectA_A,&bufferA);
    objectA_getId(ptr_ObjectA_B,&bufferB);

    if(bufferA < bufferB)
    {
        value = 1;
    }
    else if(bufferA > bufferB)
    {
        value = -1;
    }
    else
    {
        value = 0;
    }
    return value;
}
