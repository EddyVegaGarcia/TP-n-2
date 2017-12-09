#ifndef JUGADALIGHT_H_
#define JUGADALIGHT_H_

# include <iostream>
# include "destapador.h"
# include "marcador.h"
# include "mapa.h"
#include "constantes.h"

class JugadaLight{

	private:

		char opcion;
		int fila;
		int columna;
		char jugador;


	public:
		JugadaLight(char opcion, char jugador, int fila, int columna);
		//pre:
		//post: devuelve la fila actual
		int obtenerFila();

		//pre:
		//post: devuelve la columna actual
	    int obtenerColumna();
		//pre:
		//post: devuelve la opcion actual
	    char obtenerOpcion();

	    char obtenerJugador();

		//pre: se pasa como parámetro la opción que el usuario ingresó, es decir una D si
		//quiere destapar una casilla, M si la quiere marcar o R si quiere retirarse.
		//post: queda la opcion de la jugada registrada.
		void asignarOpcion(char opcionDeUsuario);

		//pre: se pasa por parámetro la fila que el usuario ingresó, ésta debe ser válida,
		// es decir dentro de las dimensiones especificadas al comienzo del juego.
		//post: la fila queda registrada.
		void asignarFila(int fila);

		//pre: se pasa por parámetro la columna que el usuario ingresó, ésta debe ser válida,
		// es decir dentro de las dimensiones especificadas al comienzo del juego.
		//post: la columna queda registrada.
		void asignarColumna(int columna);


		void asignarJugador(char jugador);


		bool operator == (JugadaLight b);

};

#endif /*JUGADA_H_*/
