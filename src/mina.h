#ifndef MINA_H_
#define MINA_H_

#include "constantes.h"

class Mina{
	private:
	  uint fila;
	  uint columna;



	public:
	 /* Pre: Recibe fila y columna dentro del rango indicado por el usuario.
	  * Post: Crea un objeto Casilla con la fila y columna recibidas.*/
	  Mina(uint fila, uint columna);

	  /* Post: Crea un mina con fila y columna 0.*/
	  Mina();

	  /* Post: Devuelve la fila de la Mina.*/
	  uint obtenerFila();

	  /* Post: Devuelve la columna de la Mina.*/
	  uint obtenerColumna();


	  /* Pre: Recibe fila y columna de un casillero. La posición pasada no corresponde a la posición de una mina.
	  * Post: Devuelve si la casilla pasada está junto a una mina.*/
	  bool estaJuntoAMina(uint fila, uint columna);

	  /* Pre: Recibe fila y columna de un casillero.
	  * Post: Devuelve si en la casilla con fila y columna pasados por parámetro hay o no una mina. */
	  bool esMina(uint fila, uint columna);

	private:
		/* Pre: Recibe una fila dentro del rango válido.
		* Post: Asigna la fila pasada como parámetro a la Mina.*/
		void asignarFila(uint fila);

		/* Pre: Recibe una columna dentro del rango válido.
		* Post: Asigna la columna pasada como parámetro a la Mina.*/
		void asignarColumna(uint columna);

};

#endif /*MINA_H_*/
