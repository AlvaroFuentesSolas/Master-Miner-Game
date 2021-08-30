/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/

#ifndef Puntuaciones_h
#define Puntuaciones_h

#include "Mina.h"
#include "Juego.h"
#include <fstream>
#include <iostream>
#include <iomanip>

const int NUM_TOTAL_MINAS = 5;
const int A = 10;
const int B = 2;


typedef struct {
	int IdMina;
	int numMovimientos;
	int numGemas;
	int numDinamitas;
	int puntosMina;
} tDatosMina;

typedef struct {
	string nombre;
	int punt_total;
	int minasRecorridas;
	tDatosMina vMinasRecorridas[NUM_TOTAL_MINAS];
} tPuntuacionJugador;

typedef struct {
	int capacidad;
	int num_jugadores;
	tPuntuacionJugador *array_clasificacion;
} tPuntuaciones;

string nombreSinBlancos();
bool cargar_Marcador(tPuntuaciones& marcador);
bool guardar_Marcador(tPuntuaciones& marcador);
void mostrar_Minas_Usuario(const tPuntuaciones & marcador, int cont);
void mostrar_Alfabetico(const tPuntuaciones & marcador);
void mostrar_Datos_Usuario(const tPuntuaciones& marcador);
void ordenarPorNivel(tPuntuacionJugador & jugador);
bool volcarDatos(tPuntuaciones &marcador, tJuego juego, int nivel, int pos);
int menu3(tPuntuaciones puntuaciones, int pos);
int calcularPuntuacion(tJuego juego);



// ------- FUNCIONES DEL ARRAY DINAMICO -------------
void inicializar_Marcador(tPuntuaciones& marcador);
void aumentar_Capacidad(tPuntuaciones& marcador);
void destruir(tPuntuaciones& marcador);
bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos);
void insertar(tPuntuaciones& marcador, string const& nombre, int pos);


#endif
