#include "jugador.h"
# include <iostream>
using namespace std;


// métodos púbicos
void Jugador::modificarPuntaje(int punt){
	puntaje+=punt;
}
char Jugador::obtenerAlias(){
	return alias;
}
int Jugador::obtenerPuntaje(){
	return puntaje;
}


// constructor, inicializar
Jugador::Jugador(char letra){
	asignarAlias(letra);
	asignarPuntaje(0);
	inicializarPuntero();
}

// métodos privados
void Jugador::asignarAlias(char letra){
	alias=letra;
}

void Jugador::asignarPuntaje(int puntos){
	puntaje=puntos;
}

void Jugador::inicializarPuntero(){
	Jugada jugada;
	pJugada=&jugada;
}


void Jugador::iniciarJugada(){
	int filaUser, colUser;
	char opcionUser;

	cout << "Ingrese 'i j o', donde i y j son el num de fila y columna, y o es la opcion:" << endl;
	cin >> filaUser >> colUser >> opcionUser;

	// validar // debug // ver

	pJugada->asignarFila(filaUser);
	pJugada->asignarColumna(colUser);
	pJugada->asignarOpcion(opcionUser);
	pJugada->realizarJugada();

}
