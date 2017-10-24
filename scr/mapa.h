# include "lista.h"
# include "mina.h"
# include "casilla.h"
# include "bandera.h"

class Mapa(){
	
	private:
		unsigned int dimFila;
		unsigned int dimColumna;
		char dificultad;
		Lista<Mina>* pMinas;
		Lista<Casilla>* pCasillasDestapadas;
		Lista<Bandera>* pBanderas;
		
		
	
	public:
		/*todo esto está desactualizado, faltan métodos,etc.
		 *Después los agrego, ooo háganlo ustedes y pónganle
		 *pre y post, xD
		 *constructor
		 *pre: recibe como parametro la dim de las filas, 
		 *la dim de las columnas y la dificultad
		 *post:
		 */
		void mapa(int filaRecibida, 
			  int columnaRecibida, 
			  char dificultadRecibida);
		
		
		void mostrarMapa();
				
		agregarCasillaDestapada(int filaRecibida,
					int colRecibida);
		
		char obtenerValorCasilla();
		
		Lista<Mina>* obtenerPunteroMinas();
		
		Lista<Casilla>* obtenerPunteroCasillasDestapas();
		
		Lista<Bandera>* obtenerPunteroBanderas();
		
		bool validarMina(unsigned int fila, 
				 unsigned int columna);

	
};
		
