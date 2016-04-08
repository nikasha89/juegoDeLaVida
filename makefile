all : juego_de_la_vida

juego_de_la_vida : principal.o funciones.o 
gcc principal.o funciones.o -o juego_de_la_vida

principal.o : principal.c
gcc -c principal.c -o principal.o

funciones.o : hdr.h funciones. c
gcc -c funciones.c -o funciones.o