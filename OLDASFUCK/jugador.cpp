

# include "jugador.h"
# include <iostream>



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


// constructor, inicializar
Jugador::Jugador(char letra, Mapa* punteroAMapa){
	asignarAlias(letra);
	asignarPuntaje(0);
	asignarEstado(SIGUE_JUGANDO);
	inicializarPunteroAJugada(punteroAMapa);
	this->mapa = punteroAMapa;
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
	//Jugada jugada(punteroAMapa);
	//this->pJugada=&jugada;

	this->pJugada = new Jugada(punteroAMapa);
}

/*
bool Jugador::validarOpcionUser( char opcionUser)
{
	return (opcionUser != 'd' || opcionUser != 'D' || opcionUser != 'm' || opcionUser != 'M' || opcionUser != 'r' || opcionUser != 'R');
}

bool Jugador::validarOpcionUserTiempo(char opcionUser)
{
	return(opcionUser != 'f' || opcionUser != 'F' || opcionUser != 'p' || opcionUser != 'P');
}

char Jugador::pedirOpcionUser()
{
	char opcionUser;
	
	if(pListaJugada==NULL)
	{
		do{
			std::cout<<"ingrese 'd' (destapar) || 'm' (marcar) || 'r' retirarse "<<std::endl;
			std::cin >>opcionUser;
		}while(validarOpcionUser());
	}
	
	else if(validarVAP())
	{
		do{
			std::cout<<"ingrese 'd' (destapar) || 'm' (marcar) || 'r' (retirarse) "<<std::endl;
			std::cout<<" || ´p´ (quitar jugada anterior) || 'f' (volver a colocar jugada eliminada)"<<std::endl;
			std::cin >>opcionUser;
		}while(validarOpcionUser() || validarOpcionUserTiempo());
	}
	
	else
	{
		do{
			std::cout<<"ingrese 'd' (destapar) || 'm' (marcar) || 'r' (retirarse) "<<std::endl;
			std::cout<<" || ´p´ (quitar jugada anterior)"<<std::endl;
			std::cin >>opcionUser;
		}while(validarOpcionUser() || validarOpcionUserTiempo());
	}
	
	return opcionUser;
}
*/

void Jugador::iniciarJugada(){
	uint filaUser, colUser;
	bool quiereModificarJugadas = false;
	char opcionUser;
	int puntos = 0;

	std::cout<<std::endl;
	std::cout << "TURNO JUGADOR: \t"<< this->alias << std::endl;

	quiereModificarJugadas = PreguntarSiQuiereModificarJugadas();

	if (quiereModificarJugadas){

		this->asignarEstado(REALIZANDO_CAMBIOS);
	}
	else{
		do{

			std::cout<<"Ingrese fila y columna a jugar: "<<std::endl;
			std::cin>>filaUser>>colUser;
			std::cout<<std::endl;

		} while( (filaUser<1 || filaUser> mapa->obtenerFila()) || (colUser<1 || colUser > mapa->obtenerColumna()));

		/*
		opcionUser = pedirOpcionUser();
		*/
		std::cout<<"ingrese 'd' (destapar) || 'm' (marcar) || 'r' retirarse "<<std::endl;
		std::cin >>opcionUser;
		std::cout<<std::endl;

		// validar // debug // ver

		this->pJugada->asignarOpcion(opcionUser);

		this->pJugada->asignarFila(filaUser);

		this->pJugada->asignarColumna(colUser);

		puntos = this->pJugada->realizarJugada();

		if (puntos == PERDIO_PARTIDA)
			this->asignarEstado(PERDIO_PARTIDA);
		else if (puntos == SE_RETIRO)
			this->asignarEstado(SE_RETIRO);
		else{
			puntos += obtenerPuntaje();
			this->modificarPuntaje(puntos);
			this->asignarEstado(SIGUE_JUGANDO);
		}
	}
}

bool Jugador::PreguntarSiQuiereModificarJugadas(){

	char opcionUser;

	std::cout<<"ingrese 's' si quiere utilizar sus puntos en deshacer/rehacer jugadas"<<std::endl;
	std::cout<<"ingrese cualquier otra tecla para realizar cambios en el tablero"<<std::endl;

	std::cin>>opcionUser;

	return ((opcionUser == 's') || (opcionUser == 'S'));
}

Jugada* Jugador::obtenerPJugada(){

	return this-> pJugada;

}

Jugador::~Jugador(){
        delete pJugada;
}

