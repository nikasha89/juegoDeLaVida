#ifndef HDR_H
#define HDR_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 

/* Tamaño del array regular bidimensaional */
#define TAM_ARRAY 50
/* Número de iteraciones */
#define ITERACION 10
/* Lindantes se refiere a las 8 células lindantes que tiene cada una como máximo. */
#define LINDANTES 8

//Definición Estructura:



/* Definición de funciones */

//Imprime menú inicio.
int menuInicio();

//Inicializa el tablero con el número de celulas dadas por user
void inicializarTablero(bool array[][TAM_ARRAY], int numCelulas);

//Inicializa el tablero a 1s (celulas muertas)
void declararTablero(bool array[][TAM_ARRAY]);

//Para imprimir el tablero;
void imprimeTablero(bool array[][TAM_ARRAY]);

//Para analizar el tablero en cada iteración:
void analizarTablero(bool array[][TAM_ARRAY],bool provisional[][TAM_ARRAY]);

//Realiza la comprobación de las vecionas de una célula:
bool tiene3VecinasVivas(int x, int y, bool array[][TAM_ARRAY]);

//Para copiar un array en otro:
void copiaArray(bool array[][TAM_ARRAY],bool arrayAcopiar[][TAM_ARRAY]);

//Comprobar si una célula está dentro de los límites:
bool estaDentroLimites(int x, int y);

/*void iterarTablero(struct tablero *t);
void imprimeTablero(struct tablero *t);
//void analizarTablero(struct tablero *t);
//Comprueba si un array está vacío.
int estaVacioArray(struct coordenadas array[TAM_ARRAY*TAM_ARRAY]);
//Comprueba si un array está vacío, y si no lo está guarda su última posición llena.
bool estaVacio(struct tablero *t, enum estado_celula opcion);
void addCelulas(struct tablero *t);
//void removeCelulas(struct tablero *t);
*/


#endif