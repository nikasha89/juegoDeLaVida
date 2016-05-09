all : juego_de_la_vida

juego_de_la_vida : principal.o mundo.o 
	gcc principal.o mundo.o -o juego_de_la_vida

principal.o : principal.c mundo.h
	gcc -c principal.c -o principal.o -std=c99

mundo.o : mundo.h mundo.c
	gcc -c mundo.c -o mundo.o -std=c99