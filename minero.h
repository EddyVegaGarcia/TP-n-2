#ifndef MINERO_H_
#define MINERO_H_

#include <stdlib.h>
#include <time.h>

class Minero{

private:

	int dimFila;
	int dimColumna;
	char dificultad;

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

	//pre:  --
	//post: siembra minas en el mapa de juego segun la dificultad
	void sembrarMinas(int mapa[][]);


};


#endif /* MINERO_H_ */
