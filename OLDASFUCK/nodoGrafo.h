#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

#include "constantes.h"
#include "iostream"



template<class T>
class NodoGrafo
{
	private:
		T dato;
		NodoGrafo<T>* siguiente;
		NodoGrafo<T>* anterior;
		NodoGrafo<T>* paralelo;
	public:
		NodoGrafo(T dato);
		T obtenerDato();
		void cambiarDato(T nuevoDato);
		NodoGrafo<T>* obtenerSiguiente();
		NodoGrafo<T>* obtenerAnterior();
		NodoGrafo<T>* obtenerParalelo();
		void cambiarSiguiente(NodoGrafo<T>* nuevoSiguiente);
		void cambiarAnterior(NodoGrafo<T>* nuevoAnterior);
		void cambiarParalelo(NodoGrafo<T>* nuevoPararelo);
		bool tieneSiguiente();
		bool tieneParalelo();
};

template<class T>
NodoGrafo<T>::NodoGrafo(T dato)
{
	this->dato=dato;
	this->siguiente=NULL;
	this->anterior=NULL;
	this->paralelo=NULL;
}

template<class T>
T NodoGrafo<T>::obtenerDato()
{
	return this->dato;
}

template<class T>
void NodoGrafo<T>::cambiarDato(T nuevoDato)
{
	this->dato =nuevoDato;
}

template<class T>
NodoGrafo<T>* NodoGrafo<T>::obtenerSiguiente()
{
	return this->siguiente;
}

template<class T>
NodoGrafo<T>* NodoGrafo<T>::obtenerAnterior()
{
	return this->anterior;
}

template<class T>
NodoGrafo<T>* NodoGrafo<T>::obtenerParalelo()
{
	return this->paralelo;
}

template<class T>
void NodoGrafo<T>::cambiarSiguiente(NodoGrafo<T>* nuevoSiguiente)
{
	this->siguiente=nuevoSiguiente;
}

template<class T>
void NodoGrafo<T>::cambiarAnterior(NodoGrafo<T>* nuevoAnterior)
{
	this->anterior=nuevoAnterior;
}

template<class T>
void NodoGrafo<T>::cambiarParalelo(NodoGrafo<T>* nuevoParalelo)
{
	this->paralelo = nuevoParalelo;
}

template<class T>
bool NodoGrafo<T>::tieneParalelo(){

	return (!(this->paralelo == NULL));
}

template<class T>
bool NodoGrafo<T>::tieneSiguiente(){

	return(!(this->siguiente == NULL));
}


#endif /* NODOGRAFO_H_ */
