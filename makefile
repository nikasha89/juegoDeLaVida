all : juego_de_la_vida

juego_de_la_vida : mundo.o funciones.o 
	gcc mundo.o funciones.o -o juego_de_la_vida

mundo.o : mundo.c mundo.h
	gcc -c mundo.c -o mundo.o -std=c99

funciones.o : mundo.h funciones.c
	gcc -c funciones.c -o funciones.o -std=c99