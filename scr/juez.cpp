


#include "juez.h"

	Juez::Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido){

		tableroDeJuego = mapaRecibido;
		Lista<Jugador*>* ingresantes;
		this->jugadores = ingresantes;

		char alias = 'A';

		for (int i=0; i<cantidadJugadores;i++){

			Jugador* entrante = new Jugador(alias+i,mapaRecibido);
			insertarJugador(entrante);
		}

		this->jugadores->iniciarCursor();

	}

	void Juez::avanzarJugador(){

		Jugador* siguiente;
		bool puedeJugar=false;

		do{
			this->jugadores->avanzarCursor();
			Jugador* siguiente = this->jugadores->obtenerCursor();

			if(siguiente->obtenerEstado() == 0)
				puedeJugar = true;

		}while(!puedeJugar);

	}

	void Juez::mostrarJugador(){

		Jugador* elegido;
		elegido = this->jugadores->obtenerCursor();

		elegido->mostrar();
	}

	void Juez::insertarJugador(Jugador* nuevo){

		this->jugadores->insertar(nuevo);
	}

	Juez::inicializarJuego();
       Juez::~juez(){
	       
       		while( !(this->jugadores->estaVacia()) ){
			jugador* jugadorActual;
			char alias;
			int puntaje;
	   		this->jugadores->iniciarCursor();
			jugadorActual = this->jugadores->obtenerCursor();
			alias = jugardorActual->obtenerAlias();
			puntaje = jugadorActual->obtenerPuntaje();
		
			cout<<" el jugador : " << alias << "tiene " << puntaje << "puntos." << endl;
			this->jugadores->remover(1);
		}
       
       }
