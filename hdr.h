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
#define ITERACION 9

/* Definición de funciones */
//Imprime menú inicio.
int menuInicio();

//Inicializa el tablero con el número de celulas dadas por user
void inicializarTablero(bool array[][TAM_ARRAY], int numCelulas);

//Inicializa el tablero a 0s (celulas muertas)
void establecerA0Tablero(bool array[][TAM_ARRAY]);

//Para imprimir el tablero;
void imprimeTablero(bool array[][TAM_ARRAY]);

//Para analizar el tablero en cada iteración:
void analizarTablero(bool array[][TAM_ARRAY],bool provisional[][TAM_ARRAY]);

//Realiza la comprobación de las condiciones para vivir o morir de una célula:
bool comprobarCondiciones(int x, int j, bool array[][TAM_ARRAY], bool caso);

//Cuenta las células vecinas vivas de otra dada:
int cuentaVecinasVivas(int x, int j, bool array[][TAM_ARRAY]);

//Para copiar un array en otro:
void copiaArray(bool array[][TAM_ARRAY],bool arrayAcopiar[][TAM_ARRAY]);

//Comprobar si una célula está dentro de los límites:
bool estaDentroLimites(int x, int y);
#endif