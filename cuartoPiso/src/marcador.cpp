
#include "marcador.h"


//constructor
Marcador::Marcador(Mapa* mapaActual)
{

  this->fila = 0;
  this->columna = 0;
  this->puntaje = 0;
  this->mapa = mapaActual;
  
 }


//Separado por metodos para mejor claridad

int Marcador::marcar(int filaJugada, int columnaJugada) 
{

  this->fila = filaJugada;
  this->columna = columnaJugada;

  if(!mapa->estaDestapadaLaCasilla(this->fila , this->columna)){
    
    realizarMarca();
  
  }
  
  return this->puntaje;
 
}

void Marcador::realizarMarca(){
  
  if(mapa->removerYDevolverSiHabiaMarca(this->fila , this->columna))
  {
    
    desmarcarCasilla();
    
  }
  else
  {
    marcarCasilla();
  }
  
  

}


void Marcador::desmarcarCasilla()
{
    
  if(!mapa->validarMina(this->fila , this->columna))
  {
    this->puntaje+=2;
  }
  else
  {
  
    this->puntaje-=2;
  
  }

  

}

void Marcador::marcarCasilla()
{
  
  mapa->colocarMarca(this->fila, this->columna);
  
  if(!mapa->validarMina(this->fila, this->columna))
  {
    this->puntaje--;
  }
  else
  {
    this->puntaje++;
  }

  
}
