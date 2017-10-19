

#include "marcador.h"

using namespace std;

//constructor
Marcador::Marcador(mapa* mapa)
{

  filaJugada = 0;
  columnaJugada = 0;
  puntaje = 0;
  this->mapa = mapa;
  
 }


//Separado por metodos para mejor claridad

int Marcador::marcar(int filaJugada, int columnaJugada) 
{
  
  char bandera = 'B';
  char vacio = ' ';
  this->fila = filaJugada;
  this->columna = columnaJugada;
  
  if(!tablero.estaRevelado(this->filaJugada, this->columnaJugada) && !mapa.validarMina(this->filaJugada, this->columnaJugada))
  {
    
    puntaje++;
    
  }
  else 
  {
    
    puntaje--;
    
  } 
  tablero.asignarValorCasilla(this->filaJugada, this->columnaJugada, bandera);
  
  
  if((tablero.obtenerCasilla(this->filaJugada, this->columnaJugada) == bandera) && !mapa.validarMina(this->filaJugada, this->columnaJugada))
  {
   
    tablero.asignarValorCasilla(this->filaJugada, this->columnaJugada, vacio);
    puntaje+=2;
    
  }
  else
  {
    tablero.asignarValorCasilla(this->filaJugada, this->columnaJugada, vacio);
    puntaje-=2;
    
  } 
   
}

int Destapar::obtenerPuntajePorMarcar()
{

  return puntaje;

}
