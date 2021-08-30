/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/

#ifndef Mina_h
#define Mina_h

#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>

using namespace std;

typedef enum tCasilla{LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA};
					   //  ,   .   ,  G  ,   @   ,   X ,   S   ,   M   ,     D
int const MAX = 50;

typedef tCasilla tPlano[MAX][MAX];

typedef char tPlanoCaracteres[3 * MAX][3 * MAX];
typedef int tPlanoColores[3 * MAX][3 * MAX];

typedef struct {
	tPlano plano;
	int nFilas;
	int nColumnas;
	int posFila;
	int posColumna;
}tMina;


void cargar_Mina(ifstream & fichero, tMina& mina);
void dibujar1_1(const tMina& mina);
void dibujar1_3(const tMina& mina);
void dibuja3x3(tCasilla casilla, tPlanoCaracteres &caracteres, tPlanoColores &colores, int i, int j);
void colorFondo(int color);
tCasilla char2casilla(char casilla);
int numColor(tCasilla figura);
string casilla2char(tCasilla casilla);

#endif