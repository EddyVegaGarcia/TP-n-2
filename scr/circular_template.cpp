// Lista circular en C++ con plantillas
// (C) Agosto 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
#include "CCadena.h"
using namespace std;

template<class TIPO> class lista;

template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    TIPO valor;
    nodo<TIPO> *siguiente;

   friend class lista<TIPO>;
};

template<class TIPO>
class lista {
   public:
    lista() { actual = NULL; }
    ~lista();

    void Insertar(TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return actual == NULL; }
    void Mostrar();
    void Siguiente();
    bool Actual() { return actual != NULL; }
    TIPO ValorActual() { return actual->valor; }

   private:
    nodo<TIPO> *actual;
};

template<class TIPO>
lista<TIPO>::~lista()
{
   nodo<TIPO> *Nodo;

   // Mientras la lista tenga más de un nodo
   while(actual->siguiente != actual) {
      // Borrar el nodo siguiente al apuntado por lista
      Nodo = actual->siguiente;
      actual->siguiente = Nodo->siguiente;
      delete Nodo;
   }
   // Y borrar el último nodo
   delete actual;
   actual = NULL;
}

template<class TIPO>
void lista<TIPO>::Insertar(TIPO v)
{
   nodo<TIPO> *Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo<TIPO>(v);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}

template<class TIPO>
void lista<TIPO>::Borrar(TIPO v)
{
   nodo<TIPO> *Nodo;

   Nodo = actual;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if(actual->siguiente->valor != v) actual = actual->siguiente;
   } while(actual->siguiente->valor != v && actual != Nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(actual == actual->siguiente) {
         // Borrar toda la lista
         delete actual;
         actual = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         Nodo = actual->siguiente;
         actual->siguiente = Nodo->siguiente;
         delete Nodo;
      }
   }
}

template<class TIPO>
void lista<TIPO>::Mostrar()
{
   nodo<TIPO> *Nodo = actual;

   do {
      cout << Nodo->valor << "-> ";
      Nodo = Nodo->siguiente;
   } while(Nodo != actual);

   cout << endl;
}

template<class TIPO>
void lista<TIPO>::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

int main()
{
   lista<int> iLista;
   lista<float> fLista;
   lista<double> dLista;
   lista<char> cLista;
   lista<Cadena> sLista;

   // Prueba con <int>
   iLista.Insertar(20);
   iLista.Insertar(10);
   iLista.Insertar(40);
   iLista.Insertar(30);
   iLista.Insertar(60);

   iLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   iLista.Borrar(10);
   iLista.Borrar(30);

   iLista.Mostrar();

   // Prueba con <float>
   fLista.Insertar(20.01);
   fLista.Insertar(10.02);
   fLista.Insertar(40.03);
   fLista.Insertar(30.04);
   fLista.Insertar(60.05);

   fLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   fLista.Borrar(10.02);
   fLista.Borrar(30.04);

   fLista.Mostrar();

   // Prueba con <double>
   dLista.Insertar(0.0020);
   dLista.Insertar(0.0010);
   dLista.Insertar(0.0040);
   dLista.Insertar(0.0030);
   dLista.Insertar(0.0060);

   dLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   dLista.Borrar(0.0010);
   dLista.Borrar(0.0030);

   dLista.Mostrar();

   // Prueba con <char>
   cLista.Insertar('x');
   cLista.Insertar('y');
   cLista.Insertar('a');
   cLista.Insertar('b');
   cLista.Insertar('m');

   cLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   cLista.Borrar('y');
   cLista.Borrar('b');

   cLista.Mostrar();

   // Prueba con <Cadena>
   sLista.Insertar("Hola");
   sLista.Insertar("somos");
   sLista.Insertar("programadores");
   sLista.Insertar("buenos");
   sLista.Insertar("!!!!");

   sLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   sLista.Borrar("somos");
   sLista.Borrar("buenos");

   sLista.Mostrar();

   cin.get();
   return 0;
}
