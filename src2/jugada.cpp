#include "jugada.h"


using namespace std;
        
	Jugada::Jugada(Mapa* mapaActual){
		this->mapa = mapaActual;
		this->fila = 0;
		this->columna = 0;
		this->puntaje = 0;
		this->opcion=NADA;
	}

	void Jugada::asignarOpcion(char opcionDeUsuario){
	    
		this->opcion = opcionDeUsuario;
	
	}

	void Jugada::asignarFila(int filaDeUsuario){
	    
		this->fila = filaDeUsuario;
	
	}
	
	void Jugada::asignarColumna(int columnaDeUsuario){
	    
		this->columna = columnaDeUsuario;
	
	}
  
	int Jugada::realizarJugada(){
		
		int puntos=0;
		
		if(this->opcion=='m' || this->opcion=='M'){
			
			Marcador* marcador = new Marcador(this->mapa);
			
			puntos = marcador->marcar(this->fila, this ->columna);
			
			delete marcador;
		}else if(this->opcion == 'd' || this->opcion == 'D'){
			
			Destapador* destapador = new Destapador(this->mapa);
			
			puntos = destapador->destapar(this->fila , this->columna);

			delete destapador;
		      
		}else{
			puntos = SE_RETIRO;
		}
		return puntos;
	}
