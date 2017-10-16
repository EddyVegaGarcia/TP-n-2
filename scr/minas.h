tipedef unsigned int uint;


class Minas{
private:
  mina* minasAlmacenadas[];
public:

  //pre: recibe la dimension de las filas, la dimension de las columnas y 
  //la dificultad como parametro.
  //post: crea un vector de objetos tipo mina y se asigna un 
  //puntero a dicho vector.
  Minas(uint dimFilas, uint dimcolumnas, uint dificultad);
  
  //pre: recibe la fila y columna de una posiccion valida dentro del 
  //campo de juego.
  //post: devuelve el valor al que corresponde la posicion que se paso 
  char calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla);
   
};
