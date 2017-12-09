/*
 * antiDestapador.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ghost
 */

#ifndef ANTIDESTAPADOR_H_
#define ANTIDESTAPADOR_H_

# include "mapa.h"


class AntiDestapador{

private:

	unsigned int fila;
	unsigned int columna;
	int puntaje;
	Mapa* mapa;

public:

	AntiDestapador(Mapa* mapaActual);

	uint tapar(uint filaJugada,uint columnaJugada);

	int puntajeAltapar();

	void crearListaCasillasYAsignarPuntero();

	bool validarUbicacion(uint fila, uint columna);

	uint taparCasillaNoVacia(char ValorCasilla);

	void taparPandemia();

};

#endif /* ANTIDESTAPADOR_H_ */
