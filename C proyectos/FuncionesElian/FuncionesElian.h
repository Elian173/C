
#define TRUE 1
#define FALSE 0

struct EMP
{
int legajo;
char nombre[20];
char apellido[20];
int edad;
int estado;
};


/**Funciones de input **/  //__________________________________________________________________________________________

int continuar(void);
/** \brief Pregunta al usuario si quiere continuar (S o N) ; no permite otros caracteres
 * \param ()
 * \return Si se ingresa S devuelve int 1 , si se ingresa N devuelve int */

float pedirFloat(char mensaje[]);
/*** \brief Pide un float
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El float ingresado */

int pedirInt(char mensaje[]);
/*** \brief Pide un Int
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El Int ingresado */

char pedirChar(char mensaje[]);
/*** \brief Pide un char
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El char ingresado */

void pedirString(char mensaje[],char x[]);
/*** \brief Pide un string
 * \param "mensaje" es la pregunta que ve el usuario
 * \return El string ingresado */

int pedirNombre(char mensaje[],char*texto);
/** \brief Pide un texto solo de letras y lo devuelve
 * \param mensaje Es la pregunta que ve el usuario
 * \param x Array donde se carga el string ingresado
 * \return 1 si el texto contiene solo letras*/

int perdirStringNumeros(char mensaje[],char*numero[]);
/** \brief Pide un texto solo de numeros y lo devuelve
 * \param mensaje Es la pregunta que ve el usuario
 * \param x Array donde se carga el string ingresado
 * \return 1 si el texto contiene solo numeros*/



/**Funciones de validacion**///  ____________________________________________________________________________________________

int stringEsNumerico(char x[]);
/** \brief Verifica si el string es numérico
 * \param x Array con el string a validar
 * \return 1 si es númerico y 0 si no lo es*/

int stringEsLetras(char x[]);
/** \brief Verifica si el string contiene solo letras
 * \param x Array el string a analizar
 * \return 1 es solo letras y ' ' , 0 otros caracteres*/

int stringEsNumYLetras(char x[]);
/** \brief Verifica si el string contiene solo numeros y letras
 * \param x Array el string a analizar
 * \return 1 es solo letras numeros y ' ' , 0 otros caracteres*/

 /**Funciones de Ordenamiento de strings*///__________________________________________________________________________________

void iniciarEnMenosUno(int*x[],int cuantosElementos);

int buscarLugar(int elArray[], int cuantosElementos , int reemplazarPor);
