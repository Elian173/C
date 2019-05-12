

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
    int id; //incremental
    int idLibro;
    int idSocio; // debe existir
    str_Fecha fechaPrestamo;
    int isEmpty;

}ESTRUCTURA_Prestamos;

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

//HARDCODE//

void hardCodeLibros(ESTRUCTURA_Libros lista[]);

void hardCodeAutores(ESTRUCTURA_Autores lista[]);

void hardCodeSocios (ESTRUCTURA_Socios lista[]);

void hardCodePrestamos ( ESTRUCTURA_Prestamos lista[] );
//FUNCIONES DE MOSTRAR//

void mostrarAutores (ESTRUCTURA_Autores autor[] , int cantidadElementos) ;

void mostrarLibros (ESTRUCTURA_Libros libro[] ,ESTRUCTURA_Autores autor[] , int cantidadElementos);

void mostrarLibrosBurbujeo(ESTRUCTURA_Libros libro[] , int cantidadElementos);

void mostrarLibrosPorFechaPrestamo (ESTRUCTURA_Prestamos prestamo [],int cantidadElementos , str_Fecha fecha , ESTRUCTURA_Libros libro[]);

void mostrarTodosSocios (ESTRUCTURA_Socios socio[] , int cantidadElementos);

void mostrarUnSocio (ESTRUCTURA_Socios socio[] , int id);

void mostrarSociosPorFecha (ESTRUCTURA_Prestamos prestamo [],int cantidadElementos , str_Fecha fecha , ESTRUCTURA_Socios socio[]);

void mostrarSociosInsercion(ESTRUCTURA_Socios socios[],int cantidadElementos);

void mostrarPrestamos (ESTRUCTURA_Prestamos prestamos [] , int cantidadElementos, ESTRUCTURA_Socios socios[] , ESTRUCTURA_Libros libros[]) ;

void listarSociosPorPrestamosLibro (ESTRUCTURA_Prestamos prestamos [] , int cantidadElementos , ESTRUCTURA_Socios socio [] , int idLibro);

void listarLibrosPorPrestamodSocio (ESTRUCTURA_Prestamos prestamos[],int cantidadElementos ,ESTRUCTURA_Libros libro [],int idSocio);
//FUNCIONES INICIALIZACION//

void iniciarIncrementalSocios (ESTRUCTURA_Socios iniciando[],int cantidadElementos);

void iniciarIncrementalPrestamos (ESTRUCTURA_Prestamos iniciando[],int cantidadElementos);

void iniciarVacioSocios(ESTRUCTURA_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna);

void iniciarVacioPrestamos(ESTRUCTURA_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna);


//FUNCIONES BUSQUEDA//

int buscarPrimerIdVacioSocios (ESTRUCTURA_Socios aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia);

int buscarPrimerIdVaciosPrestamos(ESTRUCTURA_Prestamos aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia);

int estaTodoVacioSocios(ESTRUCTURA_Socios list[] , int len);

int estaTodoVacioPrestamos(ESTRUCTURA_Prestamos list[] , int len);

int buscarPorIdSocio(ESTRUCTURA_Socios socio[],int cantidadElementos,int id);

int buscarPorIdprestamo(ESTRUCTURA_Prestamos prestamos[],int cantidadElementos,int id);

int buscarIdLibro( ESTRUCTURA_Libros libros[] ,int cantidadElementos ,int id) ;

int contarSocios( ESTRUCTURA_Socios lista [] , int cantMAXelementos);


//CARGAS//

void cargarSocio (ESTRUCTURA_Socios elSocio[] , int id);

void modificarSocio (ESTRUCTURA_Socios elSocio[],int id );

int cargarPrestamo ( ESTRUCTURA_Prestamos prestamos[] , int id , ESTRUCTURA_Libros libros [] ,int cantidadDeLibros, ESTRUCTURA_Socios socios[],int cantidadDeSocios,ESTRUCTURA_Autores autores[]);

//ORDEN//

void ordenarPorApellido(ESTRUCTURA_Socios socio[], int cantidadElementos);

void sacarTotalYPromedio (ESTRUCTURA_Prestamos prestamos[], int cantidadMaxPrestamos);

