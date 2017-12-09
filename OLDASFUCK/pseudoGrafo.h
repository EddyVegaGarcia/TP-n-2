


#ifndef PSEUDOGRAFO_H_
#define PSEUDOGRAFO_H_

#include "nodoGrafo.h"
#include "jugada.h"

template <class T> class PseudoGrafo{

private:
	NodoGrafo<T>* primero;
	NodoGrafo<T>* actual;

public:
	PseudoGrafo();
	/*
	 * ingresa un dato como siguiente al actual, si el siguiente tiene paralelos, lo ingresa como
	 * el ultimo de los paralelos, luego mueve el cursor actual a la nueva posicion.
	 */
	void insertar(T dato);
//	void insertarComoParalelo(T dato);
	NodoGrafo<T>* obtenerActual();
	bool estaVacia();
	void retrocederCursor();
	T obtenerDatoActual();
	NodoGrafo<T>* obtenerPunteroNodoPrimero();
	bool avanzarCursor();
	bool avanzarCursorAParalela();

};

template <class T>
PseudoGrafo<T>::PseudoGrafo(){

		this->primero=NULL;
		this->actual=NULL;
}

template <class T>
void PseudoGrafo<T>::insertar(T dato){

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
			  while(paraleloSiguiente->tieneParalelo())
				  paraleloSiguiente->cambiarSiguiente(paraleloSiguiente->obtenerParalelo());
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
void PseudoGrafo<T>::retrocederCursor(){

	this->actual = this->actual->obtenerAnterior();
}

template <class T>
NodoGrafo<T>* PseudoGrafo<T>::obtenerPunteroNodoPrimero(){

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

#endif /* PSEUDOGRAFO_H_ */
