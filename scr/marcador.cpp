

#include "marcador.h"

using namespace std;

//constructor
Marcador::Marcador(mapa* mapa)
{

  crearclases();
  filaJugada -> jugada.obtenerfilaJugada(); //Falta crear el obtener de Jugada
  columnaJugada -> jugada.obtenerColumnaJugada(); //Falta
  puntaje = 0;
  
 }
 
//Creo punteros a las clases (sugerencias)
void Marcador::crearclases()
{

  Jugada jugada;
  Mapa mapa;
  Tablero tablero;
  
}

//Separado por metodos para mejor claridad

/no es necesario la fila y columnas porque ya lo obtube em el contructor
int Marcador::marcar(uint fila, uint columna) 
{
  
  char bandera = B;
  
  if(!tablero.estaRevelado(this->filaJugada, this->columnaJugada))
  {
    tablero.asignarValorCasilla(this->filaJugada, this->columnaJugada, bandera);
    puntaje (....)
  }
  else(tablero.obtenerCasilla(this->filaJugada, this->columnaJugada) == bandera)
  {
    //constructor copia tablero
    tablero.tablero(this->filaJugada, this->columnaJugada);
    puntaje(....)
  }
   
}

int Destapar::obtenerPuntajePorMarcar()
{

  return puntaje;

}
