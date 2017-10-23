


#ifndef MINERO_H_
#define MINERO_H_

#include <stdlib.h>
#include <time.h>

class Minero{

private:

	int dimFila;
	int dimColumna;
	char dificultad;
	Mina* punteroAMinas;
	Lista<Mina>* pMinas;

	//pre:  --
	//post: --
	int asignarNumeroMaximoMinas(int totalCeldas);

	//pre:  --
	//post: crea las celdas minadas en el mapa
	void asignarMinasAleatorias(int mapa[][],int celdas,int minas);

	//pre:  0 > posBomba > celdas totales
	//post: agrega una mina a la lista de minas *pMinas.
	void asignarBomba(int posBomba);
public:

	//constructor default
	Minero();

	//constructor con parámetros
	Minero(int filaRecibida, int columnaRecibida, char dificultadRecibida);

	//pre:  --
	//post: siembra minas en el mapa de juego segun la dificultad
	Mina* sembrarMinas(int mapa[][]);
	
	//pre: recibe la cantidad de minas qu ese deben crear
	//post: crea un vector de mminas con la cantidad indicada y devuelve
	//un puntero a este vector
	// este sobra. // debug
        Mina* Minero::crearVectorMinasVacias(uint cantidadMinas);
	
	//pre:recibe como parametro el numero de la casilla que quiere transformar, 
	// y una referencia a la dim y la col que va a cambiar.
	//post: calcula a que fila y columna correspondiente a el numero que se recibio y 
	//modifica los valores pasados por referencia con estos.
	void pasarDeUnaDimADos(int numeroCasilla, int& FilaAObtener, int& colAObtener);
};


#endif /* MINERO_H_ */
