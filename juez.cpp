


#include "juez.h"
#include "lista.h"


void Juez::Juez(int cantidadJugadores){
	
// Hola mati soy aldana y vengo a comentarte todo el código (?) xD. Sí, te dejo comentarios y no lo cambio.

	// El juez recibe (cantidadJugadores, ok), como segundo parámetro, un puntero a Mapa.
	// Hay que asignar ese puntero que recibiste a un atributo que tiene que tener el juez, un puntero a Mapa.

	char caracterDeJugador = 'A';
	
	for(int i=1; i<=cantidadJugadores; i++){
		
		this-> jugadores-> agregar(caracterDeJugador,i);
		// Acá adentro insertás el jugador, pero lo tenés que crear. (Por qué no leés el hermoso jugador.h que hice)
		 // te lo copipasteo, constructor de jugador: "Jugador(char letra, Mapa* punteroAMapa);"
		// (o sea la lista es de jugadores, no le agregás un caracter sino un jugador)
		
	}


}

void Juez::avanzarJugador(){

	if (this-> jugadores -> cursor == NULL) // afsdfs cursor es un atributo privado
		this-> jugadores -> cursor -> iniciarCursor();
	else
		this-> jugadores -> avanzarCursor();

}

bool Juez::haGanado(Jugador aVerificar){

	bool jugadorGano = false;

}

bool Juez::mostrarJugador(){

	Jugador actual = this-> jugadores -> obtenerCursor();

	std::cout<<"Jugador: "<< Jugador.nombre<< std::endl; // afsfdfdfwe privado, usá los obtener.
				// y es "objeto.método()", el nombre del objeto es "actual". "Jugador" es el nombre de la clase.

}

void Juez::insertarJugador(Jugador nuevo){

	this-> jugadores -> agregar(nuevo);

}

bool Juez::mostrarPuntaje(){

	Jugador actual = this-> jugadores -> obtenerCursor();

	std::cout<<"Puntaje:"<< Jugador.puntaje<< std::endl;

}

void Juez::eliminarJugador(){

	this-> jugadores -> remover(); // me fui a fijar y remover recibe la posicion.
				// no sé,     ni idea     , "problema de matías", xD. Suerte, xD.
}
