include "jugada.h"

using namespace std;

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
			
			marcador();
			
			puntos = marcador.marcar(this->fila , this ->columna);
			
		}else if(this->opcion == 'd' || this->opcion == 'D'){
			
			destapador();
			
			destapador.destapar(this->fila , this->columna);
		      
		}else{
			
			arbitro.eliminarJugador();
		}
		return puntos ;
	}
