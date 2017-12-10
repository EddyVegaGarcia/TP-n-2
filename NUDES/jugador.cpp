# include "jugador.h"
# include <iostream>


Jugador::Jugador(char letra, Mapa* punteroAMapa){
	asignarAlias(letra);
	asignarPuntaje(0);
	asignarEstado(SIGUE_JUGANDO);
	inicializarPunteroAJugada(punteroAMapa);
	this->mapa = punteroAMapa;
}


// métodos púbicos
void Jugador::modificarPuntaje(int puntos){
	this->puntaje+=puntos;
}
char Jugador::obtenerAlias(){
	return alias;
}
int Jugador::obtenerPuntaje(){
	return puntaje;
}
int Jugador::obtenerEstado(){
	return this-> estado;
}

// métodos privados
void Jugador::asignarAlias(char letra){
	this->alias=letra;
}

void Jugador::asignarPuntaje(int puntos){
	this->puntaje=puntos;
}

void Jugador::asignarEstado(int estado){
	this->estado=estado;
}
	
	
void Jugador::inicializarPunteroAJugada(Mapa* punteroAMapa){

	this->pJugada = new Jugada(punteroAMapa);
}


bool Jugador::validarOpcionUser( char opcionUser)
{
	return (opcionUser != 'd' && opcionUser != 'D' && opcionUser != 'm' && opcionUser != 'M' && opcionUser != 'r' && opcionUser != 'R');
}

bool Jugador::validarOpcionUserConfirmacion(char opcionUser)
{
	return((opcionUser != 's') && (opcionUser != 'S') && (opcionUser != 'n') && (opcionUser != 'N'));
}


void Jugador::iniciarJugada(){
	uint filaUser, colUser;
	bool quiereModificarJugadas = false;
	char opcionUser;
	int puntos = 0;

	std::cout<<std::endl;
	std::cout << "TURNO JUGADOR: \t"<< this->alias << std::endl;
	std::cout<<std::endl;


	if(this->puntaje>=PUNTAJE_NECESARIO_PARA_JUGADAS_ESPECIALES)
		quiereModificarJugadas = PreguntarSiQuiereModificarJugadas();
	else std::cout<<"Puntaje insuficiente para realizar JUGADAS ESPECIALES"<<std::endl;


	if (quiereModificarJugadas){

		this->asignarEstado(REALIZANDO_CAMBIOS);
	}
	else{
		do{

			std::cout<<"Ingrese fila y columna a jugar: "<<std::endl;
			std::cin>>filaUser>>colUser;
			std::cout<<std::endl;

		} while( (filaUser<1 || filaUser> mapa->obtenerFila()) || (colUser<1 || colUser > mapa->obtenerColumna()));


		do{
			std::cout<<"ingrese 'd' (destapar) || 'm' (marcar) || 'r' retirarse "<<std::endl;
			std::cin >>opcionUser;
			std::cout<<std::endl;
		}while(this->validarOpcionUser(opcionUser));


		this->pJugada->asignarOpcion(opcionUser);
		this->pJugada->asignarFila(filaUser);
		this->pJugada->asignarColumna(colUser);
		puntos = this->pJugada->realizarJugada();

		if (puntos == PERDIO_PARTIDA)
			this->asignarEstado(PERDIO_PARTIDA);
		else if (puntos == SE_RETIRO)
			this->asignarEstado(SE_RETIRO);
		else{
			//puntos += obtenerPuntaje();
			this->modificarPuntaje(puntos);
			this->asignarEstado(SIGUE_JUGANDO);
		}

	}
}

bool Jugador::PreguntarSiQuiereModificarJugadas(){

	char opcionUser;
	do{
		std::cout<<"\t.:JUGADA ESPECIAL:.\t.:DESHACER/REHACER"<<std::endl;
		std::cout<<"Se le restaran "<< COSTO_MODIFICAR << " puntos - CONFIRMAR (S/N) : "<<std::endl;
		std::cin>>opcionUser;
	}while(this->validarOpcionUserConfirmacion(opcionUser));

	return ((opcionUser == 's') || (opcionUser == 'S'));
}

Jugada* Jugador::obtenerPJugada(){

	return this-> pJugada;

}

Jugador::~Jugador(){
        delete pJugada;
}
