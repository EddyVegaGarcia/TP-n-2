#ifndef JUGADA_H_
#define JUGADA_H_

include <iostream>
include "destapador.h"
include "marcador.h"

class jugada(){
	
	private:
		
		//atributos
		char opcion;
		int fila;
		int columna;
		int puntaje;
		
	public:

		//metodos
		
		//pre: se pasa como parametro la opcion que el usuario ingreso, es decir una D si
		//quiere destapar una casilla, M si la quiere marcar o R si quiere retirarse.
		//post: queda la opcion de la jugada registrada con el dato recibido.
		void asignarOpcion(char opcionDeUsuario);
		
		//pre: se pasa por parametro la fila y la columna que el usuario ingreso, esta debe ser valida,
		// es decir dentro de las dimensiones especificadas a un comienzo del juego.
		//post: la fila y la columna quedan registradas con los datos recibidos.
		jugada(int fila, int columna);
	
		//pre: 
		//post: segun la opcion que se registro anteriormente se realizara la jugada, es
		//decir, se destapara la casilla, se marcara esta, o se retirara el jugador, se 
		//devolvera el puntaje ganado con la jugada hecha.
		int realizarJugada();
		
		
		
}
#endif
