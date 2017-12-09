#ifndef MINERO_H_
#define MINERO_H_

#include <stdlib.h>
#include <ctime>
# include "mina.h"
#include "constantes.h"
#include "lista.h"

class Minero{

	private:

		uint dimFila;
		uint dimColumna;
		char dificultad;
		Lista<Mina>* pMinas;



	public:



		//pre: recibe una cantidad de filas, columnas, la dificultad para crear el minero, y un
		// puntero a una lista de minas onde estas se crearan.
		//post: crea un minero con estos valores
		Minero(uint filaRecibida, uint columnaRecibida, char dificultadRecibida,  Lista<Mina>* punteroAListaMinas);

		//pre:
		//post: lleno la lista de minas con la catidad correspondient de minas en ubicaciones aleatorias
		void sembrarMinas();

	private:
		//pre: recibe el total de celdas que tendra el juego, es decir dim filas * dim columnas
		//post: devuelve el numero correspondiente de minas segun el total de celdas y la dificultad del minero.
		int asignarNumeroMaximoMinas(int totalCeldas);

		//pre: recibe por parametro el total de celdas que tendra el juego y la cantidad de
		//minas correspondiente
		//post: llena la lista de minas con la cantidad de minas necesaria en ubicaciones aleatorias
		void asignarMinasAleatorias(int celdas,int minas);
	
		//pre:  recibe la posicion de la bomba, esta debe ser valida, es decir un valor entre cero
		//y a cantidad total de casillas
		//post: agrega una mina a la lista de minas *pMinas en la ubicacion correspondiente(fila, columna)
		void asignarBomba(int posicionEnUnaDimension);

		//pre:recibe como parametro el numero de la casilla que quiere transformar,
		// y una referencia a la fila y la columna que va a modificar.
		//post: calcula a que fila y columna correspondiente a el numero que se recibio y
		//modifica los valores pasados por referencia con estos.
		void pasarDeUnaDimADos(int numeroCasilla, uint& filaAObtener, uint& columnaAObtener);
	
	
};

#endif /* MINERO_H_ */
