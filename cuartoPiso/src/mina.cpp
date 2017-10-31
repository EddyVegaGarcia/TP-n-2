# include "mina.h"

void Mina::asignarFila(uint fila){
  this->fila=fila;
}
void Mina::asignarColumna(uint columna){
  this->columna=columna;
}

Mina::Mina(uint fila, uint columna){
  asignarFila(fila);
  asignarColumna(columna);
}

Mina::Mina(){
  asignarFila(0);
  asignarColumna(0);
}

uint Mina::obtenerFila(){
  return this->fila;
}

uint Mina::obtenerColumna(){
  return this->columna;
}

bool Mina::estaJuntoAMina(uint filaAComparar, uint columnaAComparar){

  bool estaAlrededor=false;

  for(uint i=fila-1; i<fila+2; i++){

    for(uint j=columna-1;j<columna+2;j++){

      if (i==filaAComparar && j==columnaAComparar)
        estaAlrededor=true;
    }
  }

  return estaAlrededor;
}

bool Mina::esMina(uint filaAComparar, uint columnaAComparar){
  bool hayMina=false;
  if (this->fila==filaAComparar && this->columna==columnaAComparar)
    hayMina=true;
  return hayMina;
}

