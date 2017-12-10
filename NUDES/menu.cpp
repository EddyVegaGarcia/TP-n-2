#include "menu.h"
# include <string>


// Constructor
Menu::Menu(){
	asignarFila(0);
	asignarColumna(0);
	asignarDificultad(0);
	asignarCantJugadores(0);
	
	menuPrincipal();
	
}

void Menu::menuPrincipal(){
	char opcionChar='0';
	int opcion= 0;
	Pantalla pantalla;
	
	do{

		opcionChar = pantalla.imprimirOpcionesDeMenu();

		opcion = (int)opcionChar;

		if((opcion - 48) == 1){
			pantalla.imprimirTitulo();
			pedirOpcionesDeJuegoAUser();
			crearAmbiente();
		}

		if((opcion - 48) == 2){
			pantalla.imprimirReglasDeJuego();
		}
		
	}while(opcion!=51);
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

	Pantalla pantalla;
	pantalla.pidiendoDatos();

	pedirYAsignarDimensiones();
	pedirYAsignarDificultad();
	pedirYAsignarCantJugadores();

	comprobarDatos();
}

void Menu::comprobarDatos(){

	std::string dificultadPalabra;
	uint dificultadNumerica;
	Pantalla pantalla;

	if (dificultad=='D'|| dificultad=='d')
	{
		dificultadPalabra = "DIFICIL";
		dificultadNumerica = DIFICIL;
	}
	else if (dificultad=='M'||dificultad=='m')
	{
		dificultadPalabra = "MEDIO";
		dificultadNumerica = MEDIO;
	}
	else{
		dificultadPalabra = "FACIL";
		dificultadNumerica = FACIL;
	}
	
	int numeroDeMinas = (this->dimFila*this->dimColumna*dificultadNumerica)/100;
	
	if (numeroDeMinas==0)
		numeroDeMinas = 1;
	
	pantalla.imprimirDatosIngresados();

}

void Menu::pedirYAsignarDimensiones(){

	uint filUser, colUser;
        do{
		pantalla.pedirDimensiones(filUser, colUser);
        }While(filUser<=0 || colUser<=0);
		
	asignarFila(filUser);
	asignarColumna(colUser);
}

void Menu::pedirYAsignarDificultad(){
	char difUser;
	Pantalla pantalla;
	
	difUser = pantalla.pedirDificultad();
	asignarDificultad(difUser);
}

void Menu::pedirYAsignarCantJugadores(){
	uint cantUser;
	Pantalla pantalla;
	
	cantUser = pantalla.pedirCantidadJugadores();
	asignarCantJugadores(cantUser);
}

void Menu::crearAmbiente(){
	Mapa mapa(this->dimFila, this->dimColumna, dificultad);
	//Mapa* punteroAMapa=&mapa;
	Juez juez(cantJugadores, &mapa);
	juez.inicializarJuego();
}
