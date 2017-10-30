# include "buscador.h"

template<class T> Buscador<T>::Buscador(Lista<T>* pListaABuscar){
	this->pLista=pListaABuscar;

}

template<class T> bool Buscador<T>::buscar(uint filaBuscada, uint columnaBuscada, uint &posicionEncontrada=0){

		T elementoActual;

		bool encontrado=false;
		posicionEncontrada=0;
	
		pLista->iniciarCursor();

		while(pLista->avanzarCursor() && not encontrado){
			elementoActual=pLista->obtenerCursor();
			if (elementoActual.obtenerFila()==filaBuscada && elementoActual.obtenerColumna()==columnaBuscada){
				posicionEncontrada++;
				encontrado=true;
			}
		}
		return encontrado;

}
