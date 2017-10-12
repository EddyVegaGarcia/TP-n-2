#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

#include "Jugada.h"
//#include "matriz.h"
#include "Mapa.h"
#include "Tablero.h"
#include "Mina.h"

class Destapador{
	
	private:
		//Atributos
		int filaJugada;
		int columnaJugada;
		int ubicacion;
	
	public:
		//Metodos
		
		/*
		 *Pre:
		 *
		 * Post: Se asigna la ubicacion que se desea destapar y se inicializa puntaje en 0.
		 *Se crea clases para poder utilizarlas.
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
		 * Post:La casilla confirma un vacío, revele tanto esa casilla como vacías e
		 * enumeradas al rededor y se le asigna el puntaje correspondiente. 
		 */	
		void destaparPandemia();
			
			
			
		
		/*
		 *Pre:
		 *
		 * Post: El  valor de la casilla se revela y y se le asigna el puntaje correspondiente.
		 */
		void destaparCasilla();
			
			

		/*
		 *Pre:
		 *
		 * Post: El valor de la casilla confirma una bomba y por consecuencia 
		 *el jugador actual pierde y se le asigna el puntaje correspondiente.
		 *Si se confirma casilla enumerada se le asigna el puntaje correspondiente.
		 */
		void asignarPuntaje();
	
	
		/*
		 *Pre:
		 *
		 *Post: Se obtiene el valor del puntaje al realizar la jugada revelar.
		 */
		int obtenerPuntajePorRevelar();
	
	private:
	
		/*
		 *Pre:
		 *
		 * Post: Crea clases para utilizar sus metodos.
		 */
		void crearClases();
		 
		 
};

#endif /*DESTAPADOR_H_ */
