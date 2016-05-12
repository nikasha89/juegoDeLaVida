#include "mundo.h"
//Constructor Mundo:
struct Mundo * mundo_constructor(int width, int high)
{
	struct Mundo *tablero = (struct Mundo *) malloc( sizeof(struct Mundo) );
	if(compruebaError(tablero))
		exit(EXIT_FAILURE);
	//Añadimos las dimensiones del tablero:
	tablero->width = width;
	tablero->high = high;
	/* Si array_objetivo=true, cogemos array,
	si array_objetivo=false cogemos provisional */
	tablero->array_objetivo = true;
	//Declaramos el array de tablero:
	tablero->array = array_contructor(width, high);
	if(compruebaError(tablero->array)){
		free(tablero);
		exit(EXIT_FAILURE);
	}
	//Declaramos el array provisional:
	tablero->provisional = array_contructor(width, high);
	if(compruebaError(tablero->provisional)){
		free(tablero->array);
		free(tablero);
		exit(EXIT_FAILURE);
	}
	return tablero;
}
//Constructor de Array de Células:
bool * array_contructor(int width, int high)
{
	bool *mundo = (bool *) malloc(width * high * sizeof(bool));
}

//Destruye Mundo:
void mundo_free(struct Mundo * mundo)
{
	free(mundo->array);
	free(mundo->provisional);
	free(mundo);
}

//Comienza el juego preguntando el número de células de las que partir:
int menuInicio(int width, int high)
{
	int num = 0;
	printf("Escoge un número entre 3 y %d: \n", width*high);
	scanf("%4d",&num);
	return num;
}

//Inicializa el Tablero con todas las células muertas:
void establecerA0Tablero(struct Mundo *mundo)
{
	//Establecemos a falso (como muertas) todas las células:
	for(int i=0;i<mundo->high;i++)
		for(int j=0;j<mundo->width;j++)
			*(transformaApuntero(mundo->array,i,j,mundo->width)) = false;
}

//Inicializa el tablero con el número de células indicado por el usuario:
void inicializarTablero(struct Mundo *mundo, int numCelulas)
{	
	//Añadimos la semilla:
	srand (time(NULL));
	//Bucle con valor de iteración igual al número de células: 
	for(int n=0;n< numCelulas;n++){ 
		/* Para obtener un número aleatorio:
		numero = rand () % (N-M+1) + M;   // Este está entre M y N 
		En nuestro caso: Entre 0 y width/high Para obtener dos coordenadas del tablero
		donde introducir las células vivas: 
		*/
		int i= rand() %  mundo->high;
		int j= rand() %  mundo->width;
		//Establecemos celula como viva (true)
		*(transformaApuntero(mundo->array,i,j,mundo->width)) = true;
	}
}

//Imprime tablero por consola:
void imprimeTablero(struct Mundo *mundo)
{
	bool *array_objetivo = mundo->array;
	if(!mundo->array_objetivo){
		array_objetivo = mundo->provisional;		
	}
	int numCelulas = contadorCelulasVivas(mundo);
	for(int i=0; i<mundo->high; i++){
		for(int j=0; j<mundo->width; j++){
			//Si célula está viva escribimos V:
			if(*(transformaApuntero(array_objetivo,i,j,mundo->width)) == true)
				printf(ANSI_COLOR_YELLOW " V " ANSI_COLOR_RESET);
			//Si está muerta escribimos - :
			else
				printf(ANSI_COLOR_CYAN " - " ANSI_COLOR_RESET);
		}
		//Si llegamos a la última columna nos vamos a la siguiente línea:
		printf(" \n");
	}
	printf("\tLeyenda:\n\t");
	printf(ANSI_COLOR_YELLOW "V: Célula Viva -> Vivas: %d\n" ANSI_COLOR_RESET, numCelulas);
	printf(ANSI_COLOR_CYAN "\t- : Célula Muerta -> Muertas %d\n" ANSI_COLOR_RESET,mundo->width*mundo->high - numCelulas);
}

//Realiza la iteración:
void analizarTablero(struct Mundo *mundo)
{
	//Recorremos el array analizando cada célula y sus vecinas:
	for (int i = 0; i < mundo->high; i++)
		for(int j = 0; j < mundo->width ; j++)
			//Comprobamos las condiciones en cada caso:
			comprobarCondiciones(i,j,mundo);
	//Ahora array_objetivo será el que anteriormente era provisional:
	mundo->array_objetivo = !mundo->array_objetivo;
	bool *array_objetivo = mundo->array;
	if(!mundo->array_objetivo)
		array_objetivo = mundo->provisional;
}

//Realiza la comprobación de las vecionas de una célula:
void comprobarCondiciones(int i, int j, struct Mundo *mundo)
{
	int vecinas = 0;
	/* Sabiendo que cada célula (i,j) tiene máximo 8 lindantes,
	comprobando (i-1,j-1);(i-1,j);(i-1,j+1);(i,j-1); y
	(i,j+1);(i+1,j-1);(i+1,j);(i+1,j+1); */
	bool *array_objetivo = mundo->array;
	bool *array_provisional = mundo->provisional;
	if(!mundo->array_objetivo){
		array_provisional = mundo->array;
		array_objetivo = mundo->provisional;		
	}
	bool caso =*(transformaApuntero(array_objetivo,i,j,mundo->width));
	vecinas = cuentaVecinasVivas(i,j,mundo);
	switch(caso){
		//Si está muerta:
		case false:
			//Si tiene 3 vecinas vivas nace:
			if(vecinas == 3)
				*(transformaApuntero(array_provisional,i,j,mundo->width)) = true;
			else
				//Si no tiene 3 vecinas vivas sigue muerta:
				*(transformaApuntero(array_provisional,i,j,mundo->width)) = *(transformaApuntero(array_objetivo,i,j,mundo->width));
			break;
		//Si está viva:
		case true:
			//Si no tiene 2 o 3 vecinas vivas muere:
			if(!(vecinas >=2 && vecinas <= 3))
				*(transformaApuntero(array_provisional,i,j,mundo->width)) = false;
			else
				//Si tiene 2 o 3 vecinas vivas sigue viva:
				*(transformaApuntero(array_provisional,i,j,mundo->width)) = *(transformaApuntero(array_objetivo,i,j,mundo->width));
			break;
	}
}

//Contador de células Vecinas Vivas de Array:
int cuentaVecinasVivas(int i, int j,  struct Mundo *mundo)
{
	bool *array_objetivo = mundo->array;
	if(!mundo->array_objetivo)
		array_objetivo = mundo->provisional;		
	int contador = 0;
	if(estaDentroLimites(i-1, j-1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i-1,j-1,mundo->width)))
		contador++;
	if(estaDentroLimites(i-1,j, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i-1,j,mundo->width)))
		contador++;
	if(estaDentroLimites(i-1,j+1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i-1,j+1,mundo->width)))
		contador++;
	if(estaDentroLimites(i,j-1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i,j-1,mundo->width)))
		contador++;
	if(estaDentroLimites(i,j+1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i,j+1,mundo->width)))
		contador++;
	if(estaDentroLimites(i+1,j-1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i+1,j-1,mundo->width)))
		contador++;
	if(estaDentroLimites(i+1,j, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i+1,j,mundo->width)))
		contador++;
	if(estaDentroLimites(i+1,j+1, mundo->width, mundo->high) && *(transformaApuntero(array_objetivo,i+1,j+1,mundo->width)))
		contador++;
	return contador;
}

//Comprueba que los índices pertenecen al tablero:
bool estaDentroLimites(int i, int j, int width, int high)
{
	return  !(i>=high || i<0 || j>width || j<0);
}

//Contador de celulas vivas:
int contadorCelulasVivas(struct Mundo *mundo)
{
	int contador = 0;
	bool *array_objetivo = mundo->array;
	if(!mundo->array_objetivo)
		array_objetivo = mundo->provisional;		
	for(int i = 0; i < mundo->high; i++)
		for(int j = 0; j < mundo->width; j++)
			if(*(transformaApuntero(array_objetivo,i,j,mundo->width))) 
				contador++;	
	return contador;
}

/* Le pasamos el puntero al 1er elemento y el resto de parámetros
y le devolvemos un puntero a bool*/
bool * transformaApuntero(bool *array,int i,int j, int width)
{	
	bool *p = array+i*width+j;
	return p;
}

//Para comprobar errores de reserva de memoria (1 si da error y 0 e.o.c):
int compruebaError(void *p)
{
	if(!p)
		perror("Error al reservar memoria!");
	return !p;

}