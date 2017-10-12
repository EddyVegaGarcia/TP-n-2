#ifndef JUGADA_H_
#define JUGADA_H_

include <iostream>
include "matriz.h"


class mina(){
	private: 
	
	//atributos
	int fila;
	int columna;
	matriz* tablero;
	//metodos
	
	public:
	//pre: recibe como parametro primero el numero de fila y luego
	//el numero de columna correspondiente a su ubicacion
	//post: quedan registrados los datos de fila y columna respectivos
	//en los atributos de la mina.
	mina(int fila, int columna, matriz* tablero);
	
	//pre:
	//post: modifico el tablero ubicando la mina en la ubicacion respectiva y 
	//elimina al jugador del juego 
	void explota();
	
	
}

#endif
