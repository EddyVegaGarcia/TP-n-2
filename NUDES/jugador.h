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
	Mapa* mapa;


	/* Pre: "letra" no es alias de ningun otro jugador.
	 * Post: Deja al jugador con el alias "letra".*/
	void asignarAlias(char letra);

	/* Pre: Recibe "puntos" de tipo int.
	 * Post: Deja al jugador con el puntaje "puntos".*/
	void asignarPuntaje(int puntos);


	/* Pre: Recibe un puntero al mapa de juego.
	 * Post: Crea un objeto Jugada y apunta pJugada a jugada.*/
	void inicializarPunteroAJugada(Mapa* punteroAMapa);
	
	bool PreguntarSiQuiereModificarJugadas();


	bool validarOpcionUser(char opcionUser);
	bool validarOpcionUserConfirmacion(char opcionUser);
	/*
	char pedirOpcionUser();

	*/
	

public:
	/* Pre: Recibe una letra, futuro alias del jugador a crear, y un puntero al mapa de juego.
	 * 	Ningun jugador existente tiene por alias "letra".
	 * Post: Crea un jugador con alias "letra", estado "SIGUE_JUGANDO" y puntaje 0.
	 *	Crea una jugada y asigna su dirección al puntero pJugada.*/
	Jugador(char letra, Mapa* punteroAMapa);

	/* Pre: Recibe "puntos" de tipo int.
	 * Post: Suma "puntos" al puntaje del jugador.*/
	void modificarPuntaje(int puntos);

	
	/* Post: Devuelve el alias del jugador.*/
	char obtenerAlias();

	/* Post: Devuelve el puntaje del jugador.*/
	int obtenerPuntaje();
	
	/* Post: Devuelve el estado actual del jugador.*/
	int obtenerEstado();
	
	/* Post: Deja al jugador con estado "estado". Estado puede tomar uno de los siguientes valores:
	 * SIGUE_JUGANDO, SE_RETIRO, PERDIO_PARTIDA, HA_GANADO, NO_ESTA_JUGANDO.*/
	void asignarEstado(int estado);




	/* Pre: 
	 * Post: Pide fila, columna y opcion al user y los asigna a la jugada.*/
	void iniciarJugada();
	
	/* Post: Devuelve la ultima jugada realizada por el jugador
	 */
	Jugada* obtenerPJugada();
	
	
	/* Post: Libera los recursos asociados al Jugador. */
	~Jugador();

};

#endif /* JUGADOR_H_ */
