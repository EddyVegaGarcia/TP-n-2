# include "minero.h"



/*
 * dificultad considerada como Facil - Medio - Dificil por ahora
 * facil=   %20 del tablero son minas
 * medio=   %30 del tablero son minas
 * dificil= %40 del tablero son minas
 */

Minero::Minero(uint dimFilaRecibida, uint dimColumnaRecibida, char dificultadRecibida, Lista<Mina>* punteroAListaMinas){

	dimFila = dimFilaRecibida;
	dimColumna = dimColumnaRecibida;
	dificultad = dificultadRecibida;
	pMinas=punteroAListaMinas;

}

void Minero::sembrarMinas(){

	int totalCeldas = dimFila*dimColumna;
	int totalMinas;

	totalMinas = asignarNumeroMaximoMinas(totalCeldas);

	if (totalMinas == 0)
			totalMinas = 1;

    asignarMinasAleatorias(totalCeldas,totalMinas);
}

int Minero::asignarNumeroMaximoMinas(int totalCeldas){

	int maximoMinas;

	if (dificultad=='D'|| dificultad=='d')	maximoMinas = (totalCeldas*DIFICIL)/100;

	else if (dificultad=='M'||dificultad=='m') maximoMinas = (totalCeldas*MEDIO)/100;

	else  maximoMinas = (totalCeldas*FACIL)/100;

	return maximoMinas;
}

void Minero::asignarMinasAleatorias(int celdas,int minas){

	srand (time(NULL));

	int posVector;
	int tope = celdas;
	int aux;

	int* vectorEnteros = new int[celdas];
	for (int i=0;i<celdas;i++)
		vectorEnteros[i]=i+1; //el vector queda asignado con numeros del 1 al tope

	for (int i=0;i<minas;i++){

		posVector= rand() % tope;
		aux = vectorEnteros[posVector];

		asignarBomba(aux);


		vectorEnteros[posVector] = vectorEnteros[tope-1];
		vectorEnteros[tope-1] = aux;
		tope--;
	}
	delete []vectorEnteros;
}



void Minero::asignarBomba(int posicionEnUnaDimension){
	uint fila;
	uint columna;
	pasarDeUnaDimADos(posicionEnUnaDimension, fila, columna);
	
	Mina minaPorAgregar(fila, columna);
	this->pMinas->agregar(minaPorAgregar);
	
}

void Minero::pasarDeUnaDimADos(int numeroCasilla, uint& filaAObtener, uint& columnaAObtener){

	bool convertido = false;
	uint fila = 1;
	uint columna = numeroCasilla;

	while(!convertido){

		if(columna>this->dimColumna){
			fila++;
			columna = columna - this->dimFila;
		}
		else convertido = true;

	}
	filaAObtener = fila;
	columnaAObtener = columna;
}
