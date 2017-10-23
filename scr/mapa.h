





class Mapa(){
	
	private:
		unsigned int dimFila;
		unsigned int dimColumna;
		char dificultad;
		Lista<Mina>* pMinas;
		Lista<Casilla>* pCasillasDestapadas;
		Lista<Bandera>* pBanderas;
		
		
	
	public:
	// todo esto está desactualizado, faltan métodos, etc. Después los agrego, ooo háganlo ustedes y pónganle pre y post, xD
		//constructor
		//pre: recibe como parametro la dim de las filas, la dim de las columnas y la dificultad
		//post: 
		void mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida);
		
		
		void mostrarMapa();
		
		
		void mostrarMapa();
		
		agregarCasillaDestapada(int filaRecibida,int colRecibida);
		
		char obtenerValorCasilla();
		
		Lista<Minas>* obtener punteroMinas();
		
		Lista<Minas>* obtener punteroMinas();
		
		Lista<Minas>* obtener punteroBanderas();
		
		bool validarMina(unsigned int fila, unsigned int columna);

	
};
		
