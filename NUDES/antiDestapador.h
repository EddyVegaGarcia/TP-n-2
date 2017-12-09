#ifndef ANTIDESTAPADOR_H_
#define ANTIDESTAPADOR_H_

# include "mapa.h"
# include "jugador.h"
# include "constantes.h"


class AntiDestapador{

private:
	Jugador* jugador;
	unsigned int fila;
	unsigned int columna;
	int puntaje;
	Mapa* mapa;

public:

	AntiDestapador(Mapa* mapaActual, Jugador* jugador);

	uint tapar(uint filaJugada,uint columnaJugada);

	int puntajeAltapar();

	void crearListaCasillasYAsignarPuntero();

	bool validarUbicacion(uint fila, uint columna);

	uint taparCasillaNoVacia(char ValorCasilla);

	void taparPandemia();

};

#endif /* ANTIDESTAPADOR_H_ */
