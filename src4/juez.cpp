#include "juez.h"



using namespace std;

Juez::Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido){
	this->cantidadDeJugadores = cantidadJugadores;
	this->tableroDeJuego = mapaRecibido;
	this->jugadoresQuePerdieron = 0;
	
	crearYAsignarListaDeJugadores();
	
	crearJugadores();

}

void Juez::crearYAsignarListaDeJugadores(){

	this-> jugadores =  new ListaCircularCursor<Jugador*>;
}

void Juez::crearJugadores(){
	char alias = 'A';

/*	Jugador* entrante;
	for (int i=0; i<cantidadDeJugadores;i++){
		Jugador jugador(alias+i,tableroDeJuego);
		entrante=&jugador;

		this->jugadores->insertar(entrante);
	}*/
	for (int i=0; i<cantidadDeJugadores; i++){

		Jugador* entrante = new Jugador(alias+i,tableroDeJuego);
		this->jugadores->insertar(entrante);

	}


	this->jugadores->inicializarCursor();
}


/* Avanzar jugador hasta un jugador que siga jugando.*/
void Juez::avanzarJugador(){

	Jugador* siguiente;
	bool puedeJugar=false;

	this->jugadores->inicializarCursor();

	do{
		this->jugadores->avanzarCursor();
		siguiente = this->jugadores->obtenerCursor();

		if(siguiente->obtenerEstado() == SIGUE_JUGANDO)
			puedeJugar = true;

	}while(!puedeJugar);

}


Jugador* Juez::encontrarJugadorQueGanoPorPuntaje(){
	jugadores->inicializarCursor();
	Jugador* jugadorGanador;
	int puntajeMaximo = 0;

	int puntajesMostrados=0;
	bool seHaEncontrado=false;
	while(puntajesMostrados<cantidadDeJugadores && (!seHaEncontrado)){
		
		Jugador* jugadorActual;
		jugadorActual = jugadores->obtenerCursor();
		if(jugadorActual->obtenerPuntaje() > puntajeMaximo){
			puntajeMaximo = jugadorActual->obtenerPuntaje();
			jugadorGanador = jugadorActual;
			puntajesMostrados++;
			seHaEncontrado=true;
		}
		
		
	}
	return jugadorGanador;
	
}
void Juez::crearArchivoConPuntajes(){

	std::ofstream puntajes(archivoDePuntajes);
	int puntajesGuardados=0;

       while(puntajesGuardados<cantidadDeJugadores){
		char alias;
	    int puntaje;
		Jugador* jugadorActual;
		jugadorActual = jugadores->obtenerCursor();
		alias = jugadorActual->obtenerAlias();
		puntaje = jugadorActual->obtenerPuntaje();
	    puntajes << "el jugador" << alias << "obtuvo puntaje de: " << puntaje << endl;
	    puntajesGuardados++;
	       
       }	
   puntajes.close();

}


void Juez::inicializarJuego(){
	this->casillasOcultas=tableroDeJuego->obtenerCantidadDeCasillasOcultas();
	this->minasPorDescubrir=tableroDeJuego->obtenerTamanioDeLaListaDeMinas();

	uint banderasCorrectas = 0;

	this->jugadores->inicializarCursor();
	Jugador* jugadorActual;
	jugadores->avanzarCursor();
	bool terminoElJuego=false;


	while((jugadoresQuePerdieron<cantidadDeJugadores)&& (!terminoElJuego)){

		jugadorActual = this->jugadores->obtenerCursor();

		if(this->casillasOcultas > this->minasPorDescubrir
				&& banderasCorrectas<  this->minasPorDescubrir){

			if (jugadorActual->obtenerEstado() == SIGUE_JUGANDO){
				minasPorDescubrir = sigueJugando(jugadorActual, tableroDeJuego);
			}

			banderasCorrectas = buscarBanderasCorrectas();
			jugadores->avanzarCursor();

		else terminoElJuego=true;
			
		}
	}
	
	terminoLaPartida();
	

	Jugador* jugadorGanador = encontrarJugadorQueGanoPorPuntaje();
	mostrarFelicitaciones(jugadorGanador);
	crearArchivoConPuntajes();


}


uint Juez::sigueJugando(Jugador* jugadorActual, Mapa* tableroDeJuego){

	jugadorActual->iniciarJugada();

	if(jugadorActual->obtenerEstado() == PERDIO_PARTIDA){

		jugadoresQuePerdieron++;
		this->minasPorDescubrir--;

		jugadorActual->asignarEstado(NO_ESTA_JUGANDO);

		mostrarPuntajeDeJugadorQueHaPerdido(jugadorActual);
	}
	this->casillasOcultas=tableroDeJuego->obtenerCantidadDeCasillasOcultas();
	tableroDeJuego->mostrarMapa();

return this->minasPorDescubrir;
}

uint Juez::buscarBanderasCorrectas(){

	uint cantidadBanderasCorrectas = 0;

	Lista<Mina>* minas;
	Lista<Bandera>* banderas;

	minas = this->tableroDeJuego->obtenerPunteroMinas();
	banderas = this->tableroDeJuego->obtenerPunteroBanderas();

	minas->iniciarCursor();

	Bandera actual;

	while(banderas->avanzarCursor()){

		actual = banderas->obtenerCursor();
		if(banderaEsCorrecta(actual,minas))
			cantidadBanderasCorrectas++;
	}

	return cantidadBanderasCorrectas;
}

bool Juez::banderaEsCorrecta(Bandera actual,Lista<Mina>*minas){

	bool encontrada = false;
	Mina compatible;

	minas->iniciarCursor();

	while(minas->avanzarCursor() && !encontrada){

		compatible = minas->obtenerCursor();

		if(actual.obtenerFila() == compatible.obtenerFila() &&
				actual.obtenerColumna() == compatible.obtenerColumna())

			encontrada = true;

	}

return encontrada;
}

void Juez::mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual){
	int puntaje = 0;
	char alias;
	alias = jugadorActual->obtenerAlias();
	puntaje = jugadorActual->obtenerPuntaje();
	cout<<" El jugador " << alias << " ha perdido XD XD"<<endl;
	cout<< "Su puntaje es " << puntaje << endl;

}

void Juez::terminoLaPartida(){
	cout << "Juego terminado :)." << endl;
}

void Juez::mostrarFelicitaciones(Jugador* jugadorActual){
	cout << jugadorActual->obtenerAlias() << "!!! Ganaste !!!" << endl;
	cout << "Tu puntaje es: " << jugadorActual->obtenerPuntaje() << "."<< endl;
}


Juez::~Juez(){
	this->jugadores->inicializarCursor();
	Jugador* jugadorActual;
	jugadorActual = this->jugadores->obtenerCursor();
	while( !(this->jugadores->estaVacia()) ){

		Jugador* jugadorABorrar;
		char alias;
		int puntaje;
		alias = jugadorActual->obtenerAlias();
		puntaje = jugadorActual->obtenerPuntaje();
		cout<<"El jugador: " << alias << " tiene " << puntaje << " puntos." << endl;
		jugadorABorrar = jugadorActual;
		this->jugadores->avanzarCursor();
		jugadorActual = this->jugadores->obtenerCursor();


		delete jugadorABorrar;
		this->jugadores->remover(1);
	}
	delete this->jugadores;

}
