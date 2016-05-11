#ifndef HDR_H
#define HDR_H
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 

/* Tamaño del array regular bidimensaional */
#define TAM_ARRAY 50
/* Número de iteraciones */
#define ITERACION 9
//Definición de colores:
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//Definición Estructuras:
struct Mundo {
		int width;
		int high;
		bool *array;
		bool *provisional;
	};

/* Definición de funciones */
//Imprime menú inicio.
int menuInicio(int width, int high);

//Inicializa el tablero con el número de celulas dadas por user
void inicializarTablero(struct Mundo *mundo, int numCelulas);

//Inicializa el tablero a 0s (celulas muertas)
void establecerA0Tablero(struct Mundo *mundo);

//Para imprimir el tablero;
void imprimeTablero(struct Mundo *mundo);

//Para analizar el tablero en cada iteración:
void analizarTablero(struct Mundo *mundo);

//Realiza la comprobación de las condiciones para vivir o morir de una célula:
void comprobarCondiciones(int i, int j, struct Mundo *mundo);

//Cuenta las células vecinas vivas de otra dada:
int cuentaVecinasVivas(int i, int j, struct Mundo *mundo);

//Para copiar un array en otro:
void copiaArray(struct Mundo *mundo);

//Comprobar si una célula está dentro de los límites:
bool estaDentroLimites(int i, int j, int width, int high);

//Para contar las celulas vivas del mundo(array):
int contadorCelulasVivas(struct Mundo *mundo);

/* Le pasamos el puntero al 1er elemento y el resto de parámetros
y le devolvemos un puntero a bool*/
bool * transformaApuntero(bool *array,int i,int j, int width);

//Para comprobar errores de reserva de memoria:
int compruebaError(void *p);
#endif