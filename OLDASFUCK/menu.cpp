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
	uint opcion=0;
	do{
		std::cout<<"\t\t.:BUSCAMINAS:."<<std::endl;
		std::cout<<std::endl;
		std::cout<<"\t.:MENU INICIAL:."<<std::endl;
		std::cout<<"1.JUGAR"<<std::endl;
		std::cout<<"2.REGLAS"<<std::endl;
		std::cout<<"3.SALIR DE MENU"<<std::endl;
		std::cout<<".:ELIJA OPCION: ";
		std::cin>>opcion;

		if(opcion == 1){
			Imprimir_Titulo();
			pedirOpcionesDeJuegoAUser();
			crearAmbiente();
		}

		if(opcion == 2){
			reglas();
		}

	}while(opcion!=3);
}

void Menu::reglas(){

	std::cout<<"•Juego multijugador con sistema de juego por turnos y "<<std::endl;
	std::cout<<"evaluado con puntajes."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Cada jugador comienza con un puntaje de 0."<<std::endl;
	std::cout<<"• Se adquiere un punto si marca una casilla con una"<<std::endl;
	std::cout<<"bandera y esta efectivamente tiene una mina, y se"<<std::endl;
	std::cout<<"pierde un punto si se marca una casilla y esta no tiene"<<std::endl;
	std::cout<<"una mina."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Se puede desmarcar una bandera, si en la posición de la"<<std::endl;
	std::cout<<"marca que se retiró efectivamente no habia una mina, el"<<std::endl;
	std::cout<<"jugador gana dos puntos, si por el contrario si había una"<<std::endl;
	std::cout<<"mina, se quita dos puntos."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Cuando se pide al usuario la ubicación de la casilla que"<<std::endl;
	std::cout<<"quiera modificar (fila y columna), estos datos deben ser"<<std::endl;
	std::cout<<"números adecuados a las opciones que el usuario marcó"<<std::endl;
	std::cout<<"en un principio, siendo números entre 1 y la dimensión"<<std::endl;
	std::cout<<"que haya elegido, y de igual manera las opciones de "<<std::endl;
	std::cout<<"M(marcar), D (destapar) y R (retirarse)."<<std::endl;
	std::cout<<"• Se debe evitar a toda costa las minas, con ayuda de los"<<std::endl;
	std::cout<<"casilleros numerados, sino el “GAME OVER” te elimina del"<<std::endl;
	std::cout<<"juego."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Las condiciones para ganar o perder se deciden de la"<<std::endl;
	std::cout<<"siguiente forma:"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Si todos los jugadores se retiran antes de ganar el juego"<<std::endl;
	std::cout<<"el ganador será quien tenga el mayor puntaje, si no, gana"<<std::endl;
	std::cout<<"el jugador que llegó hasta el final, los puntajes se"<<std::endl;
	std::cout<<"mostrarán hasta el final del juego junto con el nombre del"<<std::endl;
	std::cout<<"ganador."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Recuerde que para disfrutar plenamente del juego se"<<std::endl;
	std::cout<<"debe siempre respetar los valores válidos que se deben"<<std::endl;
	std::cout<<"usar al momento de jugar."<<std::endl;

}

void Menu::Imprimir_Linea(){
	std::cout<<"\n--------------------------------------------------"<<std::endl;
}

void Menu::Imprimir_Titulo(){
	Imprimir_Linea();
	std::cout<<"\t.:JUGANDO BUSCAMINAS:.";
	Imprimir_Linea();
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

	std::cout<<".:PIDIENDO DATOS:."<<std::endl;

	pedirYAsignarDimensiones();
	pedirYAsignarDificultad();
	pedirYAsignarCantJugadores();

	comprobarDatos();
}

void Menu::comprobarDatos(){

	std::string dificultadPalabra;
	uint dificultadNumerica;

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

	std::cout<<".:COMPROBANDO COMANDOS:."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Tamanio de la tabla de BUSCAMINAS: \t\t"<<this->dimFila<<" X "<<this->dimColumna<<std::endl;

	std::cout<<"Dificultad pedida: \t\t\t\t.:"<<dificultadPalabra<<":."<<std::endl;
	std::cout<<"Cantidad de MINAS en el BUSCAMINAS: \t\t"<<(this->dimFila*this->dimColumna*dificultadNumerica)/100<<std::endl;
	std::cout<<"Cantidad de JUGADORES: \t\t\t\t"<<cantJugadores<<std::endl;
	std::cout<<std::endl;

}

void Menu::pedirYAsignarDimensiones(){

	uint filUser, colUser;

	std::cout<<std::endl;
	std::cout << "FILAS y COLUMNAS totales para su tablero (ej: 40 60): " << std::endl;
	std::cin >> filUser >> colUser;
	std::cout<<std::endl;

	asignarFila(filUser);
	asignarColumna(colUser);
}

void Menu::pedirYAsignarDificultad(){
	char difUser;
	std::cout << "Ingresar dificultad (un caracter): F (facil) / M (medio) / D (dificil):" << std::endl;
	std::cin >> difUser;
	std::cout<<std::endl;
	
	asignarDificultad(difUser);
}

void Menu::pedirYAsignarCantJugadores(){
	uint cantUser;
	std::cout << "Ingresar la cantidad de jugadores:" << std::endl;
	std::cin >> cantUser;
	std::cout<<std::endl;
		
	asignarCantJugadores(cantUser);
}

void Menu::crearAmbiente(){
	Mapa mapa(this->dimFila, this->dimColumna, dificultad);
	Mapa* punteroAMapa=&mapa;
	Juez juez(cantJugadores, punteroAMapa);
	juez.inicializarJuego();

}
