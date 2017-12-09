#ifndef MARCADOR_H_
#define MARCADOR_H_

# include "constantes.h"
# include "mapa.h"

class Marcador{
	
	private:
		int puntaje;
		int fila;
		int columna;
	    Mapa* mapa;
	
	public:		
		/* Pre: Recibe un puntero al mapa en el cual va a marcar.
		 * Post: Crea un Marcador, con puntaje 0.*/
		Marcador(Mapa* mapaActual);
		
		/* Pre: Recibe "filaJugada" y "columnaJugada" que indican la ubicación de una casilla.
		 * Post: Se establece la casilla sobre la cual el Marcador va a operar.
		 *	La casilla se marca si no estaba marcada y se desmarca si ya estaba marcada.
		 * 	Devuelve el puntaje correspondiente, que depende de la presencia o no de una mina
		 *	en la casilla y de la operación que se lleve adelante (marcar o desmarcar).*/
		int marcar(int filaJugada, int columnaJugada);
			
	private:
	
		/* Post: La casilla se marca si no estaba marcada y se desmarca si ya estaba marcada.
		 *
		 */
		void realizarMarca();
		
		/* Post: Marca la casilla. Modifica el puntaje correspondiente en función de la presencia o no
		 *	de una mina en la casilla a marcar (es positivo si en la casilla hay una mina,
		 *	y negativo en caso contrario).*/
		void marcarCasilla();
		
		/* Post: Desmarca la casilla. Modifica el puntaje correspondiente en función de la presencia o no
		 *	de una mina en la casilla a desmarcar (es negativo si en la casilla hay una mina,
		 *	y positivo en caso contrario).*/
		void desmarcarCasilla();
		
		
};

#endif /*MARCADOR_H_*/
