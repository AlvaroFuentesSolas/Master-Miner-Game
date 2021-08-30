/*
ANTONIO RÓDENAS CILLER
ÁLVARO FUENTES SOLAS
*/

#include "Juego.h"
#include "Puntuaciones.h"

string nombreSinBlancos() {

	char palabra[30];
	string cadena;

	cout << setw(40) << "Introduce tu nombre de jugador/a: ";
	cin.getline(palabra, 30);//optienes la cadena completa del array

	for (int i = 0; palabra[i] != 0; ++i) {
		if (palabra[i] != 32)
			cadena += palabra[i];
	}

	return cadena;
}

bool cargar_Marcador(tPuntuaciones & marcador){
	
	bool cargarCorrecta = false;
	string texto;
	ifstream fileIn;
	fileIn.open("puntuaciones.txt");
	if (fileIn.is_open()) {
		inicializar_Marcador(marcador);
		while (!fileIn.eof()){			
			fileIn >> texto;
			if (texto != "000") {

				if (marcador.capacidad == marcador.num_jugadores) {
					aumentar_Capacidad(marcador);
				}
				marcador.array_clasificacion[marcador.num_jugadores].nombre = texto;
				fileIn >> marcador.array_clasificacion[marcador.num_jugadores].punt_total;
				fileIn >> marcador.array_clasificacion[marcador.num_jugadores].minasRecorridas;
				for (int a = 0; a < marcador.array_clasificacion[marcador.num_jugadores].minasRecorridas; a++) {
					fileIn >> marcador.array_clasificacion[marcador.num_jugadores].vMinasRecorridas[a].IdMina;
					fileIn >> marcador.array_clasificacion[marcador.num_jugadores].vMinasRecorridas[a].numMovimientos;
					fileIn >> marcador.array_clasificacion[marcador.num_jugadores].vMinasRecorridas[a].numGemas;
					fileIn >> marcador.array_clasificacion[marcador.num_jugadores].vMinasRecorridas[a].numDinamitas;
					fileIn >> marcador.array_clasificacion[marcador.num_jugadores].vMinasRecorridas[a].puntosMina;
				}

				marcador.num_jugadores++;
			}

		}		
		cargarCorrecta = true;
	}
	fileIn.close();
	return cargarCorrecta;
}

bool guardar_Marcador(tPuntuaciones & marcador){
	
	bool guardado = false;
	ofstream salida;
	salida.open("puntuaciones.txt");

	if (salida.is_open()) {
		for (int i = 0; i < marcador.num_jugadores; i++) {
			salida << marcador.array_clasificacion[i].nombre << "\n";
			salida << marcador.array_clasificacion[i].punt_total << "\n";
			salida << marcador.array_clasificacion[i].minasRecorridas << "\n";
			for (int a = 0; a < marcador.array_clasificacion[i].minasRecorridas; a++) {				
				salida << marcador.array_clasificacion[i].vMinasRecorridas[a].IdMina << " "
					<< marcador.array_clasificacion[i].vMinasRecorridas[a].numMovimientos << " "
					<< marcador.array_clasificacion[i].vMinasRecorridas[a].numGemas << " "
					<< marcador.array_clasificacion[i].vMinasRecorridas[a].numDinamitas << " "
					<< marcador.array_clasificacion[i].vMinasRecorridas[a].puntosMina << "\n";			
			}
		}
		salida.close();
		guardado = true;
	}
	else {
		cout << "No se ha podido guardar las partidas jugadas";
	}

	return guardado;
	
}

void mostrar_Minas_Usuario(const tPuntuaciones & marcador, int cont){

	ordenarPorNivel(marcador.array_clasificacion[cont]);

	cout << marcador.array_clasificacion[cont].nombre;
	cout << "  Movimientos   Gemas   Dinamitas  Puntos        Puntos en total\n";
	for (int i = 0; i < marcador.array_clasificacion[cont].minasRecorridas; i++) {
		cout << "Mina  " << marcador.array_clasificacion[cont].vMinasRecorridas[i].IdMina << setw(9)
			<< marcador.array_clasificacion[cont].vMinasRecorridas[i].numMovimientos << setw(11)
			<< marcador.array_clasificacion[cont].vMinasRecorridas[i].numGemas << setw(9)
			<< marcador.array_clasificacion[cont].vMinasRecorridas[i].numDinamitas << setw(12)
			<< marcador.array_clasificacion[cont].vMinasRecorridas[i].puntosMina;
		if (i == 0) {
			cout << setw(23) << marcador.array_clasificacion[cont].punt_total << "\n";
		}
		else {
			cout << "\n";
		}
	}
}

void mostrar_Alfabetico(const tPuntuaciones & marcador){

	cout << setw(53) << "Mira las puntuaciones de los otros jugadores.\n\n";
	cout << setw(55) << "------------  LISTA DE JUGADORES  ------------ \n\n";
	for (int i = 0; i < marcador.num_jugadores; i++) {
		cout << setw(30) << marcador.array_clasificacion[i].nombre << setw(7) << marcador.array_clasificacion[i].punt_total << "\n";
	}
	cout << "\n";
}

void mostrar_Datos_Usuario(const tPuntuaciones & marcador){

	
	cout << setw(40) << "----- JUGADORES ORDENADOS POR NOMBRE -----\n\n";
	for (int i = 0; i < marcador.num_jugadores; i++) {
		mostrar_Minas_Usuario(marcador, i);
	}
}

void ordenarAlfabeticamente(tPuntuaciones & marcador) {
	
	tPuntuacionJugador aux;
	for (int i = 0; i < marcador.num_jugadores; i++) {
		for (int j = 0; j < marcador.num_jugadores - 1; j++) {
			if (marcador.array_clasificacion[j].nombre < marcador.array_clasificacion[j + 1].nombre) { 
				aux = marcador.array_clasificacion[j];
				marcador.array_clasificacion[j] = marcador.array_clasificacion[j + 1];
				marcador.array_clasificacion[j + 1] = aux;
			}
		}
	}
}

void ordenarPorNivel( tPuntuacionJugador & jugador) {

	tDatosMina aux;
	for (int i = 0; i < jugador.minasRecorridas; i++) {
		for (int j = 0; j < jugador.minasRecorridas - 1; j++) {
			if (jugador.vMinasRecorridas[j].IdMina > jugador.vMinasRecorridas[j + 1].IdMina) { 
				aux = jugador.vMinasRecorridas[j];
				jugador.vMinasRecorridas[j] = jugador.vMinasRecorridas[j + 1];
				jugador.vMinasRecorridas[j + 1] = aux;
			}
		}
	}
}

int menu3(tPuntuaciones puntuaciones, int pos) {
	int eleccion;

	do {
		char a = 168;
		cout << "\n" << puntuaciones.array_clasificacion[pos].nombre << ", " << a << "Que mina quieres explorar?.\n";
		cout << "Introduce un numero entre 1 y 5 para explorar una mina y 0 para salir\n";
		cin >> eleccion;

	} while (!((eleccion == 0) || (eleccion == 1) || (eleccion == 2) || (eleccion == 3) || (eleccion == 4) || (eleccion == 5)));

	return eleccion;
}

//Funcion donde cogemos la informacion del tJuego y lo pasamos a la posicion del jugador correspondiente en el array de tPuntuacionesJugador
bool volcarDatos(tPuntuaciones &marcador, tJuego juego, int nivel, int pos) {


	bool minaRecorrida = false, minaMejorada = false;
	int i = 0;
	int puntuacion = calcularPuntuacion(juego);
	while (i < marcador.array_clasificacion[pos].minasRecorridas && !minaRecorrida) { //Recorremos el array de las minas recorridas por el jugador
		if (marcador.array_clasificacion[pos].vMinasRecorridas[i].IdMina == nivel) { //Si econtramos la mina...
			if (marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina < puntuacion) { //... y su puntuacion es menor que la conseguida, sustituimos
				
				marcador.array_clasificacion[pos].vMinasRecorridas[i].IdMina = nivel;
				marcador.array_clasificacion[pos].vMinasRecorridas[i].numDinamitas = juego.numDinamitas;
				marcador.array_clasificacion[pos].vMinasRecorridas[i].numGemas = juego.contGemas;
				marcador.array_clasificacion[pos].vMinasRecorridas[i].numMovimientos = juego.numMovimientos;
				marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina = puntuacion;
				marcador.array_clasificacion[pos].punt_total += marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
				minaMejorada = true;
			}
			
			minaRecorrida = true;
		}
		i++;
	}
	if (minaRecorrida == false) { //Si no hemos encontrado la mina en el array de minas recorridas por el jugador, la añadimos
		marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].IdMina = nivel;
		marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].numDinamitas = juego.numDinamitas;
		marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].numGemas = juego.contGemas;
		marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].numMovimientos = juego.numMovimientos;
		marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].puntosMina = puntuacion;
		marcador.array_clasificacion[pos].punt_total += marcador.array_clasificacion[pos].vMinasRecorridas[marcador.array_clasificacion[pos].minasRecorridas].puntosMina;
		marcador.array_clasificacion[pos].minasRecorridas++;
		minaMejorada = true;
	}

	return minaMejorada;
	
}

int calcularPuntuacion(tJuego juego) {
	
	int puntuacion = juego.mina.nColumnas * juego.mina.nFilas + A * juego.contGemas - juego.numMovimientos - B * juego.numDinamitas;
	return puntuacion;

}




// ------------------------------------- FUNCIONES DEL ARRAY DINAMICO -------------------------------------------------

void aumentar_Capacidad(tPuntuaciones & marcador){
	
	tPuntuacionJugador *aux = new tPuntuacionJugador[marcador.capacidad * 2]; //duplicamos la capacidad del nuevo array

	for (int i = 0; i < marcador.num_jugadores; i++) { //copiamos los datos del array que tenemos al auxiliar
		aux[i] = marcador.array_clasificacion[i];
	}

	delete[] marcador.array_clasificacion; // liberamos memoria
	marcador.array_clasificacion = aux;
	marcador.capacidad = marcador.capacidad * 2;
	aux = nullptr; // liberamos el puntero auxiliar
}

void destruir(tPuntuaciones & marcador){

	marcador.num_jugadores = 0;
	marcador.capacidad = 0;
	delete[] marcador.array_clasificacion; //borramos el array auxiliar
	marcador.array_clasificacion = nullptr;

}

bool buscar(const string & nombre, const tPuntuaciones & marcador, int & pos){
	
	bool encontrado = false;
	int alto = marcador.num_jugadores - 1, bajo = 0, mitad;
	while ((bajo <= alto) && (!encontrado)) {
		mitad = (bajo + alto) / 2;
		if (nombre == marcador.array_clasificacion[mitad].nombre)
			encontrado = true;
		else if (nombre < marcador.array_clasificacion[mitad].nombre)
			alto = mitad - 1;
		else
			bajo = mitad + 1;
	}
	
	pos = mitad;
	
	return encontrado;
}

void insertar(tPuntuaciones & marcador, string const & nombre, int pos){


	if (marcador.capacidad == marcador.num_jugadores) {
		aumentar_Capacidad(marcador);
	}

	for (int i = marcador.num_jugadores - 1; i >= pos; i--) { //Desplazamos todos los elementos una posicion a la derecha del array antes de insertar
		marcador.array_clasificacion[i + 1] = marcador.array_clasificacion[i];
	}	
	marcador.array_clasificacion[pos].nombre = nombre;
	marcador.array_clasificacion[pos].punt_total = 0;
	marcador.array_clasificacion[pos].minasRecorridas = 0;
	marcador.num_jugadores++;
}

void inicializar_Marcador(tPuntuaciones & marcador){
	
	marcador.capacidad = 2;
	marcador.num_jugadores = 0;
	marcador.array_clasificacion = new tPuntuacionJugador[marcador.capacidad];
	
}
