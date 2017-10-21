#include "jugador.h"
# include "constantes.h"
# include <iostream>
using namespace std;


// métodos púbicos
void Jugador::modificarPuntaje(int puntos){
	this->puntaje+=puntos;
}
char Jugador::obtenerAlias(){
	return alias;
}
int Jugador::obtenerPuntaje(){
	return puntaje;
}


// constructor, inicializar
Jugador::Jugador(char letra, Mapa* punteroAMapa){
	asignarAlias(letra);
	asignarPuntaje(0);
	asignarEstado();
	inicializarPunteroAJugada(punteroAMapa);
}

// métodos privados
void Jugador::asignarAlias(char letra){
	this->alias=letra;
}

void Jugador::asignarPuntaje(int puntos){
	this->puntaje=puntos;
}

void Jugador::asignarEstado(){
	this->haPerdido=false;
}
	
	
void Jugador::inicializarPunteroAJugada(Mapa* punteroAMapa){
	Jugada jugada(punteroAMapa);
	this->pJugada=&jugada;
}


void Jugador::iniciarJugada(){
	uint filaUser, colUser;
	char opcionUser;
        int puntos = 0;
	cout << "Ingrese 'i j o', donde i y j son el num de fila y columna, y o es la opcion:" << endl;
	cin >> filaUser >> colUser >> opcionUser;

	// validar // debug // ver

	pJugada->asignarFila(filaUser);
	pJugada->asignarColumna(colUser);
	pJugada->asignarOpcion(opcionUser);
	puntos = pJugada->realizarJugada();
	
	if (puntos!=HAPERDIDO){
		puntos += obtenerPuntaje() 
		modificarPuntaje(puntos);
	} else
		haPerdido=true;
}
