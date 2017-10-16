tipedef unsigned int uint;


class Minas{
private:
  mina* minasAlmacenadas[];
public:

  //pre: recibe la cantidad de minas que se deben crear.
  //post: crea un vector de objetos tipo mina y se asigna un 
  //puntero a dicho vector.
  Minas(uint cantidadMinas);
  
  //pre: recibe la fila y columna de una posiccion valida dentro del 
  //campo de juego.
  //post: devuelve el valor al que corresponde la posicion que se paso 
  char calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla);
   
};
