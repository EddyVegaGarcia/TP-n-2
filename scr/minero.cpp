


#include "minero.h"

/**
 * dificultad considerada como Facil - Medio - Dificil por ahora
 * facil=   %20 del tablero son minas
 * medio=   %30 del tablero son minas
 * dificil= %40 del tablero son minas
 * en el main se deberían agregar constantes para facilitar la modificacion de las dificultades
 */

const unsigned int facil=20;
const unsigned int medio=30;
const unsigned int dificil=40;

void Minero::Minero(){

	//sin parámetros toma como default estas opciones

	dimFila=10;
	dimColumna=10;
	dificultad='F';
}

void Minero::Minero(int filaRecibida, int columnaRecibida, char dificultadRecibida){

	dimFila = filaRecibida;
	dimColumna = columnaRecibida;
	dificultad = dificultadRecibida;
}

void Minero::sembrarMinas(int mapa[][]){

	int totalCeldas = dimFila*dimColumna;
	int totalMinas;

	totalMinas = asignarNumeroMaximoMinas(totalCeldas);
	asignarMinasAleatorias(mapa,totalCeldas,totalMinas);

}

int Minero::asignarNumeroMaximoMinas(int totalCeldas){

	int maximoMinas;

	if (dificultad=='F')		 maximoMinas = (totalCeldas*100)/facil;
	else if (dificultad=='M') maximoMinas = (totalCeldas*100)/medio;
	else 					 maximoMinas = (totalCeldas*100)/dificil;

	return maximoMinas;
}

void Minero::asignarMinasAleatorias(int mapa[][],int celdas,int minas){


	srand (time(NULL)); //la semilla deberia ir en el main CREO

	int posVector;
	int tope = celdas;
	int aux;

	int vectorEnteros;
	for (int i=0;i<celdas;i++)
		vectorEnteros[i]=i+1; //el vector queda asignado con numeros del 1 al tope

	for (int i=0;i<minas;i++){

		posVector= rand() % tope;
		aux = vectorEnteros[posVector];

		asignarBomba(aux);

		vectorEnteros[posVector] = vectorEnteros[tope];
		vectorEnteros[tope] = aux;
		tope--;
	}
}

