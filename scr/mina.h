typedef unsigned int uint;

class Mina{
private:
  uint fila;
  uint columna;
  
  void asignarFila(uint fila);
  void asignarColumna(uint columna);


public:
/*Pre: recibe fila y columna dentro del rango indicado por el jugador
* Post: crea un objeto mina, con la fila y columna recibidas. */
  Mina(uint fila, uint columna);  
  
  /* Post: devuelve la fila*/
  uint obtenerFila();
  
  /* Post: devuelve la fila*/
  uint obtenerColumna();
  
  // algún método para ver los alrededores, 'o algo así' ^_^
  
  bool estaJuntoAMina(uint uint fila, uint columna);

};
