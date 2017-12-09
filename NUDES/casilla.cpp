# include "casilla.h"

void Casilla::asignarFila(uint fila){
  this->fila=fila;
}
void Casilla::asignarColumna(uint columna){
  this->columna=columna;
}
void Casilla::asignarValor(char valor){
  this->valor=valor;
}

Casilla::Casilla(uint fila, uint columna, char valor){
  asignarFila(fila);
  asignarColumna(columna);
  asignarValor(valor);
  this->seDestapo = false;
}

Casilla::Casilla(){
  asignarFila(0);
  asignarColumna(0);
  asignarValor('0');
}
  
uint Casilla::obtenerFila(){
  return this->fila;
}
  
uint Casilla::obtenerColumna(){
  return this->columna;
}

char Casilla::obtenerValor(){
  return this->valor;
}
bool Casilla::seDestapoEnTablero(){
	return this->seDestapo;
}
void Casilla::destaparEnTablero(){
	this->seDestapo = true;
}
