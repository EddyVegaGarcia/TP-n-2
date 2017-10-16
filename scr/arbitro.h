


#ifndef ARBITRO_H_
#define ARBITRO_H_

typedef char jugador;

class Arbitro{

private:

	Lista jugadores; //podria ser *string, tendriamos que ver bien eso
	Lista eliminados;
	Jugador* jugadorActual;

public:

	//pre: cantidadJugadores >= 1
	//post: crea los jugadores y los enlista
	Arbitro(int cantidadJugadores);

	//pre:
	//post: avanza el turno al jugador siguiente
	void avanzarJugador();

	//pre:
	//post: verifica si el respectivo jugador gano la partida
	bool haGanado(Jugador aVerificar); //no lo hice

	//pre:
	//post: muestra por pantalla al jugador en turno
	void mostrarJugador;

	//pre:
	//post: elimina al jugador en turno
	void eliminarJugador;

};



#endif /* ARBITRO_H_ */
