#include "juez.h"

Juez::Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido){
	cantidadDeJugadores = cantidadJugadores;
	tableroDeJuego = mapaRecibido;
	Lista<Jugador*>* ingresantes;
	this->jugadores = ingresantes;

	char alias = 'A';
	
	Jugador* entrante;
	for (int i=0; i<cantidadJugadores;i++){
		Jugador jugador(alias+i,mapaRecibido);
		entrante=&jugador;		
		insertarJugador(entrante);
	}
	delete entrante;

	this->jugadores->iniciarCursor();

}

/* Este método sería un "avanzar jugador hasta un jugador que siga jugando".
* Ver cómo/si se conjuga esto con el método inicializarJuego que hizo dafi más abajo.*/
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

void Juez::inicializarJuego(){
	int jugadoresQuePerdieron = 0 ;

	this->jugadores->inicializarCursor();

	Jugador* jugadorActual;

	while(jugadoresQuePerdieron<cantidadDeJugadores){

		jugadorActual = this->jugadores->obtenerCursor();

		if(jugadorActual->obtenerEstado() == SIGUE_JUGANDO){

			sigueJugando(jugadorActual, jugadoresQuePerdieron, tableroDeJuego);

		}
		jugadores->avanzarCursor();
	}


}
void Juez::sigueJugando(Jugador* jugadorActual, int &jugadoresQuePerdieron, Mapa* tableroDeJuego){

	jugadorActual->iniciarJugada();

		if(jugadorActual->obtenerEstado() == PERDIO_PARTIDA){

			jugadoresQuePerdieron++;

			jugadorActual->asignarEstado(NO_ESTA_JUGANDO);

			elJugadorHaPerdido(jugadorActual);
		}
	 tableroDeJuego->mostrarMapa();
}

void Juez::elJugadorHaPerdido(Jugador* jugadorActual){
	int puntaje = 0;
	char alias;
	alias = jugadorActual->obtenerAlias();
	puntaje = jugadorActual->obtenerPuntaje();
	cout<<" El jugador " << alias << " ha perdido XD XD"<<endl;
	cout<< "Su puntaje es " << puntaje << endl;

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
