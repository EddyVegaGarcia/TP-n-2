#ifndef BANDERA_H_
#define BANDERA_H_

typedef unsigned int uint;

class Bandera {

private:
  uint fila;
  uint columna;

  void asignarFila(uint fila);
  void asignarColumna(uint columna);


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

};

#endif /* BANDERA_H_ */
