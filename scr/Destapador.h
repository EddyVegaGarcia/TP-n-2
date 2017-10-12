#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

#include "jugada.h"
#include "matriz.h"
#include "mina.h"

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
		 * Post: Se asigna la ubicacion que se desea destapar y se inicializa puntaje en 0.
		 */
		Destapador ();
		
		/*
		 *Pre: 
		 *
		 * Post: Descubre la casilla y efectua segun las tres tipos (vacia, enumerada, mina)
		 */
		void destapar();
		

		
		/*
		 *Pre:
		 *
		 * Post:El valor de la casilla confirma uno vacío, revele tanto esa casilla como vacías e
		 * enumeradas al rededor y se le asigna el puntaje correspondiente. 
		 */	
		void destaparPandemia();
			
			
			
		
		/*
		 *Pre:
		 *
		 * Post: El  valor de la casilla confirma una enumerada, se revela y y se le asigna el puntaje correspondiente.
		 */
		void destaparEnumerada();
			
			
		
		/*
		 *Pre:
		 *
		 * Post: El valor de la casilla confirma ser un numero se revela y se le asigna el puntaje correspondiente.
		 */
		void destaparNUmerada();
					
		
		/*
		 *Pre:
		 *
		 * Post: El valor de la casilla confirma una bomba y por consecuencia 
		 *el jugador actual opierde ,se revela la mina y se le asigna el puntaje correspondiente.
		 */
		void destaparMina();
		 
		 
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
		 * Post: Cofirma que la casilla toma uno de los tres tipos.
		 */
		char obtenerValorCasilla(matriz* matrizMapa);

};

#endif /*DESTAPADOR_H_ */
