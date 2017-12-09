#ifndef PSEUDOGRAFO_H_
#define PSEUDOGRAFO_H_

#include "nodoGrafo.h"

template <class T> class PseudoGrafo{

private:
	NodoGrafo<T>* primero;
	NodoGrafo<T>* actual;

public:
	PseudoGrafo();
	void insertar(T dato);

	NodoGrafo<T>* obtenerActual();
	bool estaVacia();
	bool retrocederCursor();
	T obtenerDatoActual();
	NodoGrafo<T>* obtenerPrimero();
	bool avanzarCursor();
	bool avanzarCursorAParalela();

	void borrarNodo(NodoGrafo<T>* aBorrar);
	~PseudoGrafo();

};

template <class T>
PseudoGrafo<T>::PseudoGrafo(){

		this->primero=NULL;
		this->actual=NULL;
}

template <class T>
void PseudoGrafo<T>::insertar(T dato){
	/*
	 * ingresa un dato como siguiente al actual, si el siguiente tiene paralelos, lo ingresa como
	 * el ultimo de los paralelos, luego mueve el cursor actual a la nueva posicion.
	 */


	NodoGrafo<T>* nuevo = new NodoGrafo<T>(dato);


	if(primero == NULL){ //si la lista esta vacia

		primero = nuevo;

	}else if(actual->obtenerSiguiente() == NULL){ //si el actual no tiene siguiente
	      actual->cambiarSiguiente(nuevo);
	      nuevo->cambiarAnterior(actual);
	}else{									//si el actual tiene siguiente, agregarlo como paralelo
		  NodoGrafo<T>* siguiente = actual ->obtenerSiguiente();
		  NodoGrafo<T>* paraleloSiguiente;

		  if(siguiente->tieneParalelo()){

			  paraleloSiguiente = siguiente->obtenerParalelo();

			  while(paraleloSiguiente->tieneParalelo()) //obtener el ultimo de los paralelos
				  paraleloSiguiente=paraleloSiguiente->obtenerParalelo();

			  paraleloSiguiente->cambiarParalelo(nuevo);
			  nuevo->cambiarAnterior(actual);
		  }
		  else{
			  siguiente->cambiarParalelo(nuevo);
			  nuevo->cambiarAnterior(actual);
		  }

	}
	actual = nuevo;

}
template <class T>
NodoGrafo<T>* PseudoGrafo<T>::obtenerActual(){

	return (this->actual);
}

template <class T>
T PseudoGrafo<T>::obtenerDatoActual(){

	T dato = actual->obtenerDato();
	return dato;

}

template <class T>
bool PseudoGrafo<T>::estaVacia(){

	return (this->primero == NULL);
}

template <class T>
bool PseudoGrafo<T>::retrocederCursor(){

	if (primero!=NULL){
		if(actual!=primero)
			this->actual = this->actual->obtenerAnterior();
		else this->actual = NULL;
	}

	return (actual != NULL);
}

template <class T>
NodoGrafo<T>* PseudoGrafo<T>::obtenerPrimero(){

	return this->primero;
}

template <class T>
bool PseudoGrafo<T>::avanzarCursor(){
//si tiene siguiente, lo avanza y devuelve true
	bool tieneSiguiente = false;

	if(this->actual->tieneSiguiente()){
		this->actual= this->actual->obtenerSiguiente();
		tieneSiguiente = true;
	}
return tieneSiguiente;
}

template <class T>
bool PseudoGrafo<T>::avanzarCursorAParalela(){
//si tiene paralelo, lo avanza y devuelve true
	bool tieneParalelo = false;

	if(this->actual->tieneParalelo()){
		this->actual= this->actual->obtenerParalelo();
		tieneParalelo = true;
	}
return tieneParalelo;

}

template <class T>
PseudoGrafo<T>::~PseudoGrafo(){

	if(actual != NULL){

		NodoGrafo<T>* ultimo = primero;
		NodoGrafo<T>* anterior = NULL;

		while(ultimo->obtenerSiguiente() != NULL)
			ultimo = ultimo->obtenerSiguiente();

		while(primero != ultimo){

			anterior = ultimo->obtenerAnterior();
			borrarNodo(ultimo);
			ultimo = anterior;
		}
		delete ultimo;
	}
}

template <class T>
void PseudoGrafo<T>::borrarNodo(NodoGrafo<T>* aBorrar){

	if(aBorrar->tieneSiguiente()){
		borrarNodo(aBorrar->obtenerSiguiente());
	}
	if(aBorrar->tieneParalelo()){
		borrarNodo(aBorrar->obtenerParalelo());
	}

	NodoGrafo<T>* anterior = aBorrar->obtenerAnterior();
	anterior->cambiarSiguiente(NULL);
	anterior->cambiarParalelo(NULL);
	delete aBorrar;

}

#endif /* PSEUDOGRAFO_H_ */
