/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/

#include "Juego.h"
#include "Mina.h"
#include "Puntuaciones.h"

int main() {

	int nivel = 0;
	int pos;
	string nombre;
	tJuego juego;
	bool salir = false;
	ifstream leerMovimiento;
	tTecla tecla;
	tPuntuaciones puntuaciones;

	inicializar_Marcador(puntuaciones);

	cargar_Marcador(puntuaciones);

	nombre = nombreSinBlancos();

	if (buscar(nombre, puntuaciones, pos)) {
		cout << setw(30) << "Ya estas registrado/a.\n\n";
		cout << setw(60) << "Mira las minas que has recorrido ordenadas por nivel\n\n";
		mostrar_Minas_Usuario(puntuaciones, pos);
	}
	else {
		cout << "\n" << setw(20) << "Eres nuevo/a: " << nombre << "\n\n";
		insertar(puntuaciones, nombre, pos);
		mostrar_Alfabetico(puntuaciones);
				
	}
	
	if ((nivel = menu3(puntuaciones, pos)) == 0) salir = true;
	while (!salir) {
		
		
		if (cargar_Juego(juego, nivel)) {

			int eleccion0, eleccion1 = -1;
			bool finPartida = false;

			system("cls");
			if ((eleccion0 = menu0()) == 0) salir = true, finPartida = true;
			if (!salir) if ((eleccion1 = menu1()) == 0) salir = true, finPartida = true;
			if (eleccion1 == 2) leerMovimiento.open("movimientos.txt");

			while (!finPartida) { // salimos del bucle cuando el jugador esté en la ficha SALIDA, que nos lo indicara la funcion hacerMovimiento
				dibujar(juego, eleccion0);
				//PRIMERO. Obtenemos el movimiento segun la eleccion del jugador...
				if (eleccion1 == 1) { //... o pantalla ...
					tecla = leerTecla();
				}
				else {				  //... o por fichero.
					char movimiento;
					if (!leerMovimiento.eof()) {
						leerMovimiento >> movimiento;
						tecla = fichero2tecla(movimiento);
						Sleep(12); //dormimos el sistema para que se aprecie el movimiento por fichero
					}
					else {
						leerMovimiento.close();
						eleccion1 = 1; //Despues de que se ejecuten los movimientos del fichero y si no hemos llegado a Salida, pasamos a opcion manual.
					}

				}
				//SEGUNDO. Realizamos el movimiento correspondiente
				if (hacerMovimiento(juego, tecla, eleccion0)) { //hacerMovimiento nos devuelve TRUE cuando el jugador haya llegado a la posicion SALIDA
					system("cls");
					bool minaMejorada = volcarDatos(puntuaciones, juego, nivel, pos);
					mostrar_Datos_Usuario(puntuaciones);
					if (!minaMejorada) cout << "\nNo has mejorado la puntuacion de la mina " << nivel << ". SIGUE INTENTANDOLO.\n";
					system("pause");
					finPartida = true;
					if ((nivel = menu3(puntuaciones, pos)) == 0) salir = true;
					
				}
				system("cls");

			}
		}

		else {
			cout << "No se ha podido cargar el juego. Lo siento";
			salir = true;
		}
	}
	guardar_Marcador(puntuaciones);

}