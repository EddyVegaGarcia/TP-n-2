#ifndef MARCADOR_H_
#define MARCADOR_H_

#include "jugada.h"
#include "matriz.h"


class Destapador{
	
	private:
		//Atributos
		int puntaje;
		int ubicacion;
	
	public:
		//Metodos
		
		/*
		 *Pre:
		 *
		 * Post: Se asigna la ubicacion que se desea marcar y se inicializa puntaje en 0.
		 */
		Marcador ();
		
		/*
		 *Pre: NO MARCAR DONDE YA ESXISTE UN MARCADOR.
		 *
		 * Post: Marca la casilla con la ubicacion que se jugó.
		 */
		void marcar();
		

		
		/*
		 *Pre: Se recibe por parametro un puntero a la matriz que contiene al tablero.
		 *
		 * Post: Colaca la marca donde se supone que hay una mina., no se revela y por 
		 * consecuencia no se pierde.
		 */	
		void marcarTablero(matriz* matrizTablero);
			
		
		/*
		 *Pre: Se pasa por parametro un valor entero valido.
		 *
		 * Post: Segun las reglas de juego se le asigna puntos segun si acertó con el marcador o no.
		 */
		void asignarPuntaje(int punt);
		
		/*
		 *Pre: 
		 *
		 * Post: Devuelve el puntaje que obtuvo el jugador.
		 */
		int obtenerPuntaje();
		
		
	private:
		//metodos privados.
		
		
		/*
		 *Pre:
		 *
		 * Post: Asigna la ubicacion de la casilla obtenida de jugada.
		 */
		int asiganrUbicacion();
		
		/*
		 *Pre: Se pasa por parametro un puntero a la matriz que contiene el tablero.
		 *
		 * Post: Cofirma que la cailla toma uno de los tres tipos.
		 */
		char verificarTablero(matriz* matrizTablero);
		
		
		/*
		 *Pre: Se pasa por parametro un puntero a la matriz que contiene el tablero.
		 *
		 * Post: Cofirma que la cailla toma uno de los tres tipos.
		 */
		char verificarMapa(matriz* matrizMapa);
				
		
};

#endif /*MARCADOR_H_*/
