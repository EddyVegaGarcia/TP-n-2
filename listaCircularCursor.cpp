


#include "listaCircularCursor.h"

template<class T> listaCircularCursor::ListaCircularCursor(){

	this->cursor = NULL;
	this->primero = NULL;
	this->tamanio = 0;
}

template<class T> listaCircularCursor::insertar(T elementoNuevo){

	this->insertar(elemento, this->tamanio+1);
}

template<class T> listaCircularCursor::insertar(T elementoNuevo, unsigned int posicion){

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

template<class T> void listaCircularCursor::remover(unsigned int posicion){

	  if ((posicion > 0) && (posicion <= this->tamanio)) {

	        Nodo<T>* removido;

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

	        delete removido;
	        this->tamanio--;

	        this->iniciarCursor(); //retorna el cursor al principio de la lista
	}
}

template<class T> void listaCircularCursor::inicializarCursor(){

	this->cursor = NULL;
}

template<class T> void listaCircularCursor::avanzarCursor(){

	  if (this->cursor == NULL) {

	        this->cursor = this->primero;

	    } else {

	        this->cursor = this->cursor->obtenerSiguiente();
	}
}

template<class T> void listaCircularCursor::obtenerCursor(){

	   T elemento;

	    if (this->cursor != NULL) {

	        elemento = this->cursor->obtenerDato();
	    }

return elemento;
}

template<class T> void listaCircularCursor::estaVacia(){

	return (this->tamanio == 0);
}


