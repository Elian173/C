#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "libros.h"
#include "InputElian.h"

//Hardcode//

void hardCodeLibros(ESTRUCTURA_Libros lista[]){
    int i;
    ESTRUCTURA_Libros ejemplos[]=
    {
        {1, "libroUno", 10},
        {2, "libroDos", 9},
        {3, "libroTres", 8},
        {4, "libroCuatro",7 },
        {5, "libroCinco" ,6},
        {6, "libroSeis",5},
        {7, "libroSiete",5},
        {8, "libroOcho", 5},
        {9, "libroNueve", 1},
        {10, "libroDiez", 1}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeAutores(ESTRUCTURA_Autores lista[]){
    int i;
    ESTRUCTURA_Autores ejemplos[]=
    {
        {1, "autorUNO", "AAAAAA", 0},
        {2, "autorDOS","BBBBBB", 0},
        {3, "autorTRES","PPPPPPPP", 0},
        {4, "autorCUATRO","DDDDDD",0 },
        {5, "autorCINCO" ,"SSSSSSSS" ,0},
        {6, "autorSEIS" ,"ZZZZZZZZZ" ,0},
        {7, "autorSIETE","XXXXXXXXXX",0},
        {8, "autorOCHO","TTTTTT", 0},
        {9, "autorNUEVE","UUUUUUUU", 0},
        {10,"autorDIEZ","IIIIII", 0},
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeSocios (ESTRUCTURA_Socios lista[]){

    int i;

    str_Fecha fecha = {1,4,2000};

    ESTRUCTURA_Socios ejemplo[]=
    {


        {1, "unoSocio", "aaa" ,'M', "11111111" ,"pepito@gmail.com",fecha,0},
        {2, "dos", "kkkkkk",'M', "18001210" , "pepito@gmail.com",fecha,0},
        {3, "tres", "jjj",'M', "324234342" , "pepito@gmail.com",fecha,0},
        {4, "cuatro", "ppppp",'F' ,"32324342" , "pepito@gmail.com",fecha, 0},
        {5, "cinco", "bbb" ,'M', "67555656" , "pepito@gmail.com",fecha, 0},
        {6, "seis", "ccc" ,'F'," 36663636" ,"pepito@gmail.com",fecha, 0},
        {7, "siete", "iiiii" ,'M'," 2622262" , "pepito@gmail.com",fecha,0},
        {8, "ocho", "wwww" ,'M', "262444445" ,"pepito@gmail.com",fecha, 0},
        {9, "nueve", "kkkkkk" ,'M', "8798978905" ,"pepito@gmail.com",fecha, 0},
        {10, "diez", "kkkkkk" ,'F', "456546545" , "pepito@gmail.com",fecha,0}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplo[i];
    };

}

void hardCodePrestamos ( ESTRUCTURA_Prestamos lista[] ){

    int i;

    str_Fecha fecha = {1,4,2000};

    ESTRUCTURA_Prestamos ejemplo[]=
    {


        {10,10, 10 , fecha ,0},
        {9, 9, 9,fecha ,0},
        {8, 8 , 8 , fecha,0},
        {7,  7,  7, fecha,0},
        {6, 6 , 6 , fecha,0},
        {5, 5, 5 , fecha,0},
        {4,  4, 4 , fecha,0},
        {3, 3 ,3  , fecha,0},
        {2,  2 ,2  , fecha,0},
        {1, 1 , 1 , fecha,0},
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplo[i];
    };


}

//Funciones de mostrar//

/** \brief Imprime una lista completa de todos los autores cargados
 * \param autor[] es el array de autores
 * \param cantidadElementos es la cantidad maxima de autores
 * \return void
 */
void mostrarAutores (ESTRUCTURA_Autores autor[] , int cantidadElementos) {

    ESTRUCTURA_Autores aux;
    int i,j;

    for(i=0; i<cantidadElementos-1; i++)
    {
    for(j=i+1; j<cantidadElementos; j++)
    {
        if( strcmp( autor[i].apellido , autor[j].apellido)>0 ){
            aux = autor[j];
            autor[j] = autor[i];
            autor[i] = aux;
        };
    };
    };

    printf("AUTORES\n");
    printf("Codigo: Apellido y Nombre\n\n");

        for(i=0;i<cantidadElementos;i++){
        if (autor[i].isEmpty == 0){
            printf("%3d %s %s\n",autor[i].id,autor[i].apellido,autor[i].nombre);
        };
        };
    return;
}

/** \brief Imprime una lista completa de todos libros que concuerden con la fecha dada
 * \param prestamo[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \param fecha es la fecha que se le pide al usuario
 * \param libro es el array de libros
 * \return void
 */
void mostrarLibrosPorFechaPrestamo (ESTRUCTURA_Prestamos prestamo [],int cantidadElementos , str_Fecha fecha , ESTRUCTURA_Libros libro[]){

    int i;
    printf("LIBROS:\n");
    printf("Codigo  Nombre:\n\n");

        for(i=0;i<cantidadElementos;i++){

            if (( prestamo[i].fechaPrestamo.dia == fecha.dia) && (prestamo[i].fechaPrestamo.mes == fecha.mes ) &&(prestamo[i].fechaPrestamo.anyo == fecha.anyo))
                {

                printf("%3d-     %-20.16s\n", libro[i].id,libro[i].nombre);
        };
        };

}


/** \brief Imprime una lista completa de todos libros que concuerden con la fecha dada
 * \param prestamo[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \param fecha es la fecha que se le pide al usuario
 * \param libro es el array de libros
 * \return void
 */
void mostrarSociosPorFecha (ESTRUCTURA_Prestamos prestamo [],int cantidadElementos , str_Fecha fecha , ESTRUCTURA_Socios socio[]){

    int i;
    printf("Socios:\n");
    printf("Codigo  Nombre:\n\n");

        for(i=0;i<cantidadElementos;i++){

            if (( prestamo[i].fechaPrestamo.dia == fecha.dia) && (prestamo[i].fechaPrestamo.mes == fecha.mes ) &&(prestamo[i].fechaPrestamo.anyo == fecha.anyo))
                {

                printf("%3d-     %s%s\n", socio[i].id,socio[i].nombre,socio[i].apellido);
        };
        };

}


/** \brief Imprime una lista completa de todos los libros cargados , y sus autores
 * \param libro[] es el array de libros
  * \param autor[] es el array de autores
 * \param cantidadElementos es la cantidad maxima de libros
 * \return void
 */
void mostrarLibros (ESTRUCTURA_Libros libro[] ,ESTRUCTURA_Autores autor[] , int cantidadElementos) {

    //ordeno por titulo//
    ESTRUCTURA_Libros aux;
    int i,j;
    for(i=0; i<cantidadElementos-1; i++)
    {
    for(j=i+1; j<cantidadElementos; j++)
    {
    if( strcmp( libro[i].nombre , libro[j].nombre)>0 ){
        aux = libro[j];
        libro[j] = libro[i];
        libro[i] = aux;
        };
    };

    };
    ////////////

    printf("LIBROS:\n");
    printf("Codigo  Nombre:     Codigo Autor: Autor:\n\n");

        for(i=0;i<cantidadElementos;i++){

            printf("%3d-     %-20.16s %3d- %s %s\n", libro[i].id,libro[i].nombre,libro[i].idAutor,autor[libro[i].idAutor-1].nombre,autor[libro[i].idAutor-1].apellido);

        };

    return;
}
/** \brief Imprime una lista completa de todos los libros alfabeticamente por burbujeo
 * \param idLibro es el codigo de libro
 * \param socios[] es el array de autores
 * \param prestamos[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */

void mostrarLibrosBurbujeo(ESTRUCTURA_Libros libro[] , int cantidadElementos){

    int j,i;
    ESTRUCTURA_Libros aux;
    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {
    flagNoEstaOrdenado = 0;
        for (j = 1; j < cantidadElementos ; j++){

            if ( strcmp( libro[j].nombre , libro[j-1].nombre)>0){
                aux = libro[j];
                libro[j] = libro[j-1];
                libro[j-1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }

    printf("LIBROS:\n");
    printf("Codigo  Nombre:\n\n");

        for(i=0;i<cantidadElementos;i++){

            printf("%3d-     %-20.16s\n", libro[i].id,libro[i].nombre);

        };
}

/** \brief Imprime una lista completa de todos los socios cargados
  * \param socio[] es el array de autores
 * \param cantidadElementos es la cantidad maxima de socios
 * \return void
 */
void mostrarTodosSocios (ESTRUCTURA_Socios socio[] , int cantidadElementos) {

        int i , totalSocios;
        char auxNombreSocio [90];

        totalSocios = contarSocios(socio,cantidadElementos);
        ordenarPorApellido(socio,totalSocios);


        printf("Codigo-Apellido y nombre:            -Sexo-Telefono:        -Email:\n\n");

        for(i=0;i<cantidadElementos;i++){

            if (socio[i].isEmpty == 0){

                strcpy(auxNombreSocio , socio[i].apellido);
                strcat(auxNombreSocio," ");
                strcat(auxNombreSocio , socio[i].nombre);

                printf("%4d - %-30.60s -%1c-%18.20s -%s\n", socio[i].id ,auxNombreSocio,socio[i].sexo,socio[i].telefono,socio[i].email);
            };
        };

    return;

}

/** \brief Imprime los datos de un solo socio
 * \param socio[] es el socio a mostrar
  * \param id es el codigo del socio
 * \return void
 */
void mostrarUnSocio (ESTRUCTURA_Socios socio[] , int id) {

    char auxNombreSocio [90];

    strcpy(auxNombreSocio , socio[id].apellido);
    strcat(auxNombreSocio," ");
    strcat(auxNombreSocio , socio[id].nombre);

    printf("Codigo-Apellido y nombre:            -Sexo-Telefono:        -Email:\n\n");
    printf("%4d - %-30.60s -%1c-%18.20s -%s\n", socio[id].id, auxNombreSocio ,socio[id].sexo,socio[id].telefono,socio[id].email);

    return;

}

/** \brief Imprime una lista completa de todos los socios cargados ordenados alfabeticamente por insercion
 * \param socios[] es el array de autores
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */
 void mostrarSociosInsercion(ESTRUCTURA_Socios socio[],int cantidadElementos){

    int i,j;
    ESTRUCTURA_Socios temp;
    char auxNombreSocio [90];

    for(i=1 ; i<cantidadElementos ; i++) {

        temp = socio[i];

        j=i-1;

        while(j>=0 && (strcmp (temp.apellido,socio[j].apellido) < 0) ){

        socio[j+1] = socio[j];
        j--;
        }

    socio[j+1]=temp;

    }

    printf("Codigo-Apellido y nombre:            -Sexo-Telefono:        -Email:\n\n");

        for(i=0;i<cantidadElementos;i++){

            if (socio[i].isEmpty == 0){

                strcpy(auxNombreSocio , socio[i].apellido);
                strcat(auxNombreSocio," ");
                strcat(auxNombreSocio , socio[i].nombre);

                printf("%4d - %-30.60s -%1c-%18.20s -%s\n", socio[i].id ,auxNombreSocio,socio[i].sexo,socio[i].telefono,socio[i].email);
            };
        };

    return;
}


/** \brief Imprime una lista completa de todos los prestamos cargados
 * \param libros[] es el array de libros
 * \param socios[] es el array de autores
 * \param prestamos[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */
void mostrarPrestamos (ESTRUCTURA_Prestamos prestamos [] , int cantidadElementos, ESTRUCTURA_Socios socios[] , ESTRUCTURA_Libros libros[]) {

    int i;
    char auxNombreSocio[90];

    printf("PRESTAMOS:\n");
    printf("Codigo -Socio:                          -Libro:             Fecha:\n\n");

        for(i=0; i < cantidadElementos;i++){

            if (prestamos[i].isEmpty == 0){

                strcpy(auxNombreSocio , socios[prestamos[i].idSocio-1].apellido);
                strcat(auxNombreSocio," ");
                strcat(auxNombreSocio , socios[prestamos[i].idSocio-1].nombre);

                printf("%4d    %-30.60s %-20.16s %2d/%2d/%4d\n" ,prestamos[i].id,auxNombreSocio, libros[prestamos[i].idLibro-1].nombre ,
                prestamos[i].fechaPrestamo.dia , prestamos[i].fechaPrestamo.mes , prestamos[i].fechaPrestamo.anyo );
            };
        };

    return;

}


/** \brief Imprime una lista completa de todos los socios que pidieron determinado libro
 * \param idLibro es el codigo de libro
 * \param socios[] es el array de socios
 * \param prestamos[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */
void listarSociosPorPrestamosLibro (ESTRUCTURA_Prestamos prestamos [] , int cantidadElementos , ESTRUCTURA_Socios socio [] , int idLibro){

    int i=0;
    char auxNombreSocio [90];

    printf("\nEl libro codigo %d fue prestado a:\n",idLibro);

    printf("Apellido y nombre:            -Sexo-Telefono:        -Email:\n\n");

    for ( i = 0 ; i<cantidadElementos ; i++){

        if (prestamos[i].idLibro == idLibro ){

        strcpy(auxNombreSocio , socio[prestamos[i].idSocio].apellido);
        strcat(auxNombreSocio," ");
        strcat(auxNombreSocio , socio[prestamos[i].idSocio].nombre);

        printf("%s - %1c - %18.20s -%s\n", auxNombreSocio ,socio[prestamos[i].idSocio].sexo,socio[prestamos[i].idSocio].telefono,socio[prestamos[i].idSocio].email);

        };
    };

    return;

}


/** \brief Imprime una lista completa de todos los libros que pidieron determinado socio
 * \param idsocio es el codigo de socio
 * \param libro[] es el array de libros
 * \param prestamos[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */
void listarLibrosPorPrestamodSocio (ESTRUCTURA_Prestamos prestamos[],int cantidadElementos ,ESTRUCTURA_Libros libro [] , int idSocio){

    int i=0;

    printf("\nLibros prestados al socio %d son:\n",idSocio);

    printf("Libro :\n\n");

    for ( i = 0 ; i<cantidadElementos ; i++){
        if (prestamos[i].idSocio == idSocio ){

        printf("%-30.60s\n", libro[i].nombre );

        }
    };

    return;

}



//Funciones inicializacion//

/**\brief Recibe un array de socios y iguala sus codigos a un valor incremental
 * \param iniciando[] es el array de socios
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \return void
 */
void iniciarIncrementalSocios (ESTRUCTURA_Socios iniciando[],int cantidadElementos){
    int i;
    for(i=0;i < cantidadElementos ; i++){

        iniciando[i].id = i+1;

    }
    return;
}

/**\brief Recibe un array de prestamos y iguala sus codigos a un valor incremental
 * \param iniciando[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \return void
 */
void iniciarIncrementalPrestamos (ESTRUCTURA_Prestamos iniciando[],int cantidadElementos){
    int i;
    for(i=0;i < cantidadElementos ; i++){

        iniciando[i].id = i+1;

    };

    return;
}

/**\brief Recibe un array de socios y iguala sus elementos isEmpty a un valor = (numeroQueseAsigna)
 * \param iniciando[] es el array de socios
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \param numeroQueSeAsigna es el numero que se le asigna a cada parametro isEmpty
 * \return void
 */
void iniciarVacioSocios(ESTRUCTURA_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna){
    int i;
    for(i=0;i < cantidadElementos ; i++){

        iniciando[i].isEmpty = numeroQueSeAsigna;

    };
    return;
}

/**\brief Recibe un array de prestamos y iguala sus elementos isEmpty a un valor = (numeroQueseAsigna)
 * \param iniciando[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \param numeroQueSeAsigna es el numero que se le asigna a cada parametro isEmpty
 * \return void
 */
void iniciarVacioPrestamos(ESTRUCTURA_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna){
    int i;
    for(i=0;i < cantidadElementos ; i++){

        iniciando[i].isEmpty = numeroQueSeAsigna;

    };

    return;
}


//Funciones de busqueda//

//-1 si no encuentra//

/**\brief Recibe un array de socios y busca el id del primer parametro con .isEmpty == (indicadorPrimerOcurrencia)
 * \param aBuscar[] es el array de socios
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \param indicadorPrimerOcurrencia es el numero que se busca en el parametro isEmpty
 * \return id del primer parametro con .isEmpty == (indicadorPrimerOcurrencia) , -1 si no encuentra
 */
int buscarPrimerIdVacioSocios (ESTRUCTURA_Socios aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia){

    int i;

    for (i=0;i<cantidadElementos;i++){
        if (aBuscar[i].isEmpty == indicadorPrimerOcurrencia){

            return i;

        };
    };

    return -1;

}

/**\brief Recibe un array de prestamos y busca el id del primer parametro con .isEmpty == (indicadorPrimerOcurrencia)
 * \param aBuscar[] es el array de prestamos
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array iniciando[]
 * \param indicadorPrimerOcurrencia es el numero que se busca en el parametro isEmpty
 * \return id del primer parametro con .isEmpty == (indicadorPrimerOcurrencia) , -1 si no encuentra
 */
int buscarPrimerIdVaciosPrestamos(ESTRUCTURA_Prestamos aBuscar[],int cantidadElementos,int indicadorPrimerOcurrencia){

    int i;

    for (i=0;i<cantidadElementos;i++){

        if (aBuscar[i].isEmpty == indicadorPrimerOcurrencia){

            return i;

        };
    };

    return -1;

}

/**\brief Recibe un array de socios y verifica si tiene datos cargados
 * \param list[] es el array de socios
 * \param len es la cantidad maxima de elementos que tiene el array list[]
 * \return 0 si hay datos cargado , 1 si no hay datos cargados
 */
int estaTodoVacioSocios(ESTRUCTURA_Socios list[] , int len){

    int i;

    for(i=0;i < len ; i++){

        if (list[i].isEmpty != 1){

            return 0;

        };
    };

    return 1;

}

/**\brief Recibe un array de prestamos y verifica si tiene datos cargados
 * \param list[] es el array de prestamos
 * \param len es la cantidad maxima de elementos que tiene el array list[]
 * \return 0 si hay datos cargado , 1 si no hay datos cargados
 */
int estaTodoVacioPrestamos(ESTRUCTURA_Prestamos list[] , int len){

    int i;

    for(i=0;i < len ; i++){

        if (list[i].isEmpty != 1){

            return 0;
        };

    };

    return 1;

}

/**\brief Recibe un array de socios y busca el id que se le pida , verifica que no este vacio y devuelve el indice
 * \param socio[] es el array de socios donde se busca el id
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array socio[]
 * \param id es el numero que se busca
 * \return indice del id pedido , -1 si no encuentra ,o ese id esta vacio
 */
int buscarPorIdSocio(ESTRUCTURA_Socios socio[] ,int cantidadElementos,int id){

    int i;

    for(i=0;i < cantidadElementos; i++){

        if(socio[i].id == id && socio[i].isEmpty == 0){

            return i;

        };
    };

    return -1;

}

/**\brief Recibe un array de prestamos y busca el id que se le pida , verifica que no este vacio y devuelve el indice
 * \param prestamo[] es el array de prestamos donde se busca el id
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array prestamo[]
 * \param id es el numero que se busca
 * \return indice del id pedido , -1 si no encuentra ,o ese id esta vacio
 */
int buscarPorIdprestamo(ESTRUCTURA_Prestamos prestamo[],int cantidadElementos,int id){

    int i;

    for(i=0;i < cantidadElementos; i++){

        if(prestamo[i].id == id && prestamo[i].isEmpty == 0){

            return i;

        };
    };

    return -1;

}

/**\brief Recibe un array de libros y busca el id que se le pida , verifica que no este vacio y devuelve el indice
 * \param libros[] es el array de libros donde se busca el id
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array libro[]
 * \param id es el numero que se busca
 * \return indice del id pedido , -1 si no encuentra
 */
int buscarIdLibro( ESTRUCTURA_Libros libros[] ,int cantidadElementos ,int id) {

    int i;

    for ( i=0; i < cantidadElementos ; i++ ){

        if (libros[i].id == id){

        return i;

        };
    };

    return -1;

}

/**\brief Recibe un array de socios y cuenta la cantidad que tienen parametro isEmpty == 0
 * \param lista[] es el array de socios
 * \param cantMAXelementos es la cantidad maxima de elementos que tiene el array lista[]
 * \return  cantidad que tienen parametro isEmpty == 0
 */
int contarSocios( ESTRUCTURA_Socios lista [] , int cantMAXelementos){

    int i , total = 0 ;

    for (i=0;i<cantMAXelementos;i++){

        if (lista[i].isEmpty == 0){
            total++;
        }
    };

    return total;

}


//CARGAS//

/**\brief Recibe un array de socios , valida y carga  todos los datos de un socio en el id que se le indique
 * \param elSocio[] es el array de socios
 * \param id es el indice donde cargar los datos
 * \return void
 */
void cargarSocio (ESTRUCTURA_Socios elSocio[] , int id){

    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];
    str_Fecha auxfecha;



    f_i_PedirNombre(auxName , 31 , "\nIngrese el Nombre del socio:");

    f_i_PedirNombre(auxLastName , 31 , "\nIngrese el Apellido del socio:");

    f_i_PedirSexo(&auxSexo , "\nIngrese el sexo del socio:");

    f_i_PedirTelefono(auxTelef,16,"\nIngrese el telefono del socio:");

    f_i_PedirEmail(auxEmail , 31 , "\nIngrese el email del socio:");

    f_i_PedirIntEntre(&auxfecha.dia , 1 , 31 , "\nIngrese el dia de ingreso del socio");

    f_i_PedirIntEntre(&auxfecha.mes , 1 , 12 , "\nIngrese el mes de ingreso del socio (1 al 12)");

    f_i_PedirIntEntre(&auxfecha.anyo , 1900 , 2020 , "\nIngrese el anyo de ingreso del socio");


    strcpy(elSocio[id].nombre , auxName);
    strcpy(elSocio[id].apellido , auxLastName);
    elSocio[id].sexo = auxSexo;
    strcpy(elSocio[id].telefono , auxTelef);
    strcpy(elSocio[id].email , auxEmail);
    elSocio[id].fechaSocio = auxfecha;
    elSocio[id].isEmpty = 0;

    printf("\nSocio cargado correctamente\n");

    f_i_continuar();
    fflush(stdin);

}

/**\brief Recibe un array de socios y perdite modificar los parametros de un socio especifico en el id que se le indique
 * \param list[] es el array de socios
 * \param id es el indice donde modificar los datos
 * \return void
 */
void modificarSocio (ESTRUCTURA_Socios list [] , int id ){

    int opcion;
    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];


    f_i_PedirIntEntre(&opcion,1,6,"\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Sexo\n"
                      "4-Modificar Telefono\n5-Modificar Email\n6-Salir\nOpcion : ");


    switch (opcion){

    case 1 :f_i_PedirNombre(auxName,31,"\nIngrese el Nombre del Socio:\n");
            strcpy(list[id].nombre,auxName);
            break;

    case 2 :f_i_PedirNombre(auxLastName,31,"\nIngrese el Apellido del Socio:\n");
            strcpy(list[id].apellido,auxLastName);
            break;

    case 3 :f_i_PedirSexo(&auxSexo,"\nIngrese el sexo del Socio:\n");
            list[id].sexo = auxSexo;
            break;

    case 4 :f_i_PedirTelefono(auxTelef,16,"\nIngrese el Telefono del Socio:\n");
            strcpy(list[id].telefono,auxTelef);
            break;

    case 5 :f_i_PedirEmail(auxEmail,31,"\nIngrese el Email del Socio:\n");
            strcpy(list[id].email,auxEmail);
            break;

    case 7 :

        break;
    }

    printf("\n*Socio Modificado Correctamente*\n");
    return;

    }

/**\brief Recibe un array de prestamos , valida y carga  todos los datos de un prestamo en el id que se le indique
 * \param prestamos[] es el array de prestamos
 * \param id es el indice donde cargar los datos
 * \param libros[] es donde se encuentran los datos de los libros
 * \param cantidadDeLibros es la cantidad maxima de libros
 * \param socios[] es donde se encuentran los datos de los socios
 * \param cantidadDeSocios es la cantidad maxima de socios
 * \return 0 si se carga exitosamente , -1 si no se carga el prestamo
 */
int cargarPrestamo ( ESTRUCTURA_Prestamos prestamos[] , int id , ESTRUCTURA_Libros libros [] ,int cantidadDeLibros, ESTRUCTURA_Socios socios[],int cantidadDeSocios , ESTRUCTURA_Autores autores[]){

        int auxIdLibro;
        int auxIdSocio;
        str_Fecha auxFecha;
        limpiar();

        mostrarLibros(libros,autores,cantidadDeLibros);

        f_i_PedirIntEntre( &auxIdLibro , 1 , cantidadDeLibros ,"\nIngrese el CODIGO del libro:\n");

        auxIdLibro = buscarIdLibro( libros , cantidadDeLibros , auxIdLibro);

        if (auxIdLibro == -1 ){
            printf("\nEl libro ingresado no esta cargado en el sistema\n");
            return -1;

        } else {

        auxIdLibro = auxIdLibro +1;
        prestamos[id].idLibro = auxIdLibro;

        };

        limpiar();

        mostrarTodosSocios(socios,cantidadDeSocios);

        f_i_PedirIntEntre( &auxIdSocio , 1 , cantidadDeSocios , "\nIngrese el CODIGO del socio\n");

        auxIdSocio = buscarPorIdSocio(  socios , cantidadDeSocios , auxIdSocio );

        if (auxIdSocio == -1){

            printf("\nEl socio ingresado no esta cargado en el sistema\n");
            return -1;

        } else {

        auxIdSocio = auxIdSocio+1;
        prestamos[id].idSocio = auxIdSocio;

        };

        limpiar();

        f_i_PedirIntEntre(&auxFecha.dia, 1 , 31 , "\nIngrese el dia de prestamo:");

        f_i_PedirIntEntre(&auxFecha.mes, 1 , 12 , "\nIngrese el mes de prestamo (1 al 12):");

        f_i_PedirIntEntre(&auxFecha.anyo, 1900 , 2020 , "\nIngrese el anyo de prestamo:");
        prestamos[id].fechaPrestamo = auxFecha;

        prestamos[id].isEmpty = 0;

        return 0;

}


//ORDEN//

/** \brief ordena un array de socios por apellido
 * \param socios[] es el array de autores
 * \param cantidadElementos es la cantidad maxima de prestamos
 * \return void
 */
void ordenarPorApellido(ESTRUCTURA_Socios socio[], int cantidadElementos){

    ESTRUCTURA_Socios aux;
    int i,j;

    for(i=0; i<cantidadElementos-1; i++){

    for(j=i+1; j<cantidadElementos; j++)
    {
        if( strcmp( socio[i].apellido , socio[j].apellido)>0 ){
            aux = socio[j];
            socio[j] = socio[i];
            socio[i] = aux;
        };

        if ( strcmp(  socio[i].apellido,socio[j].apellido) == 0 ){

            if( strcmp( socio[i].nombre , socio[j].nombre)>0 ){
            aux = socio[j];
            socio[j] = socio[i];
            socio[i] = aux;
            };
        };
    };
    };

    return;

}


/** \brief saca el total de prestamos cargados
 * \param prestamos[] es el array de prestamos
 * \param cantidadMaxElementos es la cantidad maxima de prestamos
 * \return void
 */
void sacarTotalYPromedio (ESTRUCTURA_Prestamos prestamos[], int cantidadMaxPrestamos){

    int i  , totalPrestamos = 0  ;

    for (i=0 ; i< cantidadMaxPrestamos ; i++){
        if (prestamos[i].isEmpty==0){
            totalPrestamos ++ ;
        };
    };

    printf("La cantidad total de prestamos es : %d",totalPrestamos);




}

