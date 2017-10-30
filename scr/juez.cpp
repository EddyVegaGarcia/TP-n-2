#include "juez.h"
#include "constantes.h"
#include <fstream.h>

Juez::Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido){
	this->cantidadDeJugadores = cantidadJugadores;
	this->tableroDeJuego = mapaRecibido;
	
	crearYAsignarListaDeJugadores();
	
	crearJugadores();

}

void Juez::crearYAsignarListaDeJugadores(){
	Lista<Jugador*> listaDeJugadores;
	this-> jugadores = &listaDeJugadores;
}

void Juez::crearJugadores(){
	char alias = 'A';

		Jugador* entrante;
		for (int i=0; i<cantidadJugadores;i++){
			Jugador jugador(alias+i,mapaRecibido);
			entrante=&jugador;		
			insertarJugador(entrante);
		}

		this->jugadores->iniciarCursor();
}


/* Avanzar jugador hasta un jugador que siga jugando.*/
void Juez::avanzarJugador(){

	Jugador* siguiente;
	bool puedeJugar=false;

	do{
		this->jugadores->avanzarCursor();
		Jugador* siguiente = this->jugadores->obtenerCursor();

		if(siguiente->obtenerEstado() == SIGUE_JUGANDO)
			puedeJugar = true;

	}while(!puedeJugar);

}

void Juez::mostrarJugador(){

	Jugador* elegido;
	elegido = this->jugadores->obtenerCursor();

	elegido->mostrar(); // no implementado, no sé qué quieren que muestre (y tampoco para qué).
				// ya hay un obtener de alias y de puntaje, no sé   quÉ mÁs   quiEREN DE MI, jaja nah en serio.
}

void Juez::insertarJugador(Jugador* nuevo){

	this->jugadores->insertar(nuevo);
}
jugador* encontrarJugadorQueGanoPorPuntaje(Lista<Jugador*>* jugadores, int cantidadDeJugadores){
	jugadores->inicializarCursor();
	Jugador* jugadorGanador;
	int puntajeMaximo = 0;
	while(jugadores<=cantidadDeJugadores){
		
		Jugador* jugadorActual;
		jugadorActual = jugadores->obtenerCursor();
		if(jugadorActual->obtenerPuntaje() > puntajeMaximo){
			puntajeMaximo = jugadorActual->obtenerPuntaje();
			jugadorGanador = jugadorActual;
		}
		
		
	}
	return jugadorGanador;
	
}
void crearArchivoConPuntajes(Lista<Jugador*>* jugadores, int cantidadDeJugadores){
   ofstream puntajes(archivoDePuntajes); 
       while(jugadores<=cantidadDeJugadores){
		char alias;
	        int puntaje;
		Jugador* jugadorActual;
		jugadorActual = jugadores->obtenerCursor();
	       alias = jugadorActual->obtenerAlias();
	       puntaje = jugadorActual->obtenerPuntaje();
	        puntajes << "el jugador" << alias << "obtuvo puntaje de: " << puntaje << endl;
	       
		
       }	
   puntajes.close();

}
void Juez::inicializarJuego(){
	uint casillasOcultas=tableroDeJuego->obtenerCantidadDeCasillasOcultas();
	uint minasPorDescubrir=tableroDeJuego->obtenerTamanioDeLaListaDeMinas();
	int jugadoresQuePerdieron = 0 ;

	this->jugadores->inicializarCursor();
	Jugador* jugadorActual;

	while(jugadoresQuePerdieron<cantidadDeJugadores-1){

		jugadorActual = this->jugadores->obtenerCursor();

		if(jugadorActual->obtenerEstado() == SIGUE_JUGANDO){

			sigueJugando(jugadorActual, jugadoresQuePerdieron, tableroDeJuego, minasPorDescubrir);

		}
		jugadores->avanzarCursor();
	}
	
	/* Queda un solo jugador */
	avanzarJugador(); /* dejo el cursor apuntando al que sigue jugando */
	while(jugadorActual->obtenerEstado() == SIGUE_JUGANDO){
		if (casillasOcultas==minasPorDescubrir){
			jugadorActual->asignarEstado(HA_GANADO);
			mostrarFelicitaciones(jugadorActual);
		}

		sigueJugando(jugadorActual, jugadoresQuePerdieron, tableroDeJuego, minasPorDescubrir);

	}
	jugador* jugadorGanador = encontrarJugadorQueGanoPorPuntaje(this->jugadores, catidadDeJugadores);
	mostrarFelicitaciones(jugadorGanador);
	crearArchivoConPuntajes(this->jugadores, cantidadDeJugadores);


}
void Juez::sigueJugando(Jugador* jugadorActual, int &jugadoresQuePerdieron, Mapa* tableroDeJuego, uint &minasPorDescubrir){

	jugadorActual->iniciarJugada();

		if(jugadorActual->obtenerEstado() == PERDIO_PARTIDA){

			jugadoresQuePerdieron++;
			minasPorDescubrir--;
						
			jugadorActual->asignarEstado(NO_ESTA_JUGANDO);

			mostrarPuntajeDeJugadorQueHaPerdido(jugadorActual);
		}
	 tableroDeJuego->mostrarMapa();
}

void Juez::mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual){
	int puntaje = 0;
	char alias;
	alias = jugadorActual->obtenerAlias();
	puntaje = jugadorActual->obtenerPuntaje();
	cout<<" El jugador " << alias << " ha perdido XD XD"<<endl;
	cout<< "Su puntaje es " << puntaje << endl;

}

void Juez::mostrarFelicitaciones(Jugador* jugadorActual){
	cout << jugadorActual->obtenerAlias() << "!!! Ganaste !!!" << endl;
	cout << "Tu puntaje es: " jugadorActual->obtenerPuntaje() << "."<< endl;
}


Juez::~Juez(){

	while( !(this->jugadores->estaVacia()) ){
		Jugador* jugadorActual;
		char alias;
		int puntaje;
		this->jugadores->inicializarCursor();
		jugadorActual = this->jugadores->obtenerCursor();
		alias = jugardorActual->obtenerAlias();
		puntaje = jugadorActual->obtenerPuntaje();

		cout<<"El jugador: " << alias << " tiene " << puntaje << " puntos." << endl;
		this->jugadores->remover(1);
	}

}
