#include "hdr.h"

int main(int argc, char **argv)
{

	//Preguntamos al usuario para insertar el nº de células inicial

	int numeroCelulas = menuInicio();
	
	//Inicializamos el Tablero de Células:
	bool array[TAM_ARRAY][TAM_ARRAY];
	bool provisional[TAM_ARRAY][TAM_ARRAY];

	//Establecemos a 1 (Muertas) todas las células:
	declararTablero(array);

	inicializarTablero(array,numeroCelulas);
	printf("\tEstado Inicial: \n\n");
	imprimeTablero(array);

	//Iteramos:
	for(int iteracion = 0; iteracion < ITERACION; iteracion++){
		analizarTablero(array, provisional);
		copiaArray(array, provisional);
		declararTablero(provisional);
		printf("\tIteración %d: \n\n", iteracion+1);
		imprimeTablero(array);
		printf("\n");
	}
}
