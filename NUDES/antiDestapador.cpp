#include "antiDestapador.h"

AntiDestapador::AntiDestapador(Mapa* mapaActual,Jugador* jugador){
  this->fila = 0;
  this->columna = 0;
  this->puntaje = 0;
  this->mapa = mapaActual;
  this->jugador = jugador;

}

uint AntiDestapador::tapar(uint filaJugada,uint columnaJugada)
{
	uint puntaje = 0;
	this->fila = filaJugada;
 	this->columna = columnaJugada;
	puntaje = this->puntajeAltapar();
	return puntaje;
}

int AntiDestapador::puntajeAltapar()
{
	int puntaje=0;
	if(this->mapa->estaDestapadaLaCasilla(this->fila, this->columna))
	{
		char valorCasilla = mapa->obtenerValorCasilla(this->fila, this->columna);

		if(valorCasilla == VACIO)
		{
			taparPandemia();
		}
		else if(valorCasilla==MINA)
		{
			this->jugador->asignarEstado(SIGUE_JUGANDO);
			this->mapa->eliminarCasillaDestapada(this->fila, this->columna);
			puntaje = taparCasillaNoVacia(valorCasilla);
		}
	}
	return puntaje;
}

bool AntiDestapador::validarUbicacion(uint fila, uint columna){

	bool ubicacionValida = true;
	uint dimensionFila = this->mapa->obtenerFila();
	uint dimensionColumna = this->mapa->obtenerColumna();
	if(fila<0 || fila>dimensionFila || columna < 0 || columna>dimensionColumna){
		ubicacionValida = false;
	}
	return ubicacionValida;
}
void AntiDestapador::taparPandemia(){

  this->mapa->eliminarCasillasDestapadasDesde(this->fila,this->columna);

}

uint AntiDestapador::taparCasillaNoVacia(char valorCasilla)
{

	uint puntaje = 0;

	if(valorCasilla == MINA)
	{
		puntaje = PERDIO_PARTIDA;
	}

	return puntaje;


}
