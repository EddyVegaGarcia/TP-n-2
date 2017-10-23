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

Casilla::Casilla(uint fila, uint columna, Mapa* mapa){
  asignarFila(fila);
  asignarColumna(columna);
  calcularValor(fila, columna, mapa);
}

Casilla::Casilla(){
  asignarFila(0);
  asignarColumna(0);
  asignarValor('0');
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

void Casilla::calcularValor(uint fila, uint columna){
   char valorObtenido;
   valorObtenido = mapa.calcularValorDeCasilla(fila, columna);
   asignarValor(valorObtenido);
}
void Casilla::asignarValor(char valorAsignar){
  this->valor=valorAsignar;
}
