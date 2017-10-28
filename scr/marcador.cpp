

#include "marcador.h"
#include "constante.h"

using namespace std;

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
  int puntaje = 0;
  this->fila = filaJugada;
  this->columna = columnaJugada;

  if(!mapa->estaDestapadaLaCasilla(this->fila , this->columna)){
    
    puntaje = realizarMarca();
  
  }
  
  return puntaje;
 
}

int Marcador::realizarMarca(){
  
  if(mapa->validarMarca(this->fila , this->columna))
  {
    
    this->puntaje = desmarcarCasilla();
    
  }
  else
  {
     this->puntaje = marcarCasilla();
  }
  
  
  return puntaje;
}


int Marcador::desmarcarCasilla()
{
 
  mapa->removerMarca(this->fila , this->columna);
    
  if(!mapa->validarMina(this->fila , this->columna)
  {
    puntaje+=2;
  }
  else
  {
  
    puntaje-=2;
  
  }

  
  return puntaje;
}

int Marcador::marcarCasilla()
{
  
  mapa->colocarMarca(this->fila, this->columna);
  
  if(!mapa->validarMina(this->fila, this->columna)
  {
    puntaje--;
  }
  else
  {
    puntaje++;
  }
  
  return puntaje;
  
}
