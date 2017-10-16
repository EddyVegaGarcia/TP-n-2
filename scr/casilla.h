typedef unsigned int uint;

class Casilla{
private:
  uint fila;
  uint columna;
  char valor;
  
public:

 /*Pre: recibe fila y columna dentro del rango indicado por el jugador
* Post: crea un objeto casilla, con la fila y columna recibidas. */
  Casilla(uint fila, uint columna);
  
  /* Post: devuelve la fila*/
  uint obtenerFila();
  
  /* Post: devuelve la fila*/
  uint obtenerColumna();
  
  /* Post: devuelve el valor */
  char obtenerValor();

  void asignarFila(uint fila);
  void asignarColumna(uint columna);
  void asignarValor(char valor);

};
