#ifndef DESTAPADOR_H_
#define DESTAPADOR_H_

class Destapador{
	
	private:
		//Atributos
		int filaJugada;
		int columnaJugada;
		Mapa* mapa;
	
		
			
	
	public:
		//Metodos
		
		/*
		 *Pre:recibe un puntero al mapa del cual va a destapar. 
		 *
		 * Post: se guarda la casilla destapada y su valor en el mapa para mostrarse
		 */
		Destapador (Mapa* mapaActual);
		
		/*
		 *Pre:recibe fila y columna que se a jugado. 
		 *
		 * Post: Descubre 		 
		 */
		void destapar(int filaJugada, int columnaJugada);
			
	
		/*
		 *Pre: 
		 *
		 * Post: Descubre la casilla y efectua segun las tres tipos (vacia, enumerada, mina)
		 */
		void puntajeAlDestapar(int &puntaje);
	
	private:
		
	
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
		 * Post:La casilla confirma un vacío, revele tanto esa casilla como vacías e
		 * enumeradas al rededor y se le asigna el puntaje correspondiente. 
		 */	
		void destaparPandemiaRecursiva(int filaPasada, int columnaPasada);	
		
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
	
	
		
		 
};

#endif /*DESTAPADOR_H_ */
