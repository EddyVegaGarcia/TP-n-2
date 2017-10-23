#include "Bandera.h"

void Bandera::asignarFila(uint fila){
  this->fila=fila;
}
void Bandera::asignarColumna(uint columna){
  this->columna=columna;
}

Bandera::Bandera(){
  asignarFila(0);
  asignarColumna(0);
}

Bandera::Bandera(uint fila, uint columna){
  asignarFila(fila);
  asignarColumna(columna);
}

uint Bandera::obtenerFila(){
  return fila;
}

uint Bandera::obtenerColumna(){
  return columna;
}
