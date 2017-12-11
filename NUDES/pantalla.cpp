# include "pantalla.h"

////////////////////////////////////
/////// Llamados desde Juez ////////
////////////////////////////////////


void Pantalla::playGame(){
    std::cout<<".:PLAY GAME::."<<std::endl;

}
char Pantalla::pedirOpcionPasadoFuturo (){
    
   	char opcionDeUsuario;

    std::cout<<"VOLVER AL PASADO 'deshacer' (P) || ";
 	std::cout<<"VOLVER AL FUTURO 'rehacer' (F) || "<<std::endl;
 	std::cout<<"Ya no realizar JUGADA ESPECIAL (N) : "<<std::endl;
    std::cin>>opcionDeUsuario;
    
   	return opcionDeUsuario;
 }

int Pantalla::pedirOpcionRehacerJugada(PseudoGrafo<JugadaLight*>* jugadas){
	uint contador = 1;
	uint opcionUsuario;
	bool puedeRehacerJugada = true;

	JugadaLight* actual;
        do {
		std::cout<<"jugadas realizadas desde este punto: "<<std::endl;

		jugadas->avanzarCursor();
		actual = jugadas->obtenerDatoActual();
	
		if(actual == NULL){
			puedeRehacerJugada = false;
		}


		std::cout<<"jugada 1: ";
		std::cout<<"fila: "<<actual->obtenerFila()<<" columna: "<<actual->obtenerColumna()
				<<" opcion: "<<actual->obtenerOpcion()<<std::endl;

		while(jugadas->avanzarCursorAParalela()){
			contador++;
			actual=jugadas->obtenerDatoActual();
			std::cout<<"jugada "<<contador<<": ";
			std::cout<<"fila: "<<actual->obtenerFila()<<" columna: "<<actual->obtenerColumna()
				<<" opcion: "<<actual->obtenerOpcion()<<std::endl;
		}
		jugadas->retrocederCursor();

		std::cout<<std::endl<<"elija una de las jugadas para rehacer"<<std::endl;
		std::cin>>opcionUsuario;

        }while (opcionUsuario < 1|| opcionUsuario > contador || !puedeRehacerJugada);

        if(!puedeRehacerJugada){
        	opcionUsuario = -1;
        }
	
  	return opcionUsuario;
}
void Pantalla::noSePuedeRetroceder(){
    std::cout<<"no se puede retroceder mas"<<std::endl;

}

void Pantalla::mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual){

	int puntaje = 0;
	char alias;
	alias = jugadorActual->obtenerAlias();
	puntaje = jugadorActual->obtenerPuntaje();
	std::cout<<std::endl;
	std::cout<<".:EL JUGADOR " << alias << " OBTUVO SU GAME OVER:. "<<std::endl;
	std::cout<< "PUNTAJE OBTENIDO: " << puntaje << std::endl;

}

void Pantalla::terminoLaPartida(){

	std::cout<<std::endl;
	std::cout << "\t\t\t.:GAME OVER:." << std::endl;
	std::cout<<std::endl;

}
void Pantalla::mostrarFelicitaciones(Jugador* jugadorActual, int puntajesMaximosIguales){

	if(puntajesMaximosIguales == 0){
		std::cout << jugadorActual->obtenerAlias() << "!!! GANASTE !!!" << std::endl;
		std::cout << "Tu puntaje es: " << jugadorActual->obtenerPuntaje() << "."<< std::endl;
	}

	if(puntajesMaximosIguales > 0)
		std::cout<<"SE OBTUVO UN EMPATE... INTENTEN DE NUEVO."<<std::endl;

	std::cout<<std::endl;

}

////////////////////////////////////
/////// Llamados desde Menu ////////
////////////////////////////////////

char Pantalla::imprimirOpcionesDeMenu(){
	char opcionChar='0';
	std::cout<<"\t\t.:BUSCAMINAS:."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"\t.:MENU INICIAL:."<<std::endl;
	std::cout<<"1.JUGAR"<<std::endl;
	std::cout<<"2.REGLAS"<<std::endl;
	std::cout<<"3.SALIR DE MENU"<<std::endl;
	std::cout<<".:ELIJA OPCION: ";
	std::cin>>opcionChar;
	return opcionChar;
}

void Pantalla::imprimirReglasDeJuego(){

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
	std::cout<<"jugador gana dos puntos; si por el contrario si había una"<<std::endl;
	std::cout<<"mina, se quita dos puntos."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Las condiciones para ganar o perder se deciden de la"<<std::endl;
	std::cout<<"siguiente forma:"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"\t Si todos los jugadores se retiran antes de ganar el juego"<<std::endl;
	std::cout<<"\t el ganador será quien tenga el mayor puntaje, si no, gana"<<std::endl;
	std::cout<<"\t el jugador que llegó hasta el final, los puntajes se"<<std::endl;
	std::cout<<"\t mostrarán hasta el final del juego junto con el nombre del"<<std::endl;
	std::cout<<"\t ganador."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Las condiciones para jugar una JUGADA ESPECIAL es de la "<<std::endl;
	std::cout<<"siguiente forma:"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"\t Se deberá llegar al puntaje requerido de '4' puntos, como "<<std::endl;
	std::cout<<"\t minimo, ya que la jugada quita esa cantidad a sus puntos actuales."<<std::endl;
	std::cout<<"\t Si ya se a realizado una jugada, como minimo, se podrá usar la "<<std::endl;
	std::cout<<"\t JUGADA ESPECIAL de volver al pasado para regresar al ultimo estado"<<std::endl;
	std::cout<<"\t de juego que sería tantas como el jugador desee, podría llegar "<<std::endl;
	std::cout<<"\t incluso al estado inicial del juego. "<<std::endl;
	std::cout<<"\t Si se volvio al pasado, como minimo en la jugada anterior, se podra"<<std::endl;
	std::cout<<"\t realizar la JUGADA ESPECIAL de volver al futuro, donde se presenta "<<std::endl;
	std::cout<<"\t varios caminos paralelos de juego, solo si existen."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"• Recuerde que para disfrutar plenamente del juego se"<<std::endl;
	std::cout<<"debe siempre respetar los valores válidos que se deben"<<std::endl;
	std::cout<<"usar al momento de jugar."<<std::endl;

}

void Pantalla::imprimirLinea(){
	std::cout<<"\n--------------------------------------------------"<<std::endl;
}

void Pantalla::imprimirTitulo(){
	this->imprimirLinea();
	std::cout<<"\t.:JUGANDO BUSCAMINAS:.";
	this->imprimirLinea();
}

void Pantalla::imprimirPidiendoDatos(){
	std::cout<<".:PIDIENDO DATOS:."<<std::endl;
}

void Pantalla::comprobarDatos(char dificultad, uint dimFila, uint dimColumna, uint cantJugadores){
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
	
	int numeroDeMinas = (dimFila*dimColumna*dificultadNumerica)/100;
	
	if (numeroDeMinas==0)
		numeroDeMinas = 1;
	
	this->imprimirDatosIngresados(dimFila, dimColumna, dificultadPalabra, numeroDeMinas, cantJugadores);

}

void Pantalla::imprimirDatosIngresados(uint dimFila, uint dimColumna, std::string dificultadPalabra,
										int numeroDeMinas, uint cantJugadores){
	
	std::cout<<".:COMPROBANDO COMANDOS:."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Tamanio de la tabla de BUSCAMINAS: \t\t"<<dimFila<<" X "<<dimColumna<<std::endl;

	std::cout<<"Dificultad pedida: \t\t\t\t.:"<<dificultadPalabra<<":."<<std::endl;
	std::cout<<"Cantidad de MINAS en el BUSCAMINAS: \t\t"<<numeroDeMinas<<std::endl;
	std::cout<<"Cantidad de JUGADORES: \t\t\t\t"<<cantJugadores<<std::endl;
	std::cout<<std::endl;

}

void Pantalla::pedirDimensiones(uint &filaUser, uint &colUser){
	
	std::cout<<std::endl;
	std::cout << "FILAS y COLUMNAS totales para su tablero (ej: 40 60): " << std::endl;
	std::cin >> filaUser >> colUser;
	std::cout<<std::endl;
	
}

char Pantalla::pedirDificultad(){
	char dificultadUser;
	std::cout << "Ingresar dificultad (un caracter): F (facil) / M (medio) / D (dificil):" << std::endl;
	std::cin >> dificultadUser;
	std::cout<<std::endl;
	return dificultadUser;

}

uint Pantalla::pedirCantidadJugadores(){
	uint cantidadUser;
	std::cout << "Ingresar la cantidad de jugadores:" << std::endl;
	std::cin >> cantidadUser;
	std::cout<<std::endl;
	return cantidadUser;
}
