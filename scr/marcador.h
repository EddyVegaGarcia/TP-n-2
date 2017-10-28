#ifndef MARCADOR_H_
#define MARCADOR_H_



class Marcador{
	
	private:
		//Atributos
		int puntaje;
		int fila;
		int columna;
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
