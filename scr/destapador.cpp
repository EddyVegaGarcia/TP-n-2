#include "destapador.h"


	
//constructor
Destapador::Destapador(Mapa* mapaActual)
{
  this->fila = 0;
  this->columna = 0;
  this->mapa = mapaActual;
  crearListaCasillasYAsignarPuntero();

}

//metodos publicos
uint Destapador::destapar(uint filaJugada,uint columnaJugada)
{
	uint puntaje = 0;
	this->fila = filaJugada;
 	this->columna = columnaJugada;
	puntajeAlDestapar(puntaje); //decía puntajeAlDestapar(*puntaje);
	return puntaje;
}

void Destapador::puntajeAlDestapar(uint &puntaje)
{
	if( !this->mapa->estaDestapadaLaCasilla(this->fila, this->columna))
	{
		char valorCasilla = mapa->obtenerValorCasilla(this->fila, this->columna);
		this->mapa->agregarCasillaDestapada(this->fila, this->columna);

		if(valorCasilla == VACIO)
		{
			destaparPandemia(); /* se puede llamar directamente a destaparPandemiaRecursiva */
		}
		else
		{
			puntaje = destaparCasillaNoVacia(valorCasilla);
		}
	}
	
}

void Destapador::crearListaCasillasYAsignarPuntero()
{
	Lista<Casilla> vacios;
	this->pVacios = &vacios;
}

//metodos privados
void Destapador::destaparPandemia()
{
	bool avanzar = true;
	Casilla vacia_1(this->fila, this->columna, VACIO);
	pVacios->agregar(vacia_1);
	pVacios->iniciarCursor();
	while(pVacios->avanzarCursor() && avanzar){
		Casilla nueva=pVacios->obtenerCursor();
		nueva->destaparEnTablero();
		destaparPandemiaRecursiva(nuevo->seDestapoEnTablero() , this->fila, this->columna);
		avanzar =  false;
	}




}

void Destapador::destaparPandemiaRecursiva(Lista<Casilla>* vacios, uint filaPasada, uint columnaPasada)
{
	
	if((this->mapa->obtenerValorCasilla(filaPasada, columnaPasada) !=VACIO))
		return; /*Ver.*/
	
	destaparPandemiaRecursiva(filaPasada - 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada - 1, columnaPasada); /* Esto se hace siempre con loQueSea que
	* se le pase. Sería un "this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada)" al final (pero con un if
	* para ver que no exista ya).
	* Para mí que sobra el "destaparPandemia()" no es necesario un método 'intermedio'.*/
	
	destaparPandemiaRecursiva(filaPasada + 1, columnaPasada);
	this->mapa->agregarCasillaDestapada(filaPasada + 1, columnaPasada);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada - 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada - 1);
	
	destaparPandemiaRecursiva(filaPasada, columnaPasada + 1);
	this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada + 1);	

}

uint Destapador::destaparCasillaNoVacia(char valorCasilla)
{
	
	uint puntaje = 0;
  	
	if(valorCasilla == MINA)
	{
		puntaje = PERDIO_PARTIDA;	
	}
	
	return puntaje;
	
	
}
