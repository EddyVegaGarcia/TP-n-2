/*
 * pantalla.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: marcela
 */

void playGame(){
    std::cout<<".:PLAY GAME::."<<std::endl;

}
char pedirOpcionPasadoFuturo (){
    
   char opcionDeUsuario;

    std::cout<<"VOLVER AL PASADO 'deshacer' (P) || ";
		std::cout<<"VOLVER AL FUTURO 'rehacer' (F) || "<<std::endl;
		std::cout<<"Ya no realizar JUGADA ESPECIAL (N) : "<<std::endl;

		std::cin>>opcionDeUsuario;
    
    return opcionDeUsuario;
 }

int pedirOpcionRehacerJugada (PseudoGrafo<JugadaLight*>* jugadas ){
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
		
        }while (opcionUsuario < 1||opcionUsuario );
    return opcionUsuario;
}
