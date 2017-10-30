# include "lista.h"
# include "mina.h"
# include "casilla.h"
# include "bandera.h"
# include "buscador.h"

class Mapa{
	
	private:
		unsigned int dimFila;
		unsigned int dimColumna;
		char dificultad;
		Lista<Mina>* pMinas;
		Lista<Casilla>* pCasillasDestapadas;
		Lista<Bandera>* pBanderas;
		unsigned int numeroDeMapa;
		BMP baseMapa;
	
	public:
		/*constructor
		 *pre: recibe como parametro la dim de las filas, 
		 *la dim de las columnas y la dificultad
		 *post:
		 */
	
		//pre: recibe como parametro la cantidad de filas y de columnas que tendra, y tambien la
		//dificultad elegida
		//post:crea un mapa con la cantidad de filas y columnas correspondientes y con tres listas
		// una de minas, otra de casillas destapadas y otra de marcas.
		Mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida);

	
	
		/* Post: devuelve la cantidad de filas del tablero de juego.*/
		uint obtenerFila();

		/* Post: devuelve la cantidad de columnas del tablero de juego.*/
		uint obtenerColumna();

		/* Post: devuelve la dificultad de la partida.*/
		char obtenerDificultad();
	
		/* Post: devuelve el tamaño de la lista de minas.*/
		uint obtenerTamanioDeLaListaDeMinas();
	
		/* Post: devuelve la cantidad de casillas que no han sido destapadas.*/
		uint obtenerCantidadDeCasillasOcultas();

		
		
		//post: se devuelve el puntero a la lista de minas.
		Lista<Mina>* obtenerPunteroMinas();
	
		//post: se devuelve el puntero a la lista de casillas destapadas.
		Lista<Casilla>* obtenerPunteroCasillas();
	
		//post: se devuelve el puntero a la lista de banderas.
		Lista<Bandera>* obtenerPunteroBanderas();
	
	
	
		//pre:
		//post: muestra por pantalla el mapa de juego.
		void mostrarMapa();

		/*Pre: Recibe fila y columna de una casilla.
		* Post: Devuelve si la casilla con ubicación dada por "fila" y "columna" está o no destapada.*/
		bool estaDestapadaLaCasilla(unsigned int fila, unsigned int columna);

		/*Pre: Recibe fila y columna.
		* Post: La casilla cuya posición está dada por "fila" y "colmna" queda destapada.*/
		void agregarCasillaDestapada(int filaRecibida, int colRecibida, char valorRecibido); 
		
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Devuelve su valor.*/
		char obtenerValorCasilla(int filaRecibida,int columnaRecibida);
		
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Devuelve si en la posicin dada por "fila" y "columna" hay o no una mina.*/
		bool validarMina(unsigned int fila, unsigned int columna);

	
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Coloca una marca en la posición dada por "fila" y "columna".*/
		void colocarMarca(int filaRecibida,int columnaRecibida);
		
		/*Pre: Recibe fila y columna de una casilla.
		* Post: si en la posición dada por "fila" y "columna" hay una marca, entonces la elimina.
		* Devuelve si en dicha posición hay o no una marca.*/
		bool removerYDevolverSiHabiaMarca(unsigned int fila, unsigned int columna);
	
	private:
		//pre: 
		//post: se crea una lista de minas y se asigna al atributo
		void crearListaMinasYAsignarPuntero();
	
		//pre: 
		//post: se crea una lista de casillas destapadas y se asigna al atributo
		void crearListaCasillasYAsignarPuntero();
	
	
		//pre: 
		//post: se crea una lista de banderas y se asigna al atributo
		void crearListaBanderasYAsignarPuntero();
	
		// métodos llamados por Mapa::mostrarMapa();
		void llenarVectorFila(unsigned int fila, char* vector[]);
		void llenarVectorDeNoMostrado(char* vector[]);
		void llenarVectorDeCasillasDestapadas(unsigned int fila,char* vector[]);
		void llenarVectorDeBanderas(unsigned int fila,char* vector[]);
		void mostrarVector(char* vector[]);

		/* Pre: reciba fila y columna de una casilla,
		* Post: devuelve si la casilla que tiene por ubicacin "fila" y "columna" está o no en la lista
		* de banderas.*/
		bool seEncuentraEnListaDeBanderas(uint &fila, uint &columna);	
	
		/* Pre: Recibe un char, ('m' para lista de minas, 'c' para lista de casillas, 'b' para lista de banderas),
		* y una ubicación de la casilla a buscar indicada por fila y columna.
		* Post: Busca en una de las tres listas, según indicado por "lista" y devuelve un bool indicando si
		* la casilla cuya ubicacin se pasó por parámetro está o no en la lista "lista".*/
		bool seEncuentraEnLista(char lista, uint &filaBuscada, uint &columnaBuscada);

		
		/* Pre: Recibe fila y columna de una casilla.
		* Post: devuelve el valor de esa casilla.*/
		char calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla);

};
		
