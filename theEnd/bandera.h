#ifndef BANDERA_H_
#define BANDERA_H_

#include "constantes.h"

class Bandera {

	private:
	  uint fila;
	  uint columna;
	  bool seDestapo;

	public:
	  /* Pre: recibe fila y columna dentro del rango indicado por el usuario.
	  * Post: crea un objeto Bandera, con la fila y columna recibidas.*/
	  Bandera(uint fila, uint columna);

	  /* Post: crea un objeto bandera con fila y columna 0.*/
	  Bandera();

	  /* Post: devuelve la fila de la Bandera.*/
	  uint obtenerFila();

	  /* Post: devuelve la columna de la Bandera.*/
	  uint obtenerColumna();

	  /* Pre: recibe una fila dentro del rango válido.
	  * Post: asigna la fila pasada como parámetro a la bandera*/
	  void asignarFila(uint fila);

	  /* Pre: recibe una columna dentro del rango válido.
	  * Post: asigna la columna pasada como parámetro a la bandera.*/
	  void asignarColumna(uint columna);

	  /*pre:
	  * post: devuelve si la bandera ya se destapo en el tablero.
	  */
	  bool seDestapoEnTablero();

	  /*pre: la bandera no se destapo en tablero aun.
	  *post: quedara indicado que la bandera se destapo en tablero
	  */
	  void destaparEnTablero();

  
};

#endif /* BANDERA_H_ */
