#ifndef HDR_H
#define HDR_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/* Tamaño del array regular bidimensaional */
#define TAM_ARRAY 50
/* Número de iteraciones */
#define ITERACION 60
/* Lindantes se refiere a las 8 células lindantes que tiene cada una como máximo. */
#define LINDANTES 8


/* Definición de Estructuras y Enumerados 
enum estado_celula{
		VIVA, 
		MUERTA
	} EstadoCelula;

 Inicializamos célula con el estado MUERTA por defecto 
struct celula{
		enum estado_celula estado;
	} Celula;

struct coordenadas{
		Aunque sean de tipo int, lo declararemos como unsigned char
		de esta forma ocupa menos espacio en memoria
		
		unsigned char x; 
		unsigned char y;
	} Coordenadas;

struct tablero{
		int iteracion;
		struct coordenadas arrayCelulasVivas[TAM_ARRAY*TAM_ARRAY];
		int indexVivas;
		struct coordenadas arrayCelulasNacen[TAM_ARRAY*TAM_ARRAY];
		int indexNacidas;
		struct coordenadas arrayCelulasMueren[TAM_ARRAY*TAM_ARRAY];
		int indexMuertas;
	} Tablero;
*/
struct punteros {
	struct celula *next;
	struct celula *prev;
};
struct  celula{
	unsigned char x;
	unsigned char y;
	struct punteros p;
};



/* Definición de funciones */

int menuInicio();

/*void iterarTablero(struct tablero *t);
void imprimeTablero(struct tablero *t);
void inicializarTablero(struct tablero *t, int numCelulas);
//void analizarTablero(struct tablero *t);
//Comprueba si un array está vacío.
int estaVacioArray(struct coordenadas array[TAM_ARRAY*TAM_ARRAY]);
//Comprueba si un array está vacío, y si no lo está guarda su última posición llena.
bool estaVacio(struct tablero *t, enum estado_celula opcion);
void addCelulas(struct tablero *t);
//void removeCelulas(struct tablero *t);
*/


#endif