#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    Person* personArray[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i+100);
    }
    /*for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }*/
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",personArray[i]->age);
    }
    scanf(" ");
    return 0;
}

//LO MISMO PERO HAY QUE PEDIR LOS DATOSSS HASTA Q EL USUARIO QUIERA-//
//SI SE QUIEREN DAR MAS DE ALTAS DE LOS QUE HAY LUGAR , HACER REALOC//
