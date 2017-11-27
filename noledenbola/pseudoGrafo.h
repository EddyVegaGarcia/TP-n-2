


#ifndef PSEUDOGRAFO_H_
#define PSEUDOGRAFO_H_

#include "nodoGrafo.h"
#include "jugada.h"

template <class T> class PseudoGrafo{

private:
	NodoGrafo<Jugada*>* primero;
	NodoGrafo<Jugada*>* actual;

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

};

template <class T>
PseudoGrafo<T>::PseudoGrafo(){

		this->primero=NULL;
		this->actual=NULL;
}

template <class T>
void PseudoGrafo<T>::insertar(T dato){

	NodoGrafo<T>* nuevo = new NodoGrafo<T>(dato);


	if(primero == NULL){

		primero = nuevo;

	}else if(actual->obtenerSiguiente() == NULL){ //si el actual no tiene siguiente
	      NodoGrafo<T>* anterior = actual;
	      anterior->cambiarSiguiente(nuevo);
	      nuevo->cambiarAnterior(anterior);
	}else{									//si el actual tiene siguiente, agregarlo como paralelo
		  NodoGrafo<T>* siguiente = actual ->obtenerSiguiente();
		  NodoGrafo<T>* paraleloSiguiente;

		  bool recorrido = false;
		  do{
			  if(siguiente->tieneParalelo()){
				  paraleloSiguiente = siguiente->obtenerParalelo();
			  }
			  else recorrido = true;


		  }while(!recorrido);
		  paraleloSiguiente->cambiarParalelo(nuevo);
		  nuevo->cambiarAnterior(actual);
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


#endif /* PSEUDOGRAFO_H_ */
