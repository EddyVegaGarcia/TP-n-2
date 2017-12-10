#ifndef JUEZ_H_
#define JUEZ_H_

# include "mapa.h"
# include "jugador.h"
# include "constantes.h"
# include "listaCircularCursor.h"
# include <iostream>
# include <fstream>
# include "jugadaLight.h"
# include "antiDestapador.h"
# include "pseudoGrafo.h"
# include "pantalla.h"

class Juez{

	private:
		int cantidadDeJugadores;
		ListaCircularCursor<Jugador*>* jugadores;
		PseudoGrafo<JugadaLight*>* jugadas;
		Mapa* tableroDeJuego;
		int jugadoresQuePerdieron;
		uint casillasOcultas;
		uint minasPorDescubrir;

	public:
		/* Pre: Recibe una "cantidadDeJugadores" de tipo int, y un puntero a Mapa o "tableroDeJuego".
		* Post: Se crea un Juez con la cantidadDeJugadores y tableroDeJuego pasados por parámetros,
		* 	deja creada una lista con cantidadDeJugadores punteros a Jugador.*/
		Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido);

		/* Post: inicia el juego. Esto es, pide jugadas a los jugadores por turnos, las jugadas se realizan,
		* 	se modifican los puntajes, se muestra el tablero, verifica si cada jugador ganó o perdió y se
		* 	muestran los mensajes correspondientes. */
		void inicializarJuego();



		/* Post: Libera los recursos asociados a Juez.*/
		~Juez();

	private:
		/* Pre: Se ha llamado a crearYAsignarListaDeJugadores()
		* Post: Crea a los jugadores y los agrega a la lista.*/
		void crearJugadores();

		/* Post: Crea una lista de jugadores.*/
		void crearYAsignarListaDeJugadores();

		/* Pre: Se ha llamado a crearYAsignarListaDeJugadores(). Recibe un puntero a un Jugador.
		* Post: Inserta "nuevo" a la lista de jugadores creada por crearYAsignarListaDeJugadores().*/

		void crearYAsignarGrafoDeJugadas();

		void insertarJugador(Jugador* nuevo);

		/* Post: avanza hasta el jugador más próximo que siga jugando.*/
		void avanzarJugador();

		//void mostrarJugador(); /* A esto si lo quieren usar para algo, hay que cambiarlo (es corito, pero no sé qué quieren mostrar)*/


		/* Pre: Recibe un puntero al jugadorActual, una variable de tipo int que indica la cantidad de jugadores que perdieron,
		* 	un puntero a Mapa, y una variable de tipo unsigned int que indica la cantidad de minas que quedan por descubrir
		* 	en el tablero.
		* Post: da su turno al jugadorActual y muestra el tablero de juego.*/
		void sigueJugando(Jugador* jugadorActual,Mapa* tableroDeJuego);

		void crearArchivoConPuntajes();

		void encontrarJugadorQueGanoPorPuntaje();

		uint buscarBanderasCorrectas();

		bool banderaEsCorrecta(Bandera actual,Lista<Mina>* minas);

		void realizarCambios();

		bool deshacerJugada();

		bool rehacerJugada();

		void rehacerParalela(uint posicion);
};

#endif /* JUEZ_H_ */
