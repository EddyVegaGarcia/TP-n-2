#ifndef JUEZ_H_
#define JUEZ_H_

# include "mapa.h"
# include "jugador.h"
# include <iostream>

class Juez{

private:
	int cantidadDeJugadores;
	Lista<Jugador*>* jugadores;
	Mapa* tableroDeJuego;

public:

	Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido);

	void avanzarJugador();

	void mostrarJugador();

	void insertarJugador(Jugador* nuevo);
	
	void inicializarJuego();
	
	void sigueJugando(Jugador* jugadorActual, int &jugadoresQuePerdieron, Mapa* tableroDeJuego);

	void elJugadorHaPerdido(Jugador* jugadorActual);
	
	~Juez();
	


};

#endif /* JUEZ_H_ */
