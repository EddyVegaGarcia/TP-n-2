#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T>
class Nodo
{
	private:
		T dato;
		Nodo<T>* siguiente;
	public:
		Nodo(T dato);
		T obtenerDato();
		void cambiarDato(T nuevoDato);
		Nodo<T>* obtenerSiguiente();
		void cambiarSiguiente(Nodo<T>* nuevoSiguiente);
};

#endif
