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
		this->mapa->agregarCasillaDestapada(this->fila, this->columna, valorCasilla);

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

void Destapador::crearListaCasillasYAsignarPuntero()
{
	Lista<Casilla> vacios;
	this->pVacios = &vacios;
}

//metodos privados
void Destapador::destaparPandemia()
{
	agregarVacio(this->fila, this->columna);
	pVacios->iniciarCursor();
	pVacios->avanzarCursor();

	Casilla nueva=pVacios->obtenerCursor();
	nueva.destaparEnTablero();
	destaparPandemiaRecursiva( this->fila, this->columna);

}

void Destapador::agregarVacio(uint filaPasada, uint columnaPasada)
{
	Casilla vacia_n( filaPasada, columnaPasada, VACIO);
	this->pVacios->agregar(vacia_n);
}


bool Destapador::pasoPorAqui(uint filaPasada, uint columnaPasada)
{
	bool paso=false;
	this->pVacios->iniciarCursor();
	while(this->pVacios->avanzarCursor()){
		Casilla nueva= this->pVacios->obtenerCursor();
		if(nueva.obtenerFila() == filaPasada && nueva.obtenerColumna() == columnaPasada)
		{
			nueva.destaparEnTablero();
			paso = nueva.seDestapoEnTablero();
		}
	}
	return paso;
}

void Destapador::destaparPandemiaRecursiva( uint filaPasada, uint columnaPasada)
{
	
	if((this->mapa->obtenerValorCasilla(filaPasada, columnaPasada) !=VACIO))
		return; 
	
	uint avanzar = 1;

	while(avanzar < 5)
	{

		avanzarPandemia(avanzar, filaPasada, columnaPasada);

		if(!pasoPorAqui(filaPasada, columnaPasada) )
		{
			agregarVacio(filaPasada, columnaPasada);
			pasoPorAqui(filaPasada, columnaPasada);

			destaparPandemiaRecursiva(filaPasada, columnaPasada);

			if( this->mapa->estaDestapadaLaCasilla(filaPasada, columnaPasada))
				this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada,
												this->mapa->obtenerValorCasilla(filaPasada, columnaPasada));
		}

		avanzar++;

	}
	

}

void avanzarPandemia(int avanzarNueva, uint &filaPasada, uint &columnaPasada)
{
	
		if(avanzarNueva == 1)
			filaPasada--;
		else if(avanzarNueva == 2)
			filaPasada++;
		else if(avanzarNueva == 3)
			columnaPasada--;
		else
			columnaPasada++;
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

Destapador::~Destapador()
{
	for(uint i = 1; i < this->pVacios->contarElementos()+1; i++){
		this->pVacios->remover(i);
	}
}
