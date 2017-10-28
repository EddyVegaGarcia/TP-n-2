#ifndef JUGADA_H_
#define JUGADA_H_

# include <iostream>
# include "destapador.h"
# include "marcador.h"

class Jugada{
	
	private:
		
		//atributos
		char opcion;
		int fila;
		int columna;
		int puntaje;
		Mapa* mapa;
		
	public:
		//metodos
		
		//pre: recibe como parametro un puntero al mapa del juego
		//post: crea una jugada que se realizara en el mapa 
		Jugada(Mapa* mapa);
		
		//pre: se pasa como parametro la opcion que el usuario ingreso, es decir una D si
		//quiere destapar una casilla, M si la quiere marcar o R si quiere retirarse.
		//post: queda la opcion de la jugada registrada con el dato recibido.
		void asignarOpcion(char opcionDeUsuario);
		
		//pre: se pasa por parametro la fila que el usuario ingreso, esta debe ser valida,
		// es decir dentro de las dimensiones especificadas a un comienzo del juego.
		//post: la fila queda registrada con el dato recibido.
		void asignarFila(int fila);
		
		//pre: se pasa por parametro la columna que el usuario ingreso, esta debe ser valida,
		// es decir dentro de las dimensiones especificadas a un comienzo del juego.
		//post: la columna queda registrada con el dato recibido.
		void asignarColumna(int columna);
	
		//pre: 
		//post: segun la opcion que se registro anteriormente se realizara la jugada, es
		//decir, se destapara la casilla, se marcara esta, o se retirara el jugador, se 
		//devolvera el puntaje ganado con la jugada hecha.
		int realizarJugada();
			
};
#endif
