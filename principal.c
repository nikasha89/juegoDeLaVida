#include "hdr.h"

int main(){
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
		int iteracion;
		struct coordenadas arrayCelulasVivas[TAM_ARRAY*TAM_ARRAY];
		int indexVivas;
		struct coordenadas arrayCelulasNacen[TAM_ARRAY*TAM_ARRAY];
		int indexNacidas;
		struct coordenadas arrayCelulasMueren[TAM_ARRAY*TAM_ARRAY];
		int indexMuertas;
	} Tablero;
		int numeroCelulas = menuInicio();
		printf("%d\n",numeroCelulas);	
}
#endif