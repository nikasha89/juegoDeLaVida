#include "hdr.h"

//Comienza el juego preguntando el número de células de las que partir:
int menuInicio()
{
	int num = 0;
	printf("Escoge un número entre 3 y 2400: \n");
	scanf("%d",num);
	return num;
}

//Inicializa el tablero con el número de células indicado por el usuario:
void inicializarTablero(struct tablero *t, int numCelulas)
{
	//Bucle con valor de iteración igual al número de células: 
	for(int i=0;i< numCelulas;i++)
	{ 
		/* Para obtener un número aleatorio:
		numero = rand () % (N-M+1) + M;   // Este está entre M y N 
		En nuestro caso: Entre 0 y 49 Para obtener dos coordenadas del tablero
		donde introducir las células vivas: */
		
		int x= rand() %  50;
		int y= rand() %  50;
		
		t->arrayCelulasVivas[i];
		t->tablero[x][y]-> estado = VIVA;
		t->tablero_inicial[x][y]-> estado = VIVA;
	}
}

/* Comprueba si el array está vacío, devuelve -1 si está vacío,
null si hubo algún problema y un index si está lleno */
int estaVacio(struct coordenadas *array)
{	
	/* Inicializamos vacio a true, y si encuentra un elemento
	dentro del array nos devolverá -1 */
	int vacio = null;
	for(int i=0;i<TAM_ARRAY*TAM_ARRAY && vacio;i++){
		if(array[i]){
			vacio = -1;
		}
		vacio=i;
	}
	return vacio;
}

/* Comprueba si el array está vacío, devolviendo bool  */
bool estaVacio(struct tablero *t, enum estado_celula opcion)
{	
	/* Inicializamos vacio a true, y si encuentra un elemento
	dentro del array nos devolverá false */
	bool vacio = true;
	switch(opcion){
		case VIVA:
		int res = estaVacio(t->arrayCelulasNacidas);
		if(res!=NULL && res!=-1){
			vacio = false;
			indexNacidas
		}
	}
	
	return vacio;
}

voi addCelula(struct tablero *t)
{
	/* Añadimos las células nacidas 
	a la última posición del array células vivas: */
	for(int j=0;j<TAM_ARRAY*TAM_ARRAY;j++){
		t->arrayCelulasVivas[j]
	}
}

/* Realiza la comprobación de las células vivas/muertas para la siguiente iteración
y elimina/añade las células nacidas de la anterior iteración */
void iterarTablero(struct tablero *t)
{	
	/* Comprobamos que no tenemos Células que 
	tengan que nacer o revivir de la anterior iteración: */
	if(!estaVacio(t->arrayCelulasNacen)){
		/* Añadimos al array de células vivas las correspondientes */
		addCelulas(t);
	}
	if(!estaVacio(t->arrayCelulasMueren){
		/* Eliminamos del array de células vivas las que mueren */	
		removeCelulas(t);
	}
	
	/* Analizamos el nº de Células que deben nacer, 
	permanecer igual o morir en la siguiente iteración: */
	analizarTablero(t);
	/* Tras analizarTablero, tendremos en *t 2 arrays
	con las coordenadas de las células que deben nacer
	y morir en la siguiente iteración:
	*/
	for(int i=0;i<TAM_ARRAY;i++){
		for(int j=0;j<TAM_ARRAY;j++){
			t[i][j];
		}
	}	
}
