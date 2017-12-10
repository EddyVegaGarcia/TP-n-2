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
