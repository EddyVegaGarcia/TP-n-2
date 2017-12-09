/*#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include "nodoGrafo.h"

template <class T>


class lista {
   public:
    lista();
    ~lista();
    
    void Insertar(T dato);
    void Borrar(T dato);
    bool ListaVacia() { return primero == NULL; } 
    void Primero();
    bool Actual() { return primero != NULL; }
 
    
   private:
   
    NodoGrafo<Jugada>* primero; 
    
};

template <class T>
ListaDoble<T>::ListaDoble()
{
		this->primero=NULL;
		
}

template <class T>
listaDoble::~listaDoble() {
   NodoGrafo<T> aux;
   
   Primero();
   while(primero) {
      aux = primero;
      primero = primero->obtenerSiguiente;
      delete aux;
   }
}

template <class T>
void listaDoble::Insertar(T dato) {
   NodoGrafo<T> nuevo;
 
   Primero();
   nuevo = new nodoGrafo(dato);
   // Si la lista está vacía
   
   if(ListaVacia()) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      
      nuevo->cambiarAnterior(primero);
      nuevo->cambiarSiguiente(primero);
      primero = nuevo;
      
      
      
   }
   else {
      NodoGrafo<T> primeroAntiguo;
       primeroAntiguo = primero
     primero->cambiarAnterior = nuevo;
      nuevo->cambiarSiguiente(primero);
      nuevo->cambiarAnterior(primero->obtenerAnterior);
      primero = nuevo;
   }
}
template <class T>
void lista::Borrar(T dato) {
   nodoGrafo<T> nodo;
   
   nodo = primero;
      while( nodo && nodo->obtenerDato != dato) 
         nodo = nodo->obtenerSiguiente;
      if(nodo->obtenerDato == dato){
         nodoGrafo<T> anterior = nodo->obtenerAnterior;
         nodoGrafo<T> siguiente = nodo->obtenerSiguiente;
         anterior->cambiarSiguiente(siguiente);
         siguiente->cambiarAnterior(anterior);
         delete nodo;
      }

}




void lista::Primero() {
   while(primero && primero->anterior) primero = primero->anterior;
}


