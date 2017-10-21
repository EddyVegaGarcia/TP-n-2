#include "menu.h"
# include <iostream>
using namespace std;

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
	this->fila=fila;
}

void Menu::asignarColumna(uint columna){
	this->columna=columna;
}

void Menu::asignarDificultad(char dificultad){
	this->dificultad=dificultad;
}

void Menu::asignarCantJugadores(uint cant){
	this->cantJugadores=cant;
}


// obtener

uint Menu::obtenerFila(){
	return fila;
}
uint Menu::obtenerColumna(){
	return columna;
}
char Menu::obtenerDificultad(){
	return dificultad;
}

uint Menu::obtenerCantJugadores(){
	return cantJugadores;
}


// Interacción con user

void Menu::pedirOpcionesDeJuegoAUser(){
	pedirYAsignarDimensiones();
	pedirYAsignarDificultad();
	pedirYAsignarCantJugadores();
}

void Menu::pedirYAsignarDimensiones(){
	uint filUser, colUser;
	cout << "Ingresar cantidad de filas y columnas (ej: 40 60)" << endl;
	cin >> filUser >> colUser;

	asignarFila(filUser);
	asignarColumna(colUser);
}

void Menu::pedirYAsignarDificultad(){
	uint difUser;
	cout << "Ingresar dificultad (un caracter): F (facil) / M (medio) / D (dificil):" << endl;
	cin >> difUser;
	
	asignarDificultad(difUser);
}

void Menu::pedirYAsignarCantJugadores(){
	uint cantUser;
	cout << "Ingresar la cantidad de jugadores:" << endl;
	cin >> cantUser;
		
	asignarCantJugadores(cantUser);
}

void Menu::crearAmbiente(){
	Mapa mapa(fila, columna, dificultad);
	Mapa* punteroAMapa=&mapa;
	Juez juez(punteroAMapa);
}
