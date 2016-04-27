#include "hdr.h"

//Comienza el juego preguntando el número de células de las que partir:
int menuInicio()
{
	int num = 0;
	printf("Escoge un número entre 3 y 2400: \n");
	scanf("%4d",&num);
	return num;
}


void declararTablero(bool array[][TAM_ARRAY])
{

	//Establecemos a 1 (como muertas) todas las células:
	for(int i=0;i<TAM_ARRAY;i++){
		for(int j=0;j<TAM_ARRAY;j++){

			array[i][j] = true;

		}
	}

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
		
		//Establecemos muerta como falso
		array[x][y] = false;
	}
}

void imprimeTablero(bool array[][TAM_ARRAY])
{
	for(int i=0; i<TAM_ARRAY; i++){
		for(int j=0; j<TAM_ARRAY; j++){

			if(array[i][j] == 0){
				printf(" V ");
			}else{
				printf(" - ");

			}

			//Si llegamos a la última columna nos vamos a la siguiente línea:
			if(j == TAM_ARRAY-1){

				printf(" \n");
			}
		}
	}
	printf("\tLeyenda:\n\t V: Célula Viva \n\t - : Célula Muerta \n");
}

//Para copiar un array en otro:
void copiaArray(bool array[][TAM_ARRAY],bool arrayAcopiar[][TAM_ARRAY])
{

	//Copiamos el tablero en provisional:
	for (int i = 0; i < TAM_ARRAY; ++i){
		for(int j=0;j<TAM_ARRAY; j++){

			array[i][j] =  arrayAcopiar[i][j];

		}
	}

}

//Realiza la iteración:
void analizarTablero(bool array[][TAM_ARRAY],bool provisional[][TAM_ARRAY])
{
	//Copiamos el tablero en provisional:
	copiaArray(provisional, array);
	//Recorremos el array analizando cada célula y sus vecinas:
	for (int i = 0; i < TAM_ARRAY; ++i){
		for(int j=0;j<TAM_ARRAY; j++){
			bool celula = array[i][j];
			//Si está muerta y tiene 3 vecinas:
			switch(celula){
				case true:
					if(tiene3VecinasVivas(i,j,array) == true){
						//Nace:
						provisional[i][j] = false;
					}
					break;
				case false:
					//Si está viva y no tiene 3 vecinas::
					if(tiene3VecinasVivas(i,j,array) == false){
						//Muere:
						provisional[i][j] = true;
					}
					break;
			}
		}
	}
}

//Realiza la comprobación de las vecionas de una célula:
bool tiene3VecinasVivas(int x, int j, bool array[][TAM_ARRAY])
{
	int contador = 0;

	/* Sabiendo que cada célula (i,j) tiene máximo 8 lindantes,
	comprobando (i-1,j-1);(i-1,j);(i-1,j+1);(i,j-1); y
	(i,j+1);(i+1,j-1);(i+1,j);(i+1,j+1); */

	if(estaDentroLimites(x-1,j-1) && array[x-1][j-1] == false){
		contador++;
	}
	if(estaDentroLimites(x-1,j) && array[x-1][j] == false){
		contador++;
	}
	if(estaDentroLimites(x-1,j+1) && array[x-1][j+1] == false){
		contador++;
	}
	if(estaDentroLimites(x,j-1) && contador<3 && array[x][j-1] == false){
		contador++;
	}
	if(estaDentroLimites(x,j+1) && contador<3 && array[x][j+1] == false){
		contador++;
	}
	if(estaDentroLimites(x+1,j-1) && contador<3 && array[x+1][j-1] == false){
		contador++;
	}
	if(estaDentroLimites(x+1,j) && contador<3 && array[x+1][j] == false){
		contador++;
	}
	if(estaDentroLimites(x+1,j+1) && contador<3 && array[x+1][j+1] == false){
		contador++;
	}

	return (contador>=3);
}

bool estaDentroLimites(int x, int y)
{
	bool res = true;
	
	if( x>=TAM_ARRAY || x<0 || y>TAM_ARRAY || y<0){
		res = false;
	}
	return res;
}

