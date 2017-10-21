





class Mapa(){
	
	private:
		unsigned int dimFila;
		unsigned int dimColumna;
		char dificultad;
		Lista* pMinas;
		Lista* pCasillasDestapadas;
		Lista* pBanderas;
		
		
	
	public:
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
		
		void mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){
			
			this-> dimFila = filaRecibida;
			this-> dimColumna = columnaRecibida;
			this-> dificultad = DificultadRecibida;
			
			pMinas = Minero-> sembrarMinas();
			pCasillasDestapadas = new lista<Casillas>;
			pBanderas = new lista<Banderas>;
		}
		
		void mostrarMapa(){
			
			unsigned int vector[this->dimColumna];
				
				for (unsigned int i=0; i< this->columna; i++)
					vector[i] = 0;
			
			for (unsigned int i=1; i<= this-> dimFila; i++){
				
				this-> pCasillasDestapadas -> inicializarCursor();
				
				while(this-> pcasillasDestapadas ->avanzarCursor()){
					
					nodoActual = pcasillasDestapadas -> obtenerNodo();
					
					if (nodoActual.fila == i)
						vector[nodoActual.columna] = nodoActual.obtenerValor();
						
				}
				
				while(this-> pBanderas ->avanzarCursor()){
					
					nodoActual = Banderas -> obtenerNodo();
					
					if (nodoActual.fila == i)
						vector[nodoActual.columna-1] = 9; //9 para la bandera.
						
				}
				
				for ( unsigned int i = 0; i< this->columna; i++)
					
					if(vector[i] == 9)
						std::cout<<Bandera<<;
					else if (vector[i] == 0) 
						std::cout<<'*':
					else 
						std::cout<< vector[i];
					std::endl;
			}
		
		agregarCasillaDestapada(int filaRecibida,int colRecibida){
			
			this-> pMinas-> agregarValor(pMinas->ultimo);
		}
		
		//pre: lista casillas no vacia
		//post: devuelve valor de la ultima casilla
		char obtenerValorCasilla(){
			
			*Casilla punteroCasilla = this -> pMinas -> obtenerPuntero();
			return *punteroCasilla;
		}
		
		Lista<Minas>* obtener punteroMinas(){
			return this-> pMinas
		}
		
		Lista<Minas>* obtener punteroMinas(){
			
			return this-> pCasillasDestapadas;
		}
		
		Lista<Minas>* obtener punteroBanderas(){
			
			return this-> pBanderas;
		
		}
		
		bool validarMina(unsigned int fila, unsigned int columna){
			
		}
}

