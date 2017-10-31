#include "nodo.h"

template<class T>
Nodo<T>::Nodo(T dato)
{
	this->dato=dato;
	this->siguiente=NULL;
}

template<class T>
T Nodo<T>::obtenerDato()
{
	return this->dato;
}

template<class T>
void Nodo<T>::cambiarDato(T nuevoDato)
{
	this->dato =nuevoDato;
}

template<class T>
Nodo<T>* Nodo<T>::obtenerSiguiente()
{
	return this->siguiente;
}

template<class T>
void Nodo<T>::cambiarSiguiente(Nodo<T>* nuevoSiguiente)
{
	this->siguiente=nuevoSiguiente;
}
