
#include "listaCircularCursor.h"

template<class T> ListaCircularCursor<T>::ListaCircularCursor(){

	this->cursor = NULL;
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

template<class T> void ListaCircularCursor<T>::avanzarCursor(){

	  if (this->cursor == NULL) {

	        this->cursor = this->primero;

	    } else {

	        this->cursor = this->cursor->obtenerSiguiente();
	}
}

template<class T> T ListaCircularCursor<T>::obtenerCursor(){

	   T elemento;

	    if (this->cursor != NULL) {

	        elemento = this->cursor->obtenerDato();
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
