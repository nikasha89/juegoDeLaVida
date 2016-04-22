#include "hdr.h"

int main(int argc, char **argv){

/* Recogemos los parametros de ancho, alto y lugar opcion */

//Ancho y Alto del mundo:
int width, high, c;
/* Cadena de caracter que guarda el path del archivo que contiene
la sesion anteriormente jugada y guardada del mundo */
char *directorio;

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

printf("width = %d; high= %d; directorio:%s \n", width, high, directorio);
/*
	for(int i=stdin; i < argc;i++){
		printf( "Esto sobra(argumento desconocido): %s", argv[i] );
	}

	enum estado_celula{
		VIVA, 
		MUERTA
	} EstadoCelula;

	Inicializamos célula con el estado MUERTA por defecto 
	struct celula{
		enum estado_celula estado;
	} Celula;
*/
	struct lista{
		/* Aunque sean de tipo int, lo declararemos como unsigned char
		de esta forma ocupa menos espacio en memoria
		*/
		unsigned char x; 
		unsigned char y;
		int *next;
		int *prev;
	};

	struct tablero{
		int iteracion;
		struct coordenadas arrayCelulasVivas[TAM_ARRAY*TAM_ARRAY];
		int indexVivas;
		struct coordenadas arrayCelulasNacen[TAM_ARRAY*TAM_ARRAY];
		int indexNacidas;
		struct coordenadas arrayCelulasMueren[TAM_ARRAY*TAM_ARRAY];
		int indexMuertas;
	} Tablero;
		int numeroCelulas = menuInicio();
		printf("%d\n",numeroCelulas);	
}
