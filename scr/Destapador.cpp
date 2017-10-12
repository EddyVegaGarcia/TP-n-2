#include <iostream>

#include "Destapador.h"

using namespace std;

//constructor
Destapador::Destapador ()
{

  crearclases();
  filaJugada -> jugada.obtenerfilaJugada(); //Falta crear el obtener de Jugada
  columnaJugada -> jugada.obtenerColumnaJugada(); //Falta
  puntaje = 0;
  
  
}

//Creo punteros a las clases (sugerencias)
void Destapador::crearclases()
{

  Jugada jugada;
  Mapa mapa;
  Tablero tablero;
  
}

//Separado por metodos para mejor claridad

//no es necesario la fila y columnas porque ya lo obtube em el contructor
void Destapador::destapar() 
{
  
  if(mapa.validarVacio(this->filaJugada, this->columnaJugada))
    destaparPandemia();
  else  
    destaparCasilla;
  
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
