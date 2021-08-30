/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/
#ifndef Juego_h
#define Juego_h

#include "Mina.h"
#include <fstream>
#include <iostream>
#include <conio.h>

typedef enum tTecla { ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT };


typedef struct {
	tMina mina;
	int contGemas;
	int numMovimientos;
	int numDinamitas;
}tJuego;


bool cargar_Juego(tJuego& juego, int nivel);
bool hacerMovimiento(tJuego& juego, tTecla tecla, int eleccionDibujar);
void dibujar(const tJuego& juego, int eleccionEscala);
void mostrarDatos(tJuego juego);
tTecla leerTecla();
tTecla fichero2tecla(char casilla);
int menu0();
int menu1();
int menu2();

#endif