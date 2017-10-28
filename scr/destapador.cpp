

#include "destapador.h"
#include "constantes.h"

using namespace std;

		
//constructor
Destapador::Destapador (mapa* mapaActual)
{

  this->mapa = mapaActual;
  this->fila = 0
  this->columna = 0
  
  
  
}

//metodos publicos
int Destapador::destapar(int filaJugada, int columnaJugada) 
{
	int puntaje = 0;
	this->fila =  filaJugada;
 	this->columna = columnaJugada;
	puntajeAlDestapar(*puntaje);
	return  puntaje;
}


void Destapador::puntajeAlDestapar(int &puntaje)
{
	if(!this->mapa->estaDestapadaLaCasilla(this->fila , this->columna )){
		char valorCasilla = mapa->obtenerValorCasilla();
		mapa->agregarCasillaDestapada(this->fila, this->columna, valorCasilla);
		if(valorCasilla == VACIO)
		{
			destaparPandemia();
		}
		else
		{
			puntaje  = destaparCasillaNoVacia(valorCasilla);
		}
	}
	
}
//metodos privadas
void Destapar::destaparPandemia()
{
	destaparPandemiaRecursiva(this->fila, this->columna);
	this->mapa->agregarCasillaDestapada(this->fila, this->columna);
}

void Destapar::destaparPandemiaRecursiva(int filaPasada, int columnaPasada)
{
	
	if(this->mapa->obtenerValorCasilla!=VACIO || this->mapa->estaDestapadaLaCasilla(filaPasada, columnaPasada))
		return;
	
	destaparPandemiaRecursiva(filaPasada - 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada - 1, columnaPasada);
	
	destaparPandemiaRecursiva(filaPasada + 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada + 1, columnaPasada);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada - 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada - 1);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada + 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada + 1);	

}

int Destapar::destaparCasillaNoVacia(char valorCasilla)
{
	
	int puntaje = 0;
  	
	if(valorCasilla == MINA)
	{
		puntaje = PERDIO_PARTIDA;	
	}
	
	return puntaje;
	
	
}
