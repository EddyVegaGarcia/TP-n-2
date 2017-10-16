


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

	//pre:  --
	//post: --
	int asignarNumeroMaximoMinas(int totalCeldas);

	//pre:  --
	//post: crea las celdas minadas en el mapa
	void asignarMinasAleatorias(int mapa[][],int celdas,int minas);

	//pre:  0 > posBomba > celdas totales
	//post: una bomba queda plantada en el mapa
	void asignarBomba(int posBomba);  //lo dejo sin hacer hasta saber como vamos a realizar el mapa y la matriz

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
        Mina* Minero::crearVectorMinasVacias(uint cantidadMinas);
	 //pre:recibe como parametro el numero de la casilla que quiere transformar, 
	// y una referencia a la dim y la col que va a cambiar.
	//post: calcula a que fila y columna correspondiente a el numero que se recibio y 
	//modifica los valores pasados por referencia con estos.
	void pasarDeUnaDimADos(int numeroCasilla, int& FilaAObtener, int& colAObtener);
};


#endif /* MINERO_H_ */
