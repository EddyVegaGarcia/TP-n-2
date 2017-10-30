#ifndef BUSCADOR_H_
#define BUSCADOR_H_

typedef unsigned int uint;

# include "lista.h"

template<class T> class Buscador {

private:
	Lista<T>* pLista;


public:
	/* Un Buscador es el encargado de buscar un elemento en listas de Casillas, de Banderas, y
	 * de Minas.
	 * Pre: Recibe un puntero a la lista en la que se desea buscar un objeto de una de las
	 * 		clases especificadas (Bandera, Casilla, o Mina).
	 * Post: Crea un Buscador, quedando asignada la lista en la que se buscará.*/
	Buscador(Lista<T>* pListaABuscar);

	/* Pre: Recibe la fila y columna del objeto a buscar en la lista establecida en el constructor, y
	 * 		una posicionEncontrada en la que se almacenará la posición en la que se encontró el objeto
	 * 		si el mismo se encontró, o un número 0 si no se ha encontrado en la lista.*/
	bool buscar(uint filaBuscada, uint columnaBuscada, uint &posicionEncontrada=0);
};


#endif /* BUSCADOR_H_ */
