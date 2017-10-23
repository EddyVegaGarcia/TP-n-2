#ifndef BANDERA_H_
#define BANDERA_H_

typedef unsigned int uint;

class bandera {

private:
  uint fila;
  uint columna;

public:
/*Pre: recibe fila y columna dentro del rango indicado por el jugador
* Post: crea un objeto bandera, con la fila y columna recibidas. */
  Bandera(uint fila, uint columna);

  /*Post: crea un objeto bandera con fila y columna 0.*/
  Bandera();

  /* Post: devuelve la fila*/
  uint obtenerFila();

  /* Post: devuelve la fila*/
  uint obtenerColumna();
  
  /* Post: asigna la fila pasada como parámetro a la bandera*/
  void asignarFila(uint fila);
  
  /* Post: asigna la columna pasada como parámetro a la bandera*/
  void asignarColumna(uint columna);
};

#endif /* BANDERA_H_ */
