/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/
#include "Mina.h"


void cargar_Mina(ifstream& fichero, tMina& mina) {
	
	
	fichero >> mina.nFilas;
	fichero >> mina.nColumnas;
	char casilla = 0;

	for (int i = 0; i < mina.nFilas; i++) {
		fichero.get(casilla);
		for (int j = 0; j < mina.nColumnas; j++) {
			fichero.get(casilla);
			if (casilla == 'J') {
				mina.posFila = i;
				mina.posColumna = j;
			}
			mina.plano[i][j] = char2casilla(casilla);
		}
	}
}

void dibujar1_1(const tMina& mina){

	tCasilla figura;
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			figura = mina.plano[i][j];
			colorFondo(numColor(figura));
			cout << casilla2char(figura);	
			colorFondo(0);
		}
		cout << "\n";
	}

	colorFondo(0);
}

void dibujar1_3(const tMina& mina) {

	tCasilla figura;
	/*for (int i = 0; i < mina.nFilas; ++i) {

		for (int k = 0; k < 3; ++k) {

			for (int j = 0; j < mina.nColumnas; ++j) {			

				for (int l = 0; l < 3; ++l) {

						figura = mina.plano[i][j];
						colorFondo(numColor(figura));
						cout << casilla2char(figura);
						colorFondo(0);					
				}
				
				
			}

			cout << '\n';
		}
	}*/

	tPlanoCaracteres caracteres;
	tPlanoColores colores;

	for (int i = 0; i < mina.nFilas; ++i) {

		for (int j = 0; j < mina.nColumnas; ++j) {

			dibuja3x3(mina.plano[i][j], caracteres, colores, i, j); //rellenamos el tPlanoCaracteres y tPlanoColores
		}
	}

	for (int i = 0; i < mina.nFilas * 3; ++i) { //imprimos el tPlanoCaracteres y tPlanoColores

		for (int j = 0; j < mina.nColumnas * 3; ++j) {

			colorFondo(colores[i][j]);
			cout << setw(2) << caracteres[i][j];
			colorFondo(0);
		}
		cout << "\n";
	}

}

void dibuja3x3(tCasilla casilla, tPlanoCaracteres &caracteres, tPlanoColores &colores, int i, int j) {

	int contador = 0;
	for (int l = i* 3; l < 3 + i * 3; l++) {
		for (int k = j * 3; k < 3 + j * 3; k++) {
			
			switch (casilla)
			{
			case LIBRE:
				caracteres[l][k] = ' ';
				colores[l][k] = numColor(casilla);
				break;
			case TIERRA:
				caracteres[l][k] = '.';
				colores[l][k] = numColor(casilla);
				break;
			case GEMA:
				if (contador == 0) {
					caracteres[l][k] = 'G';
				}
				if (contador == 1) {
					caracteres[l][k] = 'E';
				}
				if (contador == 2) {
					caracteres[l][k] = 'M';
				}
				if (contador == 3) {
					caracteres[l][k] = 'E';
				}
				if (contador == 4) {
					caracteres[l][k] = ' ';
				}
				if (contador == 5) {
					caracteres[l][k] = 'A';
				}
				if (contador == 6) {
					caracteres[l][k] = 'M';
				}
				if (contador == 7) {
					caracteres[l][k] = 'A';
				}
				if (contador == 8) {
					caracteres[l][k] = '_';
				}
				contador++;
				colores[l][k] = numColor(casilla);

				break;
			case PIEDRA:
				caracteres[l][k] = '@';
				colores[l][k] = numColor(casilla);

				break;
			case MURO:
				caracteres[l][k] = 'X';
				colores[l][k] = numColor(casilla);

				break;
			case SALIDA:
				if (contador == 0) {
					caracteres[l][k] = 'S';
				}
				if (contador == 1) {
					caracteres[l][k] = 'A';
				}
				if (contador == 2) {
					caracteres[l][k] = 'L';
				}
				if (contador == 3) {
					caracteres[l][k] = 'I';
				}
				if (contador == 4) {
					caracteres[l][k] = 'D';
				}
				if (contador == 5) {
					caracteres[l][k] = 'A';
				}
				if (contador == 6) {
					caracteres[l][k] = 'E';
				}
				if (contador == 7) {
					caracteres[l][k] = 'S';
				}
				if (contador == 8) {
					caracteres[l][k] = 'C';
				}
				contador++;
				colores[l][k] = numColor(casilla);

				break;
			case MINERO:
				if (contador == 0) {
					caracteres[l][k] = 'M';
				}
				if (contador == 1) {
					caracteres[l][k] = 'I';
				}
				if (contador == 2) {
					caracteres[l][k] = '-';
				}
				if (contador == 3) {
					caracteres[l][k] = 'N';
				}
				if (contador == 4) {
					caracteres[l][k] = 'E';
				}
				if (contador == 5) {
					caracteres[l][k] = '-';
				}
				if (contador == 6) {
					caracteres[l][k] = 'R';
				}
				if (contador == 7) {
					caracteres[l][k] = 'O';
				}
				if (contador == 8) {
					caracteres[l][k] = '!';
				}
				contador++;
				colores[l][k] = numColor(casilla);

				break;
			case DINAMITA:
				if (contador == 0) {
					caracteres[l][k] = 'D';
				}
				if (contador == 1) {
					caracteres[l][k] = 'I';
				}
				if (contador == 2) {
					caracteres[l][k] = 'N';
				}
				if (contador == 3) {
					caracteres[l][k] = 'A';
				}
				if (contador == 4) {
					caracteres[l][k] = 'M';
				}
				if (contador == 5) {
					caracteres[l][k] = 'I';
				}
				if (contador == 6) {
					caracteres[l][k] = 'T';
				}
				if (contador == 7) {
					caracteres[l][k] = 'A';
				}
				if (contador == 8) {
					caracteres[l][k] = '!';
				}
				contador++;
				colores[l][k] = numColor(casilla);

				break;
			default:
				break;
			}
		}
	}
	
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

//Asigna un color mediante un entero dependiendo de la casilla correspondiente
int numColor(tCasilla figura){

	int color;
	if (figura == GEMA) {
		color = 2; //VERDE
	}
	else if (figura == SALIDA) {
		color = 1; //AZUL OSCURO
	}
	else if (figura == MINERO) {
		color = 7; //GRIS
	}
	else if (figura == DINAMITA) {
		color = 4; //¿ROJO?
	}
	else {
		color = 6; //MARRON
	}

	return color;
}

//Convierte las casillas del tablero a su correspondiente simbolo
string casilla2char(tCasilla casilla) {

	string figura;

	switch (casilla)
	{
	case MURO: figura = " X";
		break;
	case MINERO: figura = " M";
		break;
	case GEMA: figura = " G";
		break;
	case SALIDA: figura = " S";
		break;
	case PIEDRA: figura = " @";
		break;
	case TIERRA: figura = " .";
		break;
	case DINAMITA: figura = " D";
		break;
	default:
		figura = "  ";
		break;
	}

	return figura;
}

//Convierte los char leidos del fichero tablero a enumerados de tCasilla
tCasilla char2casilla(char casilla) { 

	tCasilla cas;
	switch (casilla)
	{
	case 'M': cas = MURO;
		break;
	case 'G': cas = GEMA;
		break;
	case 'J': cas = MINERO;
		break;
	case 'P': cas = PIEDRA;
		break;
	case 'S': cas = SALIDA;
		break;
	case 'T': cas = TIERRA;
		break;
	default:
		cas = LIBRE;
		break;
	}

	return cas;
}

