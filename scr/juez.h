


#ifndef JUEZ_H_
#define JUEZ_H_

class Juez{

private:

	Lista<jugador*>* jugadores;
	Mapa* tableroDeJuego;


public:

	Juez(unsigned int cantidadJugadores,Mapa* recibido);

	void avanzarJugador();

	void mostrarJugador();

	void insertarJugador(Jugador* nuevo);
	
	void eliminarJugador();


};



#endif /* JUEZ_H_ */



#endif /* JUEZ_H_ */
