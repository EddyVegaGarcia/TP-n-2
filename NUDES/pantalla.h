#ifndef PANTALLA_H_
#define PANTALLA_H_

# include "pseudoGrafo.h"
# include "jugadaLight.h"
# include "constantes.h"
# include <iostream>

class Pantalla{
  
public:  

  void playGame();

  char pedirOpcionPasadoFuturo();

  int pedirOpcionRehacerJugada (PseudoGrafo<JugadaLight*>* jugadas);

  void noSePuedeRetroceder();

  void mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual);

  void terminoLaPartida();

  void noHayJugadas();


  char imprimirOpcionesDeMenu();

  void imprimirReglasDeJuego();

  void imprimirLinea();

  void imprimirTitulo();

  void imprimirPidiendoDatos();

  void imprimirDatosIngresados();

  char pedirDificultad();

  uint pedirCantidadJugadores();
  
};

#endif



