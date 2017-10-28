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
		unsigned int numeroDeMapa;
		
	
		//pre: 
		//post: se crea una lista de minas y se asigna al atributo
		void crearListaMinasYAsignarPuntero();
	
		//pre: 
		//post: se crea una lista de casillas destapadas y se asigna al atributo
		void crearListaCasillasYAsignarPuntero();
	
	
		//pre: 
		//post: se crea una lista de banderas y se asigna al atributo
		crearListaBanderasYAsignarPuntero();
	
		
	
	public:
		/*todo esto está desactualizado, faltan métodos,etc.
		 *Después los agrego, ooo háganlo ustedes y pónganle
		 *pre y post, xD
		 *constructor
		 *pre: recibe como parametro la dim de las filas, 
		 *la dim de las columnas y la dificultad
		 *post:
		 */
	
		//pre: recibe como parametro la cantidad de filas y de columnas que tendra, y tambien la
		//dificultad elegida
		//post:crea un mapa con la cantidad de filas y columnas correspondientes y con tres listas
		// una de minas, de casillas destapadas y de marcas.
		mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida);
		
		//post: se devuelve el puntero a la lista de minas.
		Lista<Mina>* Mapa::obtenerPunteroMinas();
	
		//post: se devuelve el puntero a la lista de casillas destapadas.
		Lista<Casilla>* Mapa::obtenerPunteroCasillas();
	
		//post: se devuelve el puntero a la lista de banderas.
		Lista<Bandera>* Mapa::obtenerPunteroBanderas();
	
		//pre:
		//post: muestra por pantalla el mapa de juego.
		void mostrarMapa();
				
		agregarCasillaDestapada(int filaRecibida, int colRecibida); 
	
		char obtenerValorCasilla();
		
		Lista<Mina>* obtenerPunteroMinas();
		
		Lista<Casilla>* obtenerPunteroCasillasDestapas();
		
		Lista<Bandera>* obtenerPunteroBanderas();
		
		bool validarMina(unsigned int fila, unsigned int columna);

	
};
		
