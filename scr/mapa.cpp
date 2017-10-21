include "mapa.h"


Mapa::mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){
			
			this-> dimFila = filaRecibida;
			this-> dimColumna = columnaRecibida;
			this-> dificultad = DificultadRecibida;
			
			pMinas = Minero-> sembrarMinas();
			pCasillasDestapadas = new lista<Casillas>;
			pBanderas = new lista<Banderas>;
		}
		
		void mapa::mostrarMapa(){
			
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
		
		void mapa::agregarCasillaDestapada(int filaRecibida,int colRecibida){
			
			this-> pMinas-> agregarValor(pMinas->ultimo);
		}
		
		//pre: lista casillas no vacia
		//post: devuelve valor de la ultima casilla
		char mapa::obtenerValorCasilla(){
			
			*Casilla punteroCasilla = this -> pMinas -> obtenerPuntero();
			return *punteroCasilla;
		}
		
		Lista<Minas>* mapa::obtenerPunteroMinas(){
			return this-> pMinas
		}
		
		Lista<Minas>* mapa::obtenerPunteroMinas(){
			
			return this-> pCasillasDestapadas;
		}
		
		Lista<Minas>* mapa::obtenerPunteroBanderas(){
			
			return this-> pBanderas;
		
		}
		
		bool mapa::validarMina(unsigned int fila, unsigned int columna){
			
		}
}

