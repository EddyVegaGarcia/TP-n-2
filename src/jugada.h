#ifndef JUGADA_H_
#define JUGADA_H_

# include <iostream>
# include "destapador.h"
# include "marcador.h"
# include "mapa.h"
#include "constantes.h"

class Jugada{
	
	private:
	
		char opcion;
		int fila;
		int columna;
		int puntaje;
		Mapa* mapa;
		
	public:
	
		//pre: recibe como parámetro un puntero al mapa de juego.
		//post: crea una jugada que se realizará en el mapa.
		Jugada(Mapa* mapa);
		
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
	
		//pre: fila, columna y opción ya están asignadas.
		//post: según la opcion que se registró anteriormente se realizara la jugada, es
		//decir, se destapará la casilla, se marcará ésta, o se retirará el jugador, se 
		//devolverá el puntaje ganado con la jugada hecha.
		int realizarJugada();
			
};

#endif /*JUGADA_H_*/
