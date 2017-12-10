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

int Pantalla::pedirOpcionRehacerJugada (PseudoGrafo<JugadaLight*>* jugadas ){
	uint contador = 1;
	uint opcionUsuario;
	bool puedeRehacerJugada = true;

	JugadaLight* actual;
        do {
		std::cout<<"jugadas realizadas desde este punto: "<<std::endl;

		this->jugadas->avanzarCursor();
		actual = this->jugadas->obtenerDatoActual();
	
		if(actual == NULL){
			puedeRehacerJugada = false;
		}


		std::cout<<"jugada 1: ";
		std::cout<<"fila: "<<actual->obtenerFila()<<" columna: "<<actual->obtenerColumna()
				<<" opcion: "<<actual->obtenerOpcion()<<std::endl;

		while(this->jugadas->avanzarCursorAParalela()){
			contador++;
			actual=this->jugadas->obtenerDatoActual();
			std::cout<<"jugada "<<contador<<": ";
			std::cout<<"fila: "<<actual->obtenerFila()<<" columna: "<<actual->obtenerColumna()
				<<" opcion: "<<actual->obtenerOpcion()<<std::endl;
		}
		this->jugadas->retrocederCursor();

		std::cout<<std::endl<<"elija una de las jugadas para rehacer"<<std::endl;
		std::cin>>opcionUsuario;

        }while (opcionUsuario < 1|| opcionUsuario > contador);
	
  	return opcionUsuario;
}
void Pantalla::noSePuedeRetroceder (){
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
