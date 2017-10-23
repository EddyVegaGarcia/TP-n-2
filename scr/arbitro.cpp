


#include "arbitro.h"
#include "lista.h"


void Arbitro::Arbitro(int cantidadJugadores){

	char caracterDeJugador = 'A';

	for(int i=1; i<=cantidadJugadores; i++){

		this-> jugadores-> insertar(caracterDeJugador,i)

	}


}

void Arbitro::avanzarJugador(){

	if (this-> jugadores -> cursor == NULL)
		this-> jugadores -> cursor -> iniciarCursor();
	else
		this-> jugadores -> avanzarCursor();

}

bool Arbitro::haGanado(Jugador aVerificar){

	bool jugadorGano = false;

}

bool Arbitro::mostrarJugador(){

	Jugador actual = this-> jugadores -> obtenerCursor();

	std::cout<<"Jugador: "<< Jugador.nombre<< std::endl;

}

void insertarJugador(Jugador nuevo){

	this-> jugadores -> insertar(nuevo);

}

bool Arbitro::mostrarPuntaje(){

	Jugador actual = this-> jugadores -> obtenerCursor();

	std::cout<<"Puntaje:"<< Jugador.puntaje<< std::endl;

}

void Arbitro::eliminarJugador(){

	this-> jugadores -> remover();
}
