typedef unsigned int uint;

class Mina{
private:
  uint fila;
  uint columna;
  
  /* Post: signa la fila de la mina.*/
  void asignarFila(uint fila);
  
  /* Post: signa la columna de la mina.*/
  void asignarColumna(uint columna);


public:
/*Pre: recibe fila y columna dentro del rango indicado por el jugador
* Post: crea un objeto mina, con la fila y columna recibidas. */
  Mina(uint fila, uint columna);
  
  /* Post: Crea un mina con fila y columna "0".*/
  Mina();
  
  /* Post: devuelve la fila de la mina.*/
  uint obtenerFila();
  
  /* Post: devuelve la columna de la mina.*/
  uint obtenerColumna();
  
 
  /* Pre: recibe fila y columna de un casillero. La posición pasada no corresponde a la posición de una mina.
  * Post: devuelve si la casilla pasada está junto a una mina. */
  bool estaJuntoAMina(uint fila, uint columna);
  
  /* Pre: recibe fila y columna de un casillero.
  * Post: devuelve si en la casilla con fila y columna pasados por parámetro hay o no una mina. */
  bool esMina(uint fila, uint columna);

};
