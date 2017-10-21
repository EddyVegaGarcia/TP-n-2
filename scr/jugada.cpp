include "jugada.h"
include "constantes.h"

using namespace std;
        
	jugada::jugada(mapa* mapaActual){
		this->mapa = mapaActual;
		this->fila = 0;
		this->columna = 0;
		this->puntaje = 0;
	}

	void jugada::asignarOpcion(char opcionDeUsuario){
	    
		this->opcion = opcionDeUsuario;
	
	}

	void jugada::asignarFila(int filaDeUsuario){
	    
		this->fila = filaDeUsuario;
	
	}
	
	void jugada::asignarColumna(int columnaDeUsuario){
	    
		this->columna = columnaDeUsuario;
	
	}
  
	int jugada::realizarJugada(){
		
		int puntos=0;
		
		if(this->opcion=='m' || this->opcion=='M'){
			
			marcador(this->mapa*);
			
			puntos = marcador.marcar(this->fila , this ->columna);
			
		}else if(this->opcion == 'd' || this->opcion == 'D'){
			
			destapador(this->mapa , this->tablero);
			
			puntos = destapador.destapar(this->fila , this->columna);
		      
		}else{
			
			puntos = SE_RETIRO
		}
		return puntos ;
	}
