#ifndef MARCADOR_H_
#define MARCADOR_H_



class Marcador{
	
	private:
		//Atributos
		int puntaje;
		int fila;
		int columna;
	        Mapa* mapa;
	
	public:
		//Metodos
		
		/*
		 *Pre: recibe un puntero al mapa del cual va a marcar.
		 *
		 * Post: Se asigna la ubicacion que se desea marcar y se inicializa puntaje en 0.
		 */
		Marcador(Mapa* mapaActual);
		
		/*
		 *Pre: 
		 *
		 * Post: Marca si la casilla no esta marcada y desmarca si la casilla esta marcada.
		 */
		void marcar(int filaJugada, int columnaJugada);
			
	privade:
	
		/*
		 *Pre: 
		 *
		 * Post: Marca si la casilla no esta marcada y desmarca si la casilla esta marcada.
		 */
		int realizarMarca();
	
		/*
		 *Pre: 
		 *
		 * Post: Marca si la casilla no esta marcada y desmarca si la casilla esta marcada.
		 */
		int desmarcarCasilla()
		
		/*
		 *Pre: 
		 *
		 * Post: Marca si la casilla no esta marcada y desmarca si la casilla esta marcada.
		 */
		int marcarCasilla()
};

#endif /*MARCADOR_H_*/
