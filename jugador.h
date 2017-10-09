#ifndef JUGADOR_H_
#define JUGADOR_H_
# include "jugada.h"

class Jugador {
private:
	char alias;
	int puntaje;
	Jugada* pJugada;

	/* Pre: ningun jugador existente tiene por alias "letra".
	 * Post: crea un jugador. Crea una jugada y asigna su dirección al puntero pJugada.
	 * inicializa alias en letra y puntaje en cero. */
	Jugador(char letra);

	/* Pre: "letra" no es alias de ningun otro jugador.
	 * Post: asigna letra al atributo alias.*/
	void asignarAlias(char letra);

	/* Pre: recibe punt de tipo int.
	 * Post: asigna punt a puntaje. */
	void asignarPuntaje(int punt);

	/* Post: crea un objeto jugada y apunta pJugada a jugada. */
	void inicializarPuntero();

	/* Pre:
	 * Post: */
	void iniciarJugada();


public:

	/* Pre: recibe punt de tipo int.
	 * Post: suma punt a puntaje. */
	void modificarPuntaje(int punt);

	/* Post: devuelve el alias del jugador. */
	char obtenerAlias();

	/* Post: devuelve el puntaje del jugador. */
	int obtenerPuntaje();

};

#endif /* JUGADOR_H_ */
