#ifndef MARCADOR_H_
#define MARCADOR_H_

class Destapador{
	
	private:
		//Atributos
		int puntaje;
		int filaJugada;
		int columnaJugada;
	        mapa* mapa;
	
	public:
		//Metodos
		
		/*
		 *Pre:
		 *
		 * Post: Se asigna la ubicacion que se desea marcar y se inicializa puntaje en 0.
		 */
		Marcador(mapa* matrizMapa, tablero* matrizTablero);
		
		/*
		 *Pre: 
		 *
		 * Post: Marca si la casilla no esta marcada y desmarca si la casilla esta marcada.
		 */
		void marcar(int filaJugada, int columnaJugada);
			
		
		/*
		 *Pre: Se pasa por parametro un valor entero valido.
		 *
		 * Post: Segun las reglas de juego se le asigna puntos segun si acertó con el marcador o no.
		
		void asignarPuntaje();
		 */
	
		/*
		 *Pre:
		 *
		 Post: Se obtiene el valor del puntaje al realizar la jugada marcar.;
		 */
		int obtenerPuntajePorMarcar()
		
};

#endif /*MARCADOR_H_*/
