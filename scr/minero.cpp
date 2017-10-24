
typedef unsigned int uint;

#include "minero.h"
#include "constantes.h"
/**
 * dificultad considerada como Facil - Medio - Dificil por ahora
 * facil=   %20 del tablero son minas
 * medio=   %30 del tablero son minas
 * dificil= %40 del tablero son minas
 * en el main se deberían agregar constantes para facilitar la modificacion de las dificultades
 */



void Minero::Minero(){

	//sin parámetros toma como default estas opciones

	dimFila=10;
	dimColumna=10;
	dificultad='F';
}

void Minero::Minero(int dimFilaRecibida, int dimColumnaRecibida, char dificultadRecibida, Lista<Mina>* punteroAListaMinas){

	dimFila = dimFilaRecibida;
	dimColumna = dimColumnaRecibida;
	dificultad = dificultadRecibida;
	pMinas=punteroAListaMinas;

}

void Minero::sembrarMinas(){

	int totalCeldas = dimFila*dimColumna;
	int totalMinas;
		
	totalMinas = asignarNumeroMaximoMinas(totalCeldas);
        asignarMinasAleatorias(totalCeldas,totalMinas);
}

int Minero::asignarNumeroMaximoMinas(int totalCeldas){

	int maximoMinas;

	if (dificultad=='F')		 maximoMinas = (totalCeldas*facil)/100;
	else if (dificultad=='M') maximoMinas = (totalCeldas*medio)/100;
	else 					 maximoMinas = (totalCeldas*dificil)/100;

	return maximoMinas;
}

void Minero::asignarMinasAleatorias(int celdas,int minas){


	srand (time(NULL)); //la semilla deberia ir en el main CREO

	int posVector;
	int tope = celdas;
	int aux;

	vectorEnteros = new int[celdas];
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
	delete []vectorEnteros;
}



void Minero::asignarBomba(int posicionEnUnaDimension){
	int fila;
	int columna;
	pasarDeUnaDimADos(posicionEnUnaDimension, fila, columna);
	
	Mina minaPorAgregar(fila, columna);
	this->pMinas->agregar(minaPorAgregar);
	
}

void pasarDeUnaDimADos(int numeroCasilla, int& filaAObtener, int& columnaAObtener){
        filaAObtener = (numeroCasilla/this->dimColumna) + 1 ;
	columnaAObtener = this->dimColumna (2- filaAObtener);
}



