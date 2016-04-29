#include "hdr.h"

int main(int argc, char **argv)
{
	//Preguntamos al usuario para insertar el nº de células inicial
	int numeroCelulas = menuInicio();

	/* Definimos la estructura de nuestra lista: */
	struct list_head lh;
	struct list_head *it;
	struct celula *pcell;

	//Para realizar el recorrido de la lista haremos lo siguiente:
	list_for_each_entry(it,&lh,pcell->list){

	}

	//Inicializamos tablero a 0s:
	inicializarTablero(array,numeroCelulas);
	printf("\tEstado Inicial: \n\n");
	imprimeTablero(array);

	//Iteramos:
	for(int iteracion = 0; iteracion < ITERACION; iteracion++){
		//Analizamos el tablero y en provisional guardamos los cambios.
		analizarTablero(array, provisional);
		//Imprimimos iteración con su leyenda:
		printf("\tIteración %d: \n\n", iteracion+1);
		imprimeTablero(array);
		printf("\n");
	}
}
