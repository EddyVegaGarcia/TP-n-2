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
	puntaje = this->puntajeAlDestapar(); //decía puntajeAlDestapar(*puntaje);
	return puntaje;
}

int Destapador::puntajeAlDestapar()
{
	int puntaje=0;
	if( !this->mapa->estaDestapadaLaCasilla(this->fila, this->columna))
	{
		char valorCasilla = mapa->obtenerValorCasilla(this->fila, this->columna);

		if(valorCasilla == VACIO)
		{
			destaparPandemia();
		}
		else
		{
			this->mapa->agregarCasillaDestapada(this->fila, this->columna, valorCasilla);
			puntaje = destaparCasillaNoVacia(valorCasilla);
		}
	}
	return puntaje;
}

void Destapador::crearListaCasillasYAsignarPuntero()
{
	//Lista<Casilla> vacios;
	//this->pVacios = &vacios;
	this->pVacios=new Lista<Casilla>;
}

//metodos privados
bool Destapador::validarUbicacion(uint fila, uint columna){
	bool ubicacionValida = true;
	uint dimensionFila = this->mapa->obtenerFila();
	uint dimensionColumna = this->mapa->obtenerColumna();
	if(fila<0 || fila>dimensionFila || columna < 0 || columna>dimensionColumna){
		ubicacionValida = false;
	}
	return ubicacionValida;
}
void Destapador::destaparPandemia(){

	//this-> pVacios = new Lista<Casilla>;

	pandemia(this->fila,this->columna);

}

void Destapador::pandemia(uint fila, uint columna){

	char valorCasilla = mapa->obtenerValorCasilla(fila,columna);

	if(valorCasilla!= MINA){

		if(! pasoPorAqui(fila,columna)){

			Casilla nueva(fila,columna,mapa->obtenerValorCasilla(fila,columna));

			this->mapa->agregarCasillaDestapada(fila,columna,mapa->obtenerValorCasilla(fila,columna));
			this->pVacios->agregar(nueva);

			if(valorCasilla == VACIO){

				if (fila!=1 && columna!=1)
					pandemia(fila-1,columna-1);
				if (fila!=1)
					pandemia(fila-1,columna);
				if(fila!=1 && columna!= mapa->obtenerColumna())
					pandemia(fila-1,columna+1);
				if(columna!=1)
					pandemia(fila,columna-1);
				if(columna!= mapa->obtenerColumna())
					pandemia(fila,columna+1);
				if(fila!=mapa->obtenerFila() && columna!=1)
					pandemia(fila+1,columna-1);
				if(fila!=mapa->obtenerFila())
					pandemia(fila+1,columna);
				if(fila!=mapa->obtenerFila() && columna!=mapa->obtenerColumna())
					pandemia(fila+1,columna+1);
			}
		}
	}
}

void Destapador::agregarVacio(uint filaPasada, uint columnaPasada)
{
	if(validarUbicacion(filaPasada, columnaPasada)){
		Casilla vacia_n( filaPasada, columnaPasada, VACIO);
		this->pVacios->agregar(vacia_n);
	}
}


bool Destapador::pasoPorAqui(uint filaPasada, uint columnaPasada){

	bool paso=false;

	Casilla aVerificar(filaPasada,columnaPasada,0);
	Casilla actual;

	this->pVacios->iniciarCursor();

	while(this->pVacios->avanzarCursor() && !paso){ //verifica si esta celda ya fue desbloqueda como parte de la pandemia

		actual=pVacios->obtenerCursor();

		if(actual.obtenerFila() == aVerificar.obtenerFila() &&
				actual.obtenerColumna() == aVerificar.obtenerColumna()){

			paso = true;
		}


	}
	if(!paso){ //verifica si esta celda ya fue desbloqueada en algun turno anterior
		Casilla yaDesbloqueada;
		Lista<Casilla>* casillasDesbloqueadas = this->mapa->obtenerPunteroCasillas();

		casillasDesbloqueadas->iniciarCursor();
		while(casillasDesbloqueadas->avanzarCursor() && !paso){

			yaDesbloqueada = casillasDesbloqueadas->obtenerCursor();

			if(yaDesbloqueada.obtenerFila() == aVerificar.obtenerFila() &&
				yaDesbloqueada.obtenerColumna() == aVerificar.obtenerColumna())
				paso = true;
		}
	}
return paso;
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
	delete pVacios;
}
