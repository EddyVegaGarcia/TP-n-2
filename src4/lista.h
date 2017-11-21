#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include "nodo.h"

template <class T>
class Lista
{
	private:
		Nodo<T>* primero;
		unsigned int tamanio;
		Nodo<T>* cursor;

	public:
		Lista();


		bool estaVacia();
		unsigned int contarElementos();
		void agregar(T elemento);
		void agregar(T elemento, unsigned int posicion);
		T obtener(unsigned int posicion);
		void asignar(T elemento, unsigned int posicion);
		void remover(unsigned int posicion);
		void iniciarCursor();
		bool avanzarCursor();
		T obtenerCursor();

		~Lista();

	private:
		Nodo<T>* obtenerNodo(unsigned int posicion);

};


template<class T>
Lista<T>::Lista()
{
		this->primero=NULL;
		this->tamanio=0;
		this->cursor=NULL;
}

template<class T>
bool Lista<T>::estaVacia()
{
	return (this->tamanio==0);
}

template<class T>
unsigned int Lista<T>::contarElementos()
{
	return this->tamanio;
}

template<class T>
void Lista<T>::agregar(T elemento)
{
	this->agregar(elemento, this->tamanio+1);
}

template<class T>
void Lista<T>::agregar(T elemento, unsigned int posicion)
{
	if((posicion>0)&&(posicion<=this->tamanio+1))
	{
		Nodo<T>* nuevo = new Nodo<T>(elemento);
		if(posicion==1)
		{
			nuevo->cambiarSiguiente(this->primero);
			this->primero=nuevo;
		}
		else
		{
			Nodo<T>* anterior=this->obtenerNodo(posicion-1);
			nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
			anterior->cambiarSiguiente(nuevo);
		}
		this->tamanio++;
		this->iniciarCursor();
	}
}

template<class T>
T Lista<T>::obtener(unsigned int posicion)
{
	T elemento;
	if((posicion>0)&&(posicion<=this->tamanio))
	{
		elemento=this->obtenerNodo(posicion)->obtenerDato();
	}
	return elemento;
}

template<class T>
void Lista<T>::asignar(T elemento, unsigned int posicion)
{
	if((posicion>0)&&(posicion<=this->tamanio))
	{
		this->obtenerNodo(posicion)->cambiarDato(elemento);
	}
}

template<class T>
void Lista<T>::remover(unsigned int posicion)
{
	if((posicion>0)&&(posicion<=this->tamanio))
	{
		Nodo<T>* removido;
		if(posicion==1)
		{
			removido=this->primero;
			this->primero=removido->obtenerSiguiente();
		}
		else
		{
			Nodo<T>* anterior=this->obtenerNodo(posicion-1);
			removido=anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}
		delete removido;
		this->tamanio--;
		this->iniciarCursor();
	}
}

template<class T>
void Lista<T>::iniciarCursor()
{
	this->cursor=NULL;
}

template<class T>
bool Lista<T>::avanzarCursor()
{
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

template<class T>
T Lista<T>::obtenerCursor()
{
	T elemento;
	if(this->cursor!=NULL)
	{
		elemento=this->cursor->obtenerDato();
	}
	return elemento;
}

template<class T>
Lista<T>::~Lista()
{
	while(this->primero!=NULL){
		Nodo<T>* aBorrar=this->primero;
		this->primero=this->primero->obtenerSiguiente();
		delete aBorrar;
	}
}

template<class T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion)
{
	Nodo<T>* actual=this->primero;
	for(unsigned int i = 1; i<posicion; i++){
		actual=actual->obtenerSiguiente();
	}
	return actual;
}

#endif /*LISTA_H_*/
