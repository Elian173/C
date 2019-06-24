typedef struct S_Persona
{
    int edad;
    char nombre[20];
}Persona;


Persona* persona_newPersona(void);

void persona_toString(Persona* pPersona);

int persona_getEdad(Persona* pPersona);

char* persona_getNombre(Persona* pPersona);

void persona_initLista(void);

void persona_addPersona(Persona* p);

void persona_imprimirTodas();
