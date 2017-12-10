#ifndef PANTALLA_H_
#define PANTALLA_H_

# include <iostream>
# include <string>
# include "constantes.h"
# include "pseudoGrafo.h"
# include "jugadaLight.h"
# include "jugador.h"


class Pantalla{

	public:

		void playGame();

		char pedirOpcionPasadoFuturo();

		int pedirOpcionRehacerJugada(PseudoGrafo<JugadaLight*>* jugadas);

		void noSePuedeRetroceder();

		void mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual);

		void terminoLaPartida();

		void noHayJugadas();

		char imprimirOpcionesDeMenu();

		void imprimirReglasDeJuego();

		void imprimirLinea();

		void imprimirTitulo();

		void imprimirPidiendoDatos();

		void imprimirDatosIngresados(uint dimFila, uint dimColumna, std::string dificultadPalabra,
				int numeroDeMinas, uint cantJugadores);

		void pedirDimensiones(uint &filaUser, uint &colUser);

		char pedirDificultad();

		uint pedirCantidadJugadores();

};
#endif
