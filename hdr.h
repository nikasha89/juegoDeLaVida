#ifndef HDR_H
#define HDR_H
#include <stdio.h>
#include <stdbool.h>

/* Tamaño del array regular bidimensaional */
#define TAM_ARRAY 50
/* Número de iteraciones */
#define ITERACION 60
/* Lindantes se refiere a las 8 células lindantes que tiene cada una como máximo. */
#define LINDANTES 8

int menuInicio();
void iterarTablero(struct tablero *t);
void imprimeTablero(struct tablero *t);
void inicializarTablero(struct tablero *t);
void analizarTablero(struct tablero *t);
//Comprueba si un array está vacío.
int estaVacioArray(struct coordenadas *array);
//Comprueba si un array está vacío, y si no lo está guarda su última posición llena.
bool estaVacio(struct tablero *t, enum estado_celula opcion);
void addCelulas(struct tablero *t);
void removeCelulas(struct tablero *t);
#endif