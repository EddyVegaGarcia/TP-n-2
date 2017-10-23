#ifndef JUGADOR_H_
#define JUGADOR_H_
# include "jugada.h"
# include "mapa.h"
# include "constantes.h"

class Jugador {
private:
	char alias;
	int puntaje;
	int estado;
	Jugada* pJugada;

	/* Pre: "letra" no es alias de ningun otro jugador.
	 * Post: asigna letra al atributo alias.*/
	void asignarAlias(char letra);

	/* Pre: recibe punt de tipo int.
	 * Post: asigna punt a puntaje. */
	void asignarPuntaje(int puntos);

	/* Post: crea un objeto jugada y apunta pJugada a jugada. */
	void inicializarPunteroAJugada(Mapa* punteroAMapa);
	
	/* Post: inicializa el estado del jugador (sigue jugando, se retiro, perdio partida). */
	void asignarEstado(int estado){
	
public:
	/* Pre: ningun jugador existente tiene por alias "letra".
	 * Post: crea un jugador. Crea una jugada y asigna su dirección al puntero pJugada.
	 * inicializa alias en letra y puntaje en cero. */
	Jugador(char letra, Mapa* punteroAMapa);

	/* Pre: recibe punt de tipo int.
	 * Post: suma punt a puntaje. */
	void modificarPuntaje(int puntos);

	/* Post: devuelve el alias del jugador. */
	char obtenerAlias();

	/* Post: devuelve el puntaje del jugador. */
	int obtenerPuntaje();
	
	/* Pre:
	 * Post: pide fila, columna y opcion al user y los asigna a la jugada. */
	void iniciarJugada();

};

#endif /* JUGADOR_H_ */
