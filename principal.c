#include "mundo.h"

int main(int argc, char **argv)
{
	/* Recogemos los parametros de ancho, alto y lugar opcion */
	int width, high, c; //Ancho y Alto del mundo.
	/* Cadena de caracter que guarda el path del archivo que contiene
	la sesion anteriormente jugada y guardada del mundo */
	char *directorio = "";//la cadena debe ir pegada a d(por consola)
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
	//Construimos tablero:
	struct Mundo *tablero = mundo_constructor(width,high);
	//Preguntamos al usuario para insertar el nº de células inicial
	int numeroCelulasVivas = menuInicio(width, high);
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
	mundo_free(tablero);
	return 0;
}
