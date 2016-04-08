#include <stdio.h>

/* Tamaño del array regular bidimensaional */
#define TAM_ARRAY 50
/* Número de iteraciones */
#define ITERACION 60
/* Lindantes se refiere a las 8 células lindantes que tiene cada una como máximo. */
#define LINDANTES 8

enum estado_celula{
	VIVA, 
	MUERTA
} EstadoCelula;

/* Inicializamos célula con el estado MUERTA por defecto */
struct celula{
	enum estado_celula estado = MUERTA;
} Celula;

struct coordenadas{
	/* Aunque sean de tipo int, lo declararemos como unsigned char
	de esta forma ocupa menos espacio en memoria
	*/
	unsigned char x; 
	unsigned char y;
} Coordenadas;

struct tablero{
	int iteracion=0;
	struct celula tablero_inicial[TAM_ARRAY][TAM_ARRAY];
	struct coordenadas arrayCelulasVivas[TAM_ARRAY*TAM_ARRAY];
	int indexVivas;
	struct coordenadas arrayCelulasNacen[TAM_ARRAY*TAM_ARRAY];
	int indexNacidas;
	struct coordenadas arrayCelulasMueren[TAM_ARRAY*TAM_ARRAY];
	int indexMuertas;
} Tablero;

int menuInicio();
void iterarTablero(struct tablero *t);
void imprimeTablero(struct tablero *t);
void inicializarTablero(struct tablero *t);
void analizarTablero(struct tablero *t);
//Comprueba si un array está vacío.
int estaVacio(struct coordenadas *array);
//Comprueba si un array está vacío, y si no lo está guarda su última posición llena.
bool estaVacio(struct tablero *t, enum estado_celula opcion);
void addCelulas(struct tablero *t);
void removeCelulas(struct tablero *t);
