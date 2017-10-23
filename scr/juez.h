


#ifndef JUEZ_H_
#define JUEZ_H_

class Juez{

private:

	Lista* jugadores; //podria ser *string, tendriamos que ver bien eso

public:

	//pre: cantidadJugadores >= 1
	//post: crea los jugadores y los enlista
	Arbitro(unsigned int cantidadJugadores);

	//pre:
	//post: avanza el turno al jugador siguiente
	void avanzarJugador();

	//pre:
	//post: verifica si el respectivo jugador gano la partida
	bool haGanado(Jugador aVerificar); //no lo hice

	//pre:
	//post: muestra por pantalla los datos del jugador en turno
	void mostrarJugador;

	void insertarJugador(Jugador nuevo);

	//pre:
	//post: elimina al jugador en turno
	void eliminarJugador;

};



#endif /* JUEZ_H_ */
