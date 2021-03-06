

# include "jugador.h"
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
int Jugador::obtenerEstado(){
	return this-> estado;
}


// constructor, inicializar
Jugador::Jugador(char letra, Mapa* punteroAMapa){
	asignarAlias(letra);
	asignarPuntaje(0);
	asignarEstado(SIGUE_JUGANDO);
	inicializarPunteroAJugada(punteroAMapa);
}

// métodos privados
void Jugador::asignarAlias(char letra){
	this->alias=letra;
}

void Jugador::asignarPuntaje(int puntos){
	this->puntaje=puntos;
}

void Jugador::asignarEstado(int estado){
	this->estado=estado;
}
	
	
void Jugador::inicializarPunteroAJugada(Mapa* punteroAMapa){
	//Jugada jugada(punteroAMapa);
	//this->pJugada=&jugada;

	this->pJugada = new Jugada(punteroAMapa);
}


void Jugador::iniciarJugada(){
	uint filaUser, colUser;
	char opcionUser;
    int puntos = 0;
	cout << "turno del jugador: "<< this->alias << endl;
	cout << "Ingrese numero de fila de la casilla "<<endl;
	cin >>filaUser;
	cout << "ingrese numero de columna de la casilla"<<endl;
	cin >>colUser;
	cout<<"digite 'd' o 'm' segun quiera destapar o marcar la casilla"<<endl;
	cin >>opcionUser;


	// validar // debug // ver
	this->pJugada->asignarOpcion(opcionUser);

	this->pJugada->asignarFila(filaUser);

	this->pJugada->asignarColumna(colUser);



	puntos = this->pJugada->realizarJugada();
	
	if (puntos!=PERDIO_PARTIDA && puntos!=SE_RETIRO){
		puntos += obtenerPuntaje();
		this->modificarPuntaje(puntos);
	}
	else if (puntos == PERDIO_PARTIDA)
		this->asignarEstado(PERDIO_PARTIDA);
	else if (puntos == SE_RETIRO)
		this->asignarEstado(SE_RETIRO);
}

Jugador::~Jugador(){
        delete pJugada;
}

