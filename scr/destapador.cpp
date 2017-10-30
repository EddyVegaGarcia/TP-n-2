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
		return; /*Ver.*/
	
	if(!pasoPorAqui(filaPasada - 1, columnaPasada) )
	{
		agregarVacio(filaPasada - 1, columnaPasada);
		pasoPorAqui(filaPasada - 1, columnaPasada);

		destaparPandemiaRecursiva(filaPasada - 1, columnaPasada);

		if( !this->mapa->estaDestapadaLaCasilla(filaPasada - 1, columnaPasada))
			this->mapa->agregarCasillaDestapada(filaPasada - 1, columnaPasada,
											this->mapa->obtenerValorCasilla(filaPasada - 1, columnaPasada));
	}

	if(!pasoPorAqui(filaPasada + 1, columnaPasada) )
	{
		agregarVacio(filaPasada + 1, columnaPasada);
		pasoPorAqui(filaPasada + 1, columnaPasada);

		destaparPandemiaRecursiva(filaPasada + 1, columnaPasada);

		if( !this->mapa->estaDestapadaLaCasilla(filaPasada + 1, columnaPasada))
			this->mapa->agregarCasillaDestapada(filaPasada + 1, columnaPasada,
											this->mapa->obtenerValorCasilla(filaPasada + 1, columnaPasada));
	}

	if(!pasoPorAqui(filaPasada, columnaPasada - 1) )
	{
		agregarVacio(filaPasada, columnaPasada - 1);
		pasoPorAqui(filaPasada, columnaPasada - 1);

		destaparPandemiaRecursiva(filaPasada, columnaPasada - 1);

		if( !this->mapa->estaDestapadaLaCasilla(filaPasada, columnaPasada - 1))
			this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada - 1,
											this->mapa->obtenerValorCasilla(filaPasada, columnaPasada - 1));
	}
	
	if(!pasoPorAqui(filaPasada, columnaPasada + 1) )
	{
		agregarVacio(filaPasada, columnaPasada + 1);
		pasoPorAqui(filaPasada, columnaPasada + 1);

		destaparPandemiaRecursiva(filaPasada, columnaPasada + 1);

		if( !this->mapa->estaDestapadaLaCasilla(filaPasada, columnaPasada + 1))
			this->mapa->agregarCasillaDestapada(filaPasada, columnaPasada + 1,
											this->mapa->obtenerValorCasilla(filaPasada, columnaPasada + 1));
	}
	
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
