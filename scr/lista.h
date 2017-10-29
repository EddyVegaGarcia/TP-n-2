#ifndef LISTA_H_
#define LISTA_H_

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
		~Lista();

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

	private:
		Nodo<T>* obtenerNodo(unsigned int posicion);

};

#endif
