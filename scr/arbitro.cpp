// tengo una duda con cursores y con como vamos a usar el objeto
// lo vemos despues 

#include "arbitro.h"
#include "lista.h"


void Arbitro::Arbitro(int cantidadJugadores){

	char caracterDeJugador = 'A';

	eliminados = NULL;

	for(int i=1; i<=cantidadJugadores; i++){

		jugadores.insertarJugador(i,caracterDeJugador);
		caracterDeJugador++;

	}

	jugadorActual = jugadores.primero;

}

void Arbitro::avanzarJugador(){

	jugadorActual = jugadorActual.siguiente;

}

bool Arbitro::haGanado(Jugador aVerificar){

	bool jugadorGano = false;

}

bool Arbitro::mostrarJugador(){

	std::cout<<"Jugador: "<<*jugadorActual.alias<<std::endl;

}

bool Arbitro::mostrarPuntaje(){

	std::cout<<"Puntaje: "<<*jugadorActual.puntaje<<std::endl;

}
