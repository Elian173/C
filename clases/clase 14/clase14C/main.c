#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre [21];
    int edad;
    int dni;
}S_Person;

int loadPerson(S_Person* alguien);

void printPerson(S_Person* alguien);

int main()
{
    S_Person alguien;

    loadPerson(&alguien);


    printf("Hello world!\n");
    return 0;
}

int loadPerson (S_Person* alguien){


    printf("nombre:\n");
    fgets(alguien.nombre,21,stdin);
    printf("edad:\n");
    scanf("%d",alguien.edad);
    printf("dni:\n");
    scanf("%d",alguien.dni);

    return 1;
}
