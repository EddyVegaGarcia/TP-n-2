


#include "listaCircularCursor.h"

template<class T> listaCircularCursor<T>::ListaCircularCursor(){

	this->cursor = NULL;
	this->primero = NULL;
	this->tamanio = 0;
}

template<class T> void listaCircularCursor<T>::insertar(T elementoNuevo){

	this->insertar(elemento, this->tamanio+1);
}

template<class T> void listaCircularCursor<T>::insertar(T elementoNuevo, unsigned int posicion){

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;

            //para que el ultimo apunte al nuevo primero
            Nodo<T>* ultimo = this->obtenerNodo(this->tamanio);
            ultimo->cambiarSiguiente(nuevo)

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);

        }

        this->tamanio++;
        this->inicializarCursor(); //retorna el cursor al principio de la lista

    }

}

template<class T> void listaCircularCursor<T>::remover(unsigned int posicion){

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

	        this->iniciarCursor(); //retorna el cursor al principio de la lista
	}
}

template<class T> void listaCircularCursor<T>::inicializarCursor(){

	this->cursor = NULL;
}

template<class T> void listaCircularCursor<T>::avanzarCursor(){

	  if (this->cursor == NULL) {

	        this->cursor = this->primero;

	    } else {

	        this->cursor = this->cursor->obtenerSiguiente();
	}
}

template<class T> T listaCircularCursor<T>::obtenerCursor(){

	   T elemento;

	    if (this->cursor != NULL) {

	        elemento = this->cursor->obtenerDato();
	    }

return elemento;
}

template<class T> void listaCircularCursor<T>::estaVacia(){

	return (this->tamanio == 0);
}

template<class T> listaCircularCursor<T>* listaCircularCursor<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}


template<class T> void listaCircularCursor<T>::~ListaCircularCursor(){
	while (!estaVacia())
		remover(contarElementos);
}
