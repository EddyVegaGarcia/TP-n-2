#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

#include "mapa.h"
#include "constantes.h"
#include "casilla.h"
#include "lista.h"

class Destapador{
	
	private:
		uint fila;
		uint columna;
		Mapa* mapa;
		Lista<Casilla>* pVacios;
	
	
	public:
		/* Pre: Recibe un puntero al mapa en el cual va a marcar.
		 * Post: Crea un Destapador.*/
		Destapador(Mapa* mapaActual);
			
		/* Pre: Recibe "filaJugada" y "columnaJugada" que indican la ubicación de una casilla.
		 * Post: Se establece la casilla central sobre la cual el Destapador va a operar.
		 *	Destapa la casilla cuya ubicación se pasó por parámetro.
		 *	Devuelve ("un puntaje") el estado del Jugador luego de destapada la casilla, que depende de
		 *	la presencia o no de una mina en dicha casilla.*/
		unsigned int destapar(uint filaJugada, uint columnaJugada);


		~Destapador();

	
	private:
		void crearListaCasillasYAsignarPuntero();

		/* Pre: Recibe una variable "puntaje" de tipo int.
		* Post: Destapa la casilla.*/
		void puntajeAlDestapar(uint &puntaje);
	
		/* Pre: Recibe dos variables de tipo int, que indican la ubicación de la casilla central.
		 *	La casilla central ya está destapada, y no es ni está rodeada por minas.
		 * Post: Destapa todas las casillas que rodean a la casilla central, alejándose de la misma
		 *	hasta encontrar una casilla con un valor numérico que indique que dicha casilla se
		 *	encuentra alrededor de una con mina. La casilla de estas características será la
		 *	última que será destapada en esa dirección.*/
		void destaparPandemia();

		void avanzarPandemia(int avanzarNueva, uint &filaPasada, uint &columnaPasada);

		void destaparPandemiaRecursiva( uint filaPasada, uint columnaPasada);
	



		void agregarVacio(uint filaPasada, uint columnaPasada);




		bool pasoPorAqui(uint filaPasada, uint columnaPasada);

		/* Pre: La casilla ya está destapada. Recibe una variable de tipo char.
		* Post: Devuelve el ("puntaje") estado correspondiente, dependiendo del valor de la casilla
		*	(indica que el Jugador perdió si es una mina, y que continúa jugando en cualquier otro caso).*/
		unsigned int destaparCasillaNoVacia(char valorCasilla);
		 
};

#endif /*DESTAPADOR_H_ */
