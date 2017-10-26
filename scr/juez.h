


#ifndef JUEZ_H_
#define JUEZ_H_

class Juez{

private:

	Lista<jugador*>* jugadores;
	Mapa* tableroDeJuego;


public:

	Juez::Juez(unsigned int cantidadJugadores,Mapa* recibido);

	void Juez::avanzarJugador();

	void Juez::mostrarJugador();

	void Juez::insertarJugador(Jugador* nuevo);

};



#endif /* JUEZ_H_ */



#endif /* JUEZ_H_ */
