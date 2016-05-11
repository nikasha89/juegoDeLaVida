#include "mundo.h"

int main(int argc, char **argv)
{
	/* Recogemos los parametros de ancho, alto y lugar opcion */
	int width, high, c; //Ancho y Alto del mundo.
	/* Cadena de caracter que guarda el path del archivo que contiene
	la sesion anteriormente jugada y guardada del mundo */
	char *directorio = "";//la cadena debe ir pegada a d(por consola)
	//Estructura mundo:

	struct Mundo *tablero = (struct Mundo *) malloc( sizeof(struct Mundo) );
	compruebaError(tablero);
	//Inicializamos width y high con valor por defecto:
	width = TAM_ARRAY;
	high = TAM_ARRAY;
	while((c = getopt( argc, argv, "w:h:d::"))!=-1){
		switch(c){
			case 'w':
				width = strtol(optarg, NULL, 0);
				break;
			case 'h':
				high = strtol(optarg, NULL, 0);
				break;
			case 'd':
				directorio = optarg;
				break;
			default:
				return EXIT_FAILURE;
		}
	}
	//Validamos dimensiones del mundo:
	if(width <= 0 || width > 100)
		width = TAM_ARRAY;
	if(high <= 0 || high > 100)
		high = TAM_ARRAY;
	//Añadimos esas dimensiones al tablero:
	tablero->width = width;
	tablero->high = high;
	//Preguntamos al usuario para insertar el nº de células inicial
	int numeroCelulasVivas = menuInicio(width, high);
	//Declaramos el Tablero de Células:
	bool *mundo;
	bool *provisional;
	//Declaramos el mundo:
	mundo = (bool *) malloc(width * high * sizeof(bool));
	if(compruebaError(mundo))
		exit(EXIT_FAILURE);
	compruebaError(mundo);
	//Declaramos el mundo provisional:
	provisional = (bool *) malloc(width * high * sizeof(bool));
	if(compruebaError(provisional)){
		free(mundo);
		exit(EXIT_FAILURE);
	}
	//Añadimos los punteros al tablero:
	tablero->array = mundo;
	tablero->provisional = provisional;
	//Establecemos a 0 (Muertas) todas las células:
	establecerA0Tablero(tablero);
	//Inicializamos tablero a 0s:
	inicializarTablero(tablero,numeroCelulasVivas);
	imprimeTablero(tablero);
	//Iteramos:
	for(int iteracion = 0; iteracion < ITERACION; iteracion++){
		//Analizamos el tablero y en provisional guardamos los cambios.
		analizarTablero(tablero);
		//Imprimimos iteración con su leyenda:
		printf("\tIteración %d: \n\n", iteracion+1);
		imprimeTablero(tablero);
		printf("\n");
	}
	free(mundo);
	free(provisional);
	free(tablero);
	return 0;
}
