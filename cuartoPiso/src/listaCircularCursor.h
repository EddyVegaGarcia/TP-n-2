
#ifndef LISTACIRCULARCURSOR_H_
#define LISTACIRCULARCURSOR_H_

#include "nodo.h"

template<class T> class ListaCircularCursor{

private:
	Nodo<T>* cursor;
	Nodo<T>* primero;
	unsigned int tamanio;

public:
	//constructor, se crea vacia
	ListaCircularCursor();

	//pre:
	//post: inserta un elemento en la posicion (this->tamanio)
	void insertar(T elementoNuevo);

	//pre:
	//post: si la lista no tiene nodos, se inserta como primer elemento,
	//		si tiene mas de uno, se luego del ultimo ingresado.
	void insertar(T elementoNuevo, unsigned int posicion);


	//pre: tiene que existir un elemento en la lista
	//	   posicion <= this-> tamanio
	//post: remueve el elemento de la lista
	void remover(unsigned int posicion);

	//pre: debe haber al menos un elemento en la lista
	//post: deja el cursor apuntando al primer elemento
	void inicializarCursor();

	//post: apunta el cursor al siguiente elemento
	//		en caso de no estar inicializado, lo inicializa.
	void avanzarCursor();

	/* Pre: Se ha llamado a avanzarCursor() al menos una vez.
	 * Post: Devuelve el elemento del nodo al que apunta el cursor.*/
	T obtenerCursor();

	/* Post: Devuelve un booleano que indica si la lista está vacía o no.*/
	bool estaVacia();
	
	/* Post: Devuelve la cantidad de elementos de la lista.*/
	unsigned int contarElementos();
	
	/* Pre: Recibe una posición, 1<=posicion<contarElementos()
	 * Post: Devuelve el nodo que se encuentra en la posición "posicion" de la lista.*/
  	Nodo<T>* obtenerNodo(unsigned int posicion);	
	
	/* Post: Libera los recursos asociados a la lista circular.*/
	~ListaCircularCursor();
  	


};


#endif /* LISTACIRCULARCURSOR_H_ */
