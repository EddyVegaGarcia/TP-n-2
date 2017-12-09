
#ifndef LISTACIRCULARCURSOR_H_
#define LISTACIRCULARCURSOR_H_

#include "nodo.h"

template<class T> class ListaCircularCursor{

	private:
		Nodo<T>* cursor;
		Nodo<T>* cursor2;
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
		bool avanzarCursor();

		T obtenerCursor();
		//pre: debe haber al menos un elemento en la lista
		//post: deja el cursor apuntando al primer elemento
		void inicializarCursor2();

		//post: apunta el cursor al siguiente elemento
		//		en caso de no estar inicializado, lo inicializa.
		bool avanzarCursor2();

		T obtenerCursor2();
	
		bool estaVacia();

		unsigned int contarElementos();
	
		Nodo<T>* obtenerNodo(unsigned int posicion);

		/* Post: Libera los recursos asociados a la lista circular.*/
		~ListaCircularCursor();



};


template<class T> ListaCircularCursor<T>::ListaCircularCursor(){

	this->cursor = NULL;
	this->cursor2 = NULL;
	this->primero = NULL;
	this->tamanio = 0;
}


template<class T> void ListaCircularCursor<T>::insertar(T elementoNuevo){

	this->insertar(elementoNuevo, this->tamanio+1);
}

template<class T> void ListaCircularCursor<T>::insertar(T elementoNuevo, unsigned int posicion){

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elementoNuevo);

        if (posicion == 1) {

            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;

            //para que el ultimo apunte al nuevo primero
            Nodo<T>* ultimo = this->obtenerNodo(this->tamanio);
            ultimo->cambiarSiguiente(nuevo);

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);

        }

        this->tamanio++;
        this->inicializarCursor(); //retorna el cursor al principio de la lista

    }

}

template<class T> void ListaCircularCursor<T>::remover(unsigned int posicion){

	  if ((posicion > 0) && (posicion <= this->tamanio)) {

	        Nodo<T>* removido;
		if (posicion!=contarElementos()){
			if (posicion == 1) {

			    removido = this->primero;
			    this->primero = removido->obtenerSiguiente();

			    Nodo<T>* ultimo = obtenerNodo(this->tamanio);
			    ultimo->cambiarSiguiente(this->primero);

			} else {

			    Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
			    removido = anterior->obtenerSiguiente();
			    anterior->cambiarSiguiente(removido->obtenerSiguiente());
			}
		} else {
			removido=primero;
			primero=NULL;
		}

	        delete removido;
	        this->tamanio--;

	        this->inicializarCursor(); //retorna el cursor al principio de la lista
	}
}

template<class T> void ListaCircularCursor<T>::inicializarCursor(){

	this->cursor = NULL;
}

template<class T> bool ListaCircularCursor<T>::avanzarCursor(){

	if(this->cursor==NULL)
	{
		this->cursor=this->primero;
	}
	else
	{
		this->cursor=this->cursor->obtenerSiguiente();
	}
	return (this->cursor != NULL);
}

template<class T> T ListaCircularCursor<T>::obtenerCursor(){

	   T elemento;

	    if (this->cursor != NULL) {

	        elemento = this->cursor->obtenerDato();
	    }

return elemento;
}
template<class T> void ListaCircularCursor<T>::inicializarCursor2(){

	this->cursor2 = NULL;
}

template<class T> bool ListaCircularCursor<T>::avanzarCursor2(){

	if(this->cursor2==NULL)
	{
		this->cursor2=this->primero;
	}
	else
	{
		this->cursor2=this->cursor->obtenerSiguiente();
	}
	return (this->cursor2 != NULL);
}

template<class T> T ListaCircularCursor<T>::obtenerCursor2(){

	   T elemento;

	    if (this->cursor2 != NULL) {

	        elemento = this->cursor2->obtenerDato();
	    }

return elemento;
}
template<class T> bool ListaCircularCursor<T>::estaVacia(){

	return (this->tamanio == 0);
}

template<class T> Nodo<T>* ListaCircularCursor<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

template<class T> unsigned int ListaCircularCursor<T>::contarElementos()
{
	return this->tamanio;
}

template<class T> ListaCircularCursor<T>::~ListaCircularCursor(){
	while (!estaVacia())
		remover(contarElementos());
}


#endif /* LISTACIRCULARCURSOR_H_ */
