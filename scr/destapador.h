#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

# include "mapa.h"
# include "constantes.h"

class Destapador{
	
	private:
		int fila;
		int columna;
		Mapa* mapa;
	
	
	public:
		/* Pre: Recibe un puntero al mapa en el cual va a marcar.
		 * Post: Crea un Destapador.*/
		Destapador(Mapa* mapaActual);
			
		/* Pre: Recibe "filaJugada" y "columnaJugada" que indican la ubicación de una casilla.
		 * Post: Se establece la casilla central sobre la cual el Destapador va a operar.
		 *	Destapa la casilla cuya ubicación se pasó por parámetro.
		 *	Devuelve ("un puntaje") el estado del Jugador luego de destapada la casilla, que depende de
		 *	la presencia o no de una mina en dicha casilla.*/
		int destapar(int filaJugada, int columnaJugada);

	
	private:

		/* Pre: Recibe una variable "puntaje" de tipo int.
		* Post: Destapa la casilla.*/
		void puntajeAlDestapar(int &puntaje); /* Por qué se llama así??? Es el que destapa, *shrugs*.*/
	
		/* Pre: Recibe dos variables de tipo int, que indican la ubicación de la casilla central.
		 *	La casilla central ya está destapada, y no es ni está rodeada por minas.
		 * Post: Destapa todas las casillas que rodean a la casilla central, alejándose de la misma
		 *	hasta encontrar una casilla con un valor numérico que indique que dicha casilla se
		 *	encuentra alrededor de una con mina. La casilla de estas características será la
		 *	última que será destapada en esa dirección.*/
		void destaparPandemia(); // recibe fila y columna, pasarle this->fila, this->columna	
		/* Para mí (soy aldana, hola:)) una de estas dos sobra. */
		void destaparPandemiaRecursiva(int filaPasada, int columnaPasada);
	
	
		/* Pre: La casilla ya está destapada. Recibe una variable de tipo char.
		* Post: Devuelve el ("puntaje") estado correspondiente, dependiendo del valor de la casilla
		*	(indica que el Jugador perdió si es una mina, y que continúa jugando en cualquier otro caso).*/
		int destaparCasillaNoVacia(char valorCasilla);
				
	
		/////////////////////////////////////////////////////////////////////////////////

	
		/* "destaparCasilla()", esto no está implementado. Hablan de "int destaparCasillaNoVacia(char valorCasilla)"?*/
		/* Pre:
		 * Post: El  valor de la casilla se revela y y se le asigna el puntaje correspondiente.
		 */
		void destaparCasilla();
		/*
		 *Pre:
		 * Post: El valor de la casilla confirma una bomba y por consecuencia 
		 *el jugador actual pierde y se le asigna el puntaje correspondiente.
		 *Si se confirma casilla enumerada se le asigna el puntaje correspondiente.
		 */
		void asignarPuntaje(); /* "asignarPuntaje()" tampoco está implementado.
		* Por la post imagino que hablan de "int destaparCasillaNoVacia(char valorCasilla);"*/
	
	
		
		 
};

#endif /*DESTAPADOR_H_ */
