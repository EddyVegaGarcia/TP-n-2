#include "menu.h"



// Constructor
Menu::Menu(){
	asignarFila(0);
	asignarColumna(0);
	asignarDificultad(0);
	asignarCantJugadores(0);
	
	pedirOpcionesDeJuegoAUser();
	crearAmbiente();
	
}

void Menu::asignarFila(uint fila){
	this->dimFila=fila;
}

void Menu::asignarColumna(uint columna){
	this->dimColumna=columna;
}

void Menu::asignarDificultad(char dificultad){
	this->dificultad=dificultad;
}

void Menu::asignarCantJugadores(uint cantJugadores){
	this->cantJugadores=cantJugadores;
}


// obtener

uint Menu::obtenerFila(){
	return this->dimFila;
}
uint Menu::obtenerColumna(){
	return this->dimColumna;
}
char Menu::obtenerDificultad(){
	return this->dificultad;
}

uint Menu::obtenerCantJugadores(){
	return this->cantJugadores;
}


// Interacción con user

void Menu::pedirOpcionesDeJuegoAUser(){
	pedirYAsignarDimensiones();
	pedirYAsignarDificultad();
	pedirYAsignarCantJugadores();
}

void Menu::pedirYAsignarDimensiones(){
	uint filUser, colUser;
	std::cout << "Ingresar cantidad de filas y columnas (ej: 40 60)" << std::endl;
	std::cin >> filUser >> colUser;

	asignarFila(filUser);
	asignarColumna(colUser);
}

void Menu::pedirYAsignarDificultad(){
	uint difUser;
	std::cout << "Ingresar dificultad (un caracter): F (facil) / M (medio) / D (dificil):" << std::endl;
	std::cin >> difUser;
	
	asignarDificultad(difUser);
}

void Menu::pedirYAsignarCantJugadores(){
	uint cantUser;
	std::cout << "Ingresar la cantidad de jugadores:" << std::endl;
	std::cin >> cantUser;
		
	asignarCantJugadores(cantUser);
}

void Menu::crearAmbiente(){
	Mapa mapa(this->dimFila, this->dimColumna, dificultad);
	Mapa* punteroAMapa=&mapa;
	Juez juez(cantJugadores, punteroAMapa);
	juez.inicializarJuego();

}
