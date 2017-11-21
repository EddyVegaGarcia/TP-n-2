#include "bandera.h"

void Bandera::asignarFila(uint fila){
  this->fila=fila;
}
void Bandera::asignarColumna(uint columna){
  this->columna=columna;
}

Bandera::Bandera(){
  asignarFila(0);
  asignarColumna(0);
  this->seDestapo=false;
}

Bandera::Bandera(uint fila, uint columna){
  asignarFila(fila);
  asignarColumna(columna);
  this->seDestapo=false;
}

uint Bandera::obtenerFila(){
  return fila;
}

uint Bandera::obtenerColumna(){
  return columna;
}
bool Bandera::seDestapoEnTablero(){
 
return this->seDestapo;
}
void Bandera::destaparEnTablero(){

this->seDestapo = true;
}
