#include "hdr.h"

int main(int argc, char **argv)
{

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

	struct celula{
		bool muerta;
	} Tablero;
		int numeroCelulas = menuInicio();
		printf("%d\n",numeroCelulas);	
}
