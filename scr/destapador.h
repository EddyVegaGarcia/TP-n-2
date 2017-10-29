#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

class Destapador{
	
	private:
		int filaJugada;
		int columnaJugada;
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
		* Post: Destapa la casilla,*/
		void puntajeAlDestapar(int &puntaje);
		/* Por qué se llama así??? Es el que destapa, *shrugs*.*/
	
		/* Pre:
		 * Post:La casilla confirma un vacío, revele tanto esa casilla como vacías e
		 * enumeradas al rededor y se le asigna el puntaje correspondiente.*/
		/* */
		void destaparPandemia();
			
		
		/*
		 *Pre:
		 *
		 * Post:La casilla confirma un vacío, revela tanto esa casilla como vacías e
		 * enumeradas al rededor y se le asigna el puntaje correspondiente. 
		 */	
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
