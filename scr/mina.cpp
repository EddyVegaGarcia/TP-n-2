include "mina.h"

	
	
	mina(int filaMina, int columnaMina, matriz* tableroOriginal){
		
		this->fila = filaMina;
	    
	    this->columna = columnaMina;
	    
	    this->tablero = tableroOriginal;
	    
	}
	
	void mina::explota(){
		
	    this->*tablero.modificarCasilla(this->fila , this->casilla, '*');
	    
	    arbitro.eliminarJugador();
	}
	
