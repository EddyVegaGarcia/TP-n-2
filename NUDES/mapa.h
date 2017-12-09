#ifndef MAPA_H_
#define MAPA_H_

# include "buscador.h"
# include "lista.h"
# include "mina.h"
# include "minero.h"
# include "casilla.h"
# include "bandera.h"

# include "constantes.h"
# include "diseniador.h"
# include "EasyBMP_BMP.h"



class Mapa{
	
	private:
		uint dimFila;
		uint dimColumna;
		char dificultad;
		Lista<Mina>* pMinas;
		Lista<Casilla>* pCasillasDestapadas;
		Lista<Bandera>* pBanderas;
		uint numeroDeMapa;
		Diseniador diseniador;

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
		Mapa(uint filaRecibida, uint columnaRecibida, char dificultadRecibida);
	
		//destructor
		~Mapa();

	
	
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

		/*Pre: Recibe fila, columna y valor de la casilla a agregar.
		* Post: La casilla cuya posición está dada por "fila" y "columna"
		*	queda destapada y con valor valorRecibido.*/
		void agregarCasillaDestapada(int filaRecibida, int colRecibida, char valorRecibido); 
		
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Devuelve si en la posicin dada por "fila" y "columna" hay o no una mina.*/
		bool validarMina(unsigned int fila, unsigned int columna);

	
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Coloca una marca en la posición dada por "fila" y "columna".*/
		void colocarMarca(int filaRecibida,int columnaRecibida);
		
		/*Pre: Recibe fila y columna de una casilla.
		* Post: si en la posición dada por "fila" y "columna" hay una marca, entonces la elimina.
		* 	Devuelve si en dicha posición había o no una marca.*/
		bool removerYDevolverSiHabiaMarca(unsigned int fila, unsigned int columna);

		void llenarMapaBanderas(Lista<Bandera>* banderas);
	
		/*Pre: Recibe fila y columna de una casilla.
		* Post: Devuelve su valor.*/
		char obtenerValorCasilla(int filaRecibida,int columnaRecibida);

		void eliminarCasillaDestapada(unsigned int fila, unsigned int columna);

		void eliminarCasillasDestapadasDesde(unsigned int fila, unsigned int columna);

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

		
		/* Pre: Recibe fila y columna de una casilla.
		* Post: devuelve el valor de esa casilla.*/
		char calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla);

		void llenarMapaCasillasDestapadas(Lista<Casilla>* casillas);

};


#endif /*MAPA_H_*/
