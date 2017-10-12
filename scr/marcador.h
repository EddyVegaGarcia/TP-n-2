#ifndef MARCADOR_H_
#define MARCADOR_H_

#include "jugada.h"
#include "mapa.h"
#include "tablero.h"
#include "mina.h"

class Destapador{
	
	private:
		//Atributos
		int puntaje;
		int filaJugada;
		int columnaJugada;
	
	public:
		//Metodos
		
		/*
		 *Pre:
		 *
		 * Post: Se asigna la ubicacion que se desea marcar y se inicializa puntaje en 0.
		 */
		Marcador();
		
		/*
		 *Pre: NO MARCAR DONDE YA EXISTE UN MARCADOR.
		 *
		 * Post: Marca la casilla con la ubicacion que se jugó.
		 */
		void marcar();
			
		
		/*
		 *Pre: Se pasa por parametro un valor entero valido.
		 *
		 * Post: Segun las reglas de juego se le asigna puntos segun si acertó con el marcador o no.
		
		void asignarPuntaje();
		 */
	
		/*
		 *Pre:
		 *
		 *Post: Se obtiene el valor del puntaje al realizar la jugada revelar.
		 */
		int obtenerPuntajePorMarcar();
		
		
	private:
		//metodos privados.
		
		/*
		 *Pre:
		 *
		 * Post: Crea clases para utilizar sus metodos.
		 */
		void crearClases();
				
		
};

#endif /*MARCADOR_H_*/
