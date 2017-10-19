

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
