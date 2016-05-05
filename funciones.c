#include "mundo.h"

//Comienza el juego preguntando el número de células de las que partir:
int menuInicio()
{
	int num = 0;
	printf("Escoge un número entre 3 y 2400: \n");
	scanf("%4d",&num);
	return num;
}

//Inicializa el Tablero con todas las células muertas:
void establecerA0Tablero(bool array[][TAM_ARRAY])
{
	//Establecemos a falso (como muertas) todas las células:
	for(int i=0;i<TAM_ARRAY;i++)
		for(int j=0;j<TAM_ARRAY;j++)
			array[i][j] = false;
}

//Inicializa el tablero con el número de células indicado por el usuario:
void inicializarTablero(bool array[][TAM_ARRAY], int numCelulas)
{	
	//Añadimos la semilla:
	srand (time(NULL));
	//Bucle con valor de iteración igual al número de células: 
	for(int i=0;i< numCelulas;i++){ 
		/* Para obtener un número aleatorio:
		numero = rand () % (N-M+1) + M;   // Este está entre M y N 
		En nuestro caso: Entre 0 y 49 Para obtener dos coordenadas del tablero
		donde introducir las células vivas: 
		*/
		int x= rand() %  50;
		int y= rand() %  50;
		//Establecemos celula como viva (true)
		array[x][y] = true;
	}
}

//Imprime tablero por consola:
void imprimeTablero(bool array[][TAM_ARRAY])
{
	for(int i=0; i<TAM_ARRAY; i++){
		for(int j=0; j<TAM_ARRAY; j++){
			//Si célula está viva escribimos V:
			if(array[i][j] == true)
				printf(" V ");
			//Si está muerta escribimos - :
			else
				printf(" - ");
		}
		//Si llegamos a la última columna nos vamos a la siguiente línea:
		printf(" \n");
	}
	printf("\tLeyenda:\n\t V: Célula Viva \n\t - : Célula Muerta \n");
}

//Para copiar un array en otro:
void copiaArray(bool array[][TAM_ARRAY],bool arrayAcopiar[][TAM_ARRAY])
{
	//Copiamos el tablero en provisional:
	for (int i = 0; i < TAM_ARRAY; ++i)
		for(int j=0;j<TAM_ARRAY; j++)
			array[i][j] =  arrayAcopiar[i][j];
}

//Realiza la iteración:
void analizarTablero(bool array[][TAM_ARRAY],bool provisional[][TAM_ARRAY])
{
	//Recorremos el array analizando cada célula y sus vecinas:
	for (int i = 0; i < TAM_ARRAY; ++i)
		for(int j=0;j<TAM_ARRAY; j++)
			//Comprobamos las condiciones en cada caso:
			comprobarCondiciones(i,j,array, provisional);
		
	
	//Copiamos provisional en array:
	copiaArray(array, provisional);
}

//Realiza la comprobación de las vecionas de una célula:
bool comprobarCondiciones(int x, int j, bool array[][TAM_ARRAY], bool provisional[][TAM_ARRAY])
{
	int vecinas = 0;
	bool res = false;
	/* Sabiendo que cada célula (i,j) tiene máximo 8 lindantes,
	comprobando (i-1,j-1);(i-1,j);(i-1,j+1);(i,j-1); y
	(i,j+1);(i+1,j-1);(i+1,j);(i+1,j+1); */
	bool caso = array[x][j];
	vecinas = cuentaVecinasVivas(x,j,array);
	switch(caso){
		//Si está muerta:
		case false:
			//Si tiene 3 vecinas vivas nace:
			if(vecinas == 3)
				provisional[x][j] = true;
			else
				//Si no tiene 3 vecinas vivas sigue muerta:
				provisional[x][j] = array[x][j];
			break;
		//Si está viva:
		case true:
			//Si no tiene 2 o 3 vecinas vivas muere:
			if(!(vecinas >=2 && vecinas <= 3))
				provisional[x][j] = false;
			else
				//Si tiene 2 o 3 vecinas vivas sigue viva:
				provisional[x][j] = array[x][j];
			break;
	}
	return res;
}

//Contador de células Vecinas Vivas:
int cuentaVecinasVivas(int x, int j, bool array[][TAM_ARRAY])
{
	int contador = 0;
	if(estaDentroLimites(x-1,j-1) && array[x-1][j-1])
		contador++;
	if(estaDentroLimites(x-1,j) && array[x-1][j])
		contador++;
	if(estaDentroLimites(x-1,j+1) && array[x-1][j+1])
		contador++;
	if(estaDentroLimites(x,j-1) && array[x][j-1])
		contador++;
	if(estaDentroLimites(x,j+1) && array[x][j+1])
		contador++;
	if(estaDentroLimites(x+1,j-1) && array[x+1][j-1])
		contador++;
	if(estaDentroLimites(x+1,j) && array[x+1][j])
		contador++;
	if(estaDentroLimites(x+1,j+1) && array[x+1][j+1])
		contador++;
	return contador;
}

//Comprueba que los índices pertenecen al tablero:
bool estaDentroLimites(int x, int y)
{
	return  !(x>=TAM_ARRAY || x<0 || y>TAM_ARRAY || y<0);
}

