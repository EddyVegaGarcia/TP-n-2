


#ifndef JUEZ_H_
#define JUEZ_H_

class Juez{

private:
	int cantidadDeJugadores;
	Lista<jugador*>* jugadores;
	Mapa* tableroDeJuego;
	unsigned int turno;

public:

	Juez(unsigned int cantidadJugadores,Mapa* recibido);

	void avanzarJugador();

	void mostrarJugador();

	void insertarJugador(Jugador* nuevo);
	
	void eliminarJugador();
	
	inicializarJuego();
	
	~juez();
	


};



#endif /* JUEZ_H_ */



#endif /* JUEZ_H_ */
