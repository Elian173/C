typedef struct{
    int dia;
    int mes;
    int anyo;
}str_Fecha;

typedef struct{
    int id; //incremental
    char nombre[31];
    char apellido[31];
    int isEmpty;
}ESTRUCTURA_Autores;

typedef struct{
    int id; //incremental
    char nombre[31];
    int idAutor; // debe existir
}ESTRUCTURA_Libros;

typedef struct{
    int id;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email [31];
    str_Fecha fechaSocio;
    int isEmpty;
}ESTRUCTURA_Socios;

typedef struct{
    int id; //incremental
    char idLibro[20];
    int idSocio; // debe existir
    str_Fecha fechaPrestamo;
    int isEmpty;

}ESTRUCTURA_Prestamos;



void hardCodeLibros(ESTRUCTURA_Libros lista[]);

void hardCodeAutores(ESTRUCTURA_Autores lista[]);





void mostrarAutores (ESTRUCTURA_Autores autor[] , int cantidadElementos) ;

void mostrarLibros (ESTRUCTURA_Libros libro[] , int cantidadElementos) ;

void mostrarTodosSocios (ESTRUCTURA_Socios socio[] , int cantidadElementos);

void mostrarUnSocio (ESTRUCTURA_Socios socio[] , int id) ;



void iniciarIncrementalSocios (ESTRUCTURA_Socios iniciando[],int cantidadElementos);

void iniciarIncrementalPrestamos (ESTRUCTURA_Prestamos iniciando[],int cantidadElementos);

void iniciarVacioSocios(ESTRUCTURA_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna);

void iniciarVacioPrestamos(ESTRUCTURA_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna);





int buscarPrimerIdVacioSocios (ESTRUCTURA_Socios aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia);

int buscarPrimerIdVaciosPrestamos(ESTRUCTURA_Prestamos aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia);

int estaTodoVacioSocios(ESTRUCTURA_Socios list[] , int len);

int estaTodoVacioPrestamos(ESTRUCTURA_Prestamos list[] , int len);

int buscarPorIdSocio(ESTRUCTURA_Socios socio[],int cantidadElementos,int id);

int buscarPorIdprestamo(ESTRUCTURA_Prestamos prestamo[],int cantidadElementos,int id);




void cargarSocio (ESTRUCTURA_Socios elSocio[] , int id);

void f_i_modificarSocio (ESTRUCTURA_Socios elSocio[] , int id );

void modificarSocio (ESTRUCTURA_Socios elSocio[] , int id );
