/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/

#include "Juego.h"


bool cargar_Juego(tJuego& juego, int nivel) {

	bool cargarCorrecta = false;
	ifstream fileIn;
	string fichero = to_string(nivel) + ".txt";
	fileIn.open(fichero);
	if (fileIn.is_open()) {
		juego.contGemas = 0;
		juego.numDinamitas = 0;
		juego.numMovimientos = 0;
		cargar_Mina(fileIn, juego.mina);
		cargarCorrecta = true;
	}
	fileIn.close();
	return cargarCorrecta;
}

//Devuelve FALSE o TRUE dependiendo si el usuario ha llegado a la casilla salida
//El parametro INT ELECCIONDIBUJAR lo utilizamos para ver casilla a casilla como caen tanto el TNT como las piedras.
bool hacerMovimiento(tJuego& juego, tTecla tecla, int eleccionDibujar) {

	bool salida = false;
	tCasilla aux;
	
	if (tecla == ARRIBA) {
		if ((juego.mina.posFila - 1 >= 0) &&
			(juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] != MURO)) {

			if (juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] == GEMA){

				juego.contGemas++;
				juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posFila--;
			}
			
			else if ((juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] == PIEDRA) && 
				(juego.mina.plano[juego.mina.posFila - 2][juego.mina.posColumna] == LIBRE)){				
	
					
					juego.mina.plano[juego.mina.posFila - 2][juego.mina.posColumna] = PIEDRA;
					juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] = MINERO;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
					juego.mina.posFila--;
				

			}
			
			else if ((juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] == TIERRA) ||
				 (juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] == LIBRE)) {
				
				juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posFila--;
			}
		
			else if (juego.mina.plano[juego.mina.posFila - 1][juego.mina.posColumna] == SALIDA) {

				salida = true;
			}
			else {
				//NO HACER NADA, NO SE PUEDE REALIZAR NINGUN MOVIMIENTO HACIA ESA POSICION
			}

		}

	}
	
	
	if (tecla == ABAJO) {

		if ((juego.mina.posFila + 1 < juego.mina.nFilas) &&
			(juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] != MURO)) {


			if (juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] == GEMA) {
				
				juego.contGemas++;
				juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posFila++;
			}
			else if ((juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] == PIEDRA) && 
						(juego.mina.plano[juego.mina.posFila + 2][juego.mina.posColumna] == LIBRE)) {	
					
					juego.mina.plano[juego.mina.posFila + 2][juego.mina.posColumna] = PIEDRA;
					juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] = MINERO;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
					juego.mina.posFila++;

			}
			else if ((juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] == TIERRA) ||
						(juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] == LIBRE)) {
				
				juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posFila++;
			}

			else if (juego.mina.plano[juego.mina.posFila + 1][juego.mina.posColumna] == SALIDA) {

				salida = true;
			}
			else {
				//NO HACER NADA, NO SE PUEDE REALIZAR NINGUN MOVIMIENTO HACIA ESA POSICION
			}

		}

	}
	
	
	if (tecla == DCHA) {

		if ((juego.mina.posColumna + 1 < juego.mina.nColumnas) &&
			(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] != MURO)) {


			if (juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] == GEMA) {
				
				juego.contGemas++;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posColumna++;
			}
			else if ((juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] == PIEDRA) &&
						(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 2] == LIBRE)) {				
										
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 2] = PIEDRA;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] = MINERO;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
					juego.mina.posColumna++;

			}
			else if ((juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] == TIERRA) ||
				(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] == LIBRE)){

				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posColumna++;
			}

			else if (juego.mina.plano[juego.mina.posFila][juego.mina.posColumna + 1] == SALIDA) {

				salida = true;
			}
			else {
				//NO HACER NADA, NO SE PUEDE REALIZAR NINGUN MOVIMIENTO HACIA ESA POSICION
			}

		}
	}
	

	if (tecla == IZDA) {

		if ((juego.mina.posColumna - 1 >= 0) &&
			(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] != MURO)) {


			if (juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] == GEMA) {

				
				juego.contGemas++;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posColumna--;
			}
			else if ((juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] == PIEDRA) &&
				(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 2] == LIBRE)) {	
					
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 2] = PIEDRA;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] = MINERO;
					juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
					juego.mina.posColumna--;
									
			}
			else if ((juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] == TIERRA) ||
				(juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] == LIBRE)){
				
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] = MINERO;
				juego.mina.plano[juego.mina.posFila][juego.mina.posColumna] = LIBRE;
				juego.mina.posColumna--;

			}
			else if (juego.mina.plano[juego.mina.posFila][juego.mina.posColumna - 1] == SALIDA) {

				salida = true;
			}
			else {
				//NO HACER NADA, NO SE PUEDE REALIZAR NINGUN MOVIMIENTO HACIA ESA POSICION
			}

		}
	}

	
	if (tecla == TNT) {

		int i = 0;
		while (juego.mina.plano[juego.mina.posFila + i + 1][juego.mina.posColumna] == LIBRE && juego.mina.posFila + i < juego.mina.nFilas - 1) {
			i++;
			//ESTO ESTA AÑADIDO PARA QUE SE APRECIE COMO CAE LA DINAMITA EN LA PANTALLA
			juego.mina.plano[juego.mina.posFila + i][juego.mina.posColumna] = DINAMITA;
			system("cls");
			dibujar(juego, eleccionDibujar);
			Sleep(15);
			juego.mina.plano[juego.mina.posFila + i][juego.mina.posColumna] = LIBRE;
		}
		
		juego.mina.plano[juego.mina.posFila + i][juego.mina.posColumna] == TNT;
		for (int x = juego.mina.posFila + i - 1; x <= juego.mina.posFila + i + 1; x++) {
			for (int y = juego.mina.posColumna - 1; y <= juego.mina.posColumna + 1; y++) {
				juego.mina.plano[x][y] = LIBRE;
			}
		}

		juego.numDinamitas++;


	}
	juego.numMovimientos++;


	return salida;
}


void dibujar(const tJuego& juego, int eleccionEscala) {
	
	if (eleccionEscala == 1) {
		dibujar1_1(juego.mina);
	}
	else {
		dibujar1_3(juego.mina);
	}
	mostrarDatos(juego);
}

void mostrarDatos(tJuego juego)
{
	cout << "\nGemas totales recogidas: " << juego.contGemas << "\n";
	cout << "Numero de movimientos: " << juego.numMovimientos << "\n";
	cout << "Dinamitas usadas: " << juego.numDinamitas << "\n";
}

//Convierte la tecla pulsada por el usuario a un enumerado de tTecla
tTecla leerTecla() {
	
	tTecla cartaelegida;
	int dir;
	dir = _getch();
	if (dir == 224) {
		dir = _getch();
		if (dir == 72) {
			cartaelegida = ARRIBA;
		}
		else if (dir == 77) {
			cartaelegida = DCHA;
		}
		else if (dir == 75) {
			cartaelegida = IZDA;
		}
		else {
			cartaelegida = ABAJO;
		}
	}
	else if (dir == 13) {
		cartaelegida = SALIR;
	}
	else if (dir == 100 || dir == 68) {
		cartaelegida = TNT;
	}
	else {
		cartaelegida = NADA;
	}

	return cartaelegida;
}

//Convierte los char leidos del fichero a los enumerados de tTecla
tTecla fichero2tecla(char casilla) { 

	tTecla cas;
	switch (casilla)
	{
	case 'A': cas = ARRIBA;
		break;
	case 'Z': cas = ABAJO;
		break;
	case 'N': cas = IZDA;
		break;
	case 'M': cas = DCHA;
		break;
	default:
		cas = NADA;
		break;
	}

	return cas;
}

int menu0() {
	int eleccion;
	do {
		cout << "1. Jugar partida a escala 1:1\n"
			<< "2. Jugar partida a escala 1:3\n"
			<< "0. Salir\n\n"
			<< "Introduce una opcion:\n";

		cin >> eleccion;
		system("cls");
	} while (!((eleccion == 0) || (eleccion == 1) || (eleccion == 2)));

	return eleccion;
}

int menu1() {
	int eleccion;
	do {
		cout << "1. Introducir movimiento por teclado\n"
			<< "2. Introducir movimiento por fichero\n"
			<< "0. Salir\n\n"
			<< "Introduce una opcion:\n";

		cin >> eleccion;
		system("cls");
	} while (!((eleccion == 0) || (eleccion == 1) || (eleccion == 2)));

	return eleccion;
}

int menu2() {
	int eleccion;

	do {
		cout << "1. Jugar siguiente nivel\n"
			<< "0. Salir\n\n"
			<< "Introduce una opcion: ";

		cin >> eleccion;
		system("cls");

	} while (!((eleccion == 0) || (eleccion == 1) || (eleccion == 2)));

	return eleccion;
}
