/**El objeto A puede ser una persona por ejemplo. Con un Id, Nombre, Apellido , Telefono , Sexo , Telefono , Email , Edad **/

#ifndef objectA_H_INCLUDED
#define objectA_H_INCLUDED

typedef struct
{
    int day;
    int month;
    int year;
} STR_Date;

typedef struct
{
    int id;
    char name[31];
    char lastName[31];
    char sex;
    int age;
    char phone[16];
    char email[31];
    //STR_Date date;

} STR_ObjectA;

//control
STR_ObjectA* objectA_new();
void objectA_delete(STR_ObjectA* this);
void objectA_print(STR_ObjectA* this);

//set get
int objectA_getId(STR_ObjectA* this,int* id);
int objectA_setId(STR_ObjectA* this,int id);
//
int objectA_getName(STR_ObjectA* this,char* name);
int objectA_setName(STR_ObjectA* this,char* name);
//
int objectA_getLastName(STR_ObjectA* this,char* lastName);
int objectA_setLastName(STR_ObjectA* this,char* lastName);
//
int objectA_getSex(STR_ObjectA* this,char* sex);
int objectA_setSex(STR_ObjectA* this,char sex);
//
int objectA_getAge(STR_ObjectA* this,int *age);
int objectA_setAge(STR_ObjectA* this,int age);
//
int objectA_getPhone(STR_ObjectA* this,char* phone);
int objectA_setPhone(STR_ObjectA* this,char* phone);
//
int objectA_getEmail(STR_ObjectA* this,char* email);
int objectA_setEmail(STR_ObjectA* this,char* email);
//


//Orden
int objectA_orderBy_Id(void* objectA_A, void* thisB);
int objectA_orderBy_Name(void* objectA_A, void* thisB);
#endif
