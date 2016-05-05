#include "mundo.h"

int main(int argc, char **argv)
{
	//Preguntamos al usuario para insertar el nº de células inicial
	int numeroCelulasVivas = menuInicio();
	
	//Declaramos el Tablero de Células:
	bool array[TAM_ARRAY][TAM_ARRAY];
	bool provisional[TAM_ARRAY][TAM_ARRAY];

	//Establecemos a 0 (Muertas) todas las células:
	establecerA0Tablero(array);

	//Inicializamos tablero a 0s:
	inicializarTablero(array,numeroCelulasVivas);
	printf("\tEstado Inicial: \n\n");
	int cont2 = contadorCelulasVivas(array);
	imprimeTablero(array, numeroCelulasVivas);

	//Iteramos:
	for(int iteracion = 0; iteracion < ITERACION; iteracion++){
		//Analizamos el tablero y en provisional guardamos los cambios.
		analizarTablero(array, provisional);
		//Imprimimos iteración con su leyenda:
		printf("\tIteración %d: \n\n", iteracion+1);
		numeroCelulasVivas = contadorCelulasVivas(array);
		imprimeTablero(array, numeroCelulasVivas);
		printf("\n");
	}
}
