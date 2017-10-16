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

Casilla::Casilla(uint fila, uint columna){
  asignarFila(fila);
  asignarColumna(columna);
  
}
  
uint Casilla::obtenerFila(){
  return fila;
}
  
uint Casilla::obtenerColumna(){
  return columna;
}

char Casilla::obtenerValor(){
  return valor;
}
