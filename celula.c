#define ATTR_SET(flags, attr) (flags) |= (1 << (attr))
#define ATTR_IS_SET(flags, attr) (flags) & (1 << (attr))

#include "mundo.h"

//Estructura celula:
struct celula{
	//Coordenadas:
	int x;
	int y;
	//true->viva; false->muerta
	bool estado;
	//Para emplear el tipo list_head:
	struct list_head list;
	//Flags del objeto:
	uint32_t  flags;
};

//Estructura para la lista:
struct list_head{
	struct list_head *prev;
	struct list_head *next;
}

//Enumerado para atributos del objeto celula:
enum celula_attr{
	X,
	y,
	LIST,
	FLAGS,
}

//Constructor de celula:
struct celula *cell_alloc()
{
	struct celula *cell = (struct celula *) malloc(sizeof(struct celula));
	if(!cell){
		perror("Error al reservar memoria para celula");
		exit(EXIT_FAILURE);
	}
	cell->flags = 0;
	return cell;
}
//Destructor de celula:
void cell_free(struct celula *cell)
{
	free cell;
}
