#include "destapador.h"

using namespace std;
	
//constructor
Destapador::Destapador (Mapa* mapaActual)
{
  this->mapa = mapaActual;
  this->fila = 0;
  this->columna = 0;  
}

//metodos publicos
int Destapador::destapar(int filaJugada, int columnaJugada) 
{
	int puntaje = 0;
	this->fila = filaJugada;
 	this->columna = columnaJugada;
	puntajeAlDestapar(puntaje); //decía puntajeAlDestapar(*puntaje);
	return puntaje;
}

void Destapador::puntajeAlDestapar(int &puntaje)
{
	if( !this->mapa->estaDestapadaLaCasilla(this->fila , this->columna )){
		char valorCasilla = mapa->obtenerValorCasilla();
		mapa->agregarCasillaDestapada(this->fila, this->columna, valorCasilla);
		if(valorCasilla == VACIO)
		{
			destaparPandemia();
		}
		else
		{
			puntaje = destaparCasillaNoVacia(valorCasilla);
		}
	}
	
}

//metodos privadas
void Destapador::destaparPandemia()
{
	destaparPandemiaRecursiva(this->fila, this->columna);
	this->mapa->agregarCasillaDestapada(this->fila, this->columna);
}

void Destapador::destaparPandemiaRecursiva(int filaPasada, int columnaPasada)
{
	
	if(this->mapa->obtenerValorCasilla!=VACIO || this->mapa->estaDestapadaLaCasilla(filaPasada, columnaPasada))
		return; /*Ver.*/
	
	destaparPandemiaRecursiva(filaPasada - 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada - 1, columnaPasada); /* Esto se hace siempre con loQueSea que
	* se le pase. Sería un "this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada)" al final,
	* para mí que sobra el "destaparPandemia()" no es necesario un método 'intermedio'.*/
	
	destaparPandemiaRecursiva(filaPasada + 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada + 1, columnaPasada);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada - 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada - 1);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada + 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada + 1);	

}

int Destapador::destaparCasillaNoVacia(char valorCasilla)
{
	
	int puntaje = 0;
  	
	if(valorCasilla == MINA)
	{
		puntaje = PERDIO_PARTIDA;	
	}
	
	return puntaje;
	
	
}
