

#include "destapador.h"

using namespace std;

//constructor
Destapador::Destapador (mapa* matrizMapa, tablero* matrizTablero)
{

  this->mapa = matrizMapa;
  this->tablero = matrizTablero;
  this->fila = 0
  this->columna = 0
  this->puntaje = 0;
  
  
}

//Separado por metodos para mejor claridad


void Destapador::destapar(int filaJugada, int columnaJugada) 
{
  
  if(mapa.validarVacio(this->filaJugada, this->columnaJugada))
    destaparPandemia();
  else  
    destaparCasilla();
  
}

void Destapar::destaparPandemia()
{
  //recursivo mati ayuda XD
}

void Destapar::destaparCasilla()
{

  //creo una variable para pasarlo por ṕarametro(no se enviarlo de frente)
  char valorCasilla-> mapa.obtenerCasilla(this->filaJugada, this->columnaJugada);
  tablero.asignarValorCasilla(this->filaJugada, this->columnaJugada, detectorMinas);
  
  asignarPuntaje();

}


//Si es bomba o si es enumerada
void Destapar::asignarPuntaje()
{

  if(!mapa.validarMina(this->filaJugada, this->columnaJugada))
    puntaje++; //no lo se.
  else
    puntaje...

}

int Destapar::obtenerPuntajePorRevelar()
{

  return puntaje;

}

void epidemia(char tablaMinada[][ancho],char tablaBloqueada[][ancho],int fila, int columna,int &contadorCeldas){
	//si hay un cero, desbloquea los alrededores hasta encontrarse con un numero distinto de cero (recursiva)
  
  //tablaMinada es la matriz completa y tablaBloqueada es la matriz que interactua con el usuario, la funcion
  //recibe ambas y luego una posicion representada por Fila Columna, chequea los alrededores de fila columna
  //contadorCeldas no se usa en este trabajo CREO.

	if(tablaBloqueada[fila-1][columna-1]=='*' || tablaBloqueada[fila-1][columna-1]=='B'){
		tablaBloqueada[fila-1][columna-1]=tablaMinada[fila-1][columna-1];
		--contadorCeldas;

		if(tablaMinada[fila-1][columna-1]=='0'){

			if(fila-1 !=0 &&tablaMinada[fila-2][columna-1]!='x' && tablaBloqueada[fila-2][columna-1]=='*')
				expandir(tablaMinada,tablaBloqueada,fila-1,columna,contadorCeldas);

			if(columna-1 !=0 &&tablaMinada[fila-1][columna-2]!='x' && tablaBloqueada[fila-1][columna-2]=='*')
				expandir(tablaMinada,tablaBloqueada,fila,columna-1,contadorCeldas);

			if(columna !=ancho && tablaMinada[fila-1][columna]!='x' && tablaBloqueada[fila-1][columna]=='*')
				expandir(tablaMinada,tablaBloqueada,fila,columna+1,contadorCeldas);

			if(fila !=largo && tablaMinada[fila][columna-1]!='x' && tablaBloqueada[fila][columna-1]=='*')
				expandir(tablaMinada,tablaBloqueada,fila+1,columna,contadorCeldas);

		}
	}
}
