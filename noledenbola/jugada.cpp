#include "jugada.h"


using namespace std;
        
	Jugada::Jugada(Mapa* mapaActual){
		this->mapa = mapaActual;
		this->fila = 0;
		this->columna = 0;
		this->puntaje = 0;
		this->opcion=NADA;
	}

	int Jugada::obtenerFila(){
		return this->fila;
	}
	int Jugada::obtenerColumna(){
		return this->columna;
	}
	char Jugada::obtenerOpcion(){
		return this->opcion;
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
			
			Marcador marcador(this->mapa);
			
			puntos = marcador.marcar(this->fila, this ->columna);
			
		}else if(this->opcion == 'd' || this->opcion == 'D'){
			
			Destapador destapador(this->mapa);
			
			puntos = destapador.destapar(this->fila , this->columna);
		      
		}else{
			puntos = SE_RETIRO;
		}
		return puntos;
	}
/*        bool Jugada:: operator = (Jugada a, Jugada b)  {
   		bool sonIguales = false;
		if((a.obtenerFila == b.obtenerFila)&&(a.obtenerColumna == b.obtenerColumna)&&
		     					(a.obtenerOpcion == b.obtenerOpcion)){
			sonIguales = true;
		
		}
   	return sonIguales; 
	}*/
