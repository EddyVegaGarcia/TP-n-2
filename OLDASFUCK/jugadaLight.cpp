/*
 * jugadaLight.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: ghost
 */




#include "jugadaLight.h"


using namespace std;

	JugadaLight::JugadaLight(char opcion, char jugador, int fila, int columna){

		this->fila = fila;
		this->columna = columna;
		this->jugador = jugador;
		this->opcion=opcion;
	}

	int JugadaLight::obtenerFila(){
			return this->fila;
		}
		int JugadaLight::obtenerColumna(){
			return this->columna;
		}
		char JugadaLight::obtenerOpcion(){
			return this->opcion;
	}
		char JugadaLight::obtenerJugador(){
			return this->jugador;
		}

	void JugadaLight::asignarOpcion(char opcionDeUsuario){

		this->opcion = opcionDeUsuario;


	}

	void JugadaLight::asignarFila(int filaDeUsuario){

		this->fila = filaDeUsuario;

	}

	void JugadaLight::asignarColumna(int columnaDeUsuario){

		this->columna = columnaDeUsuario;

	}
    void JugadaLight::asignarJugador(char jugador){

    	this->jugador = jugador;
    }


	 bool JugadaLight::operator == ( JugadaLight b)  {
		bool sonIguales = false;
		 	if((this->fila == b.obtenerFila())&&(this->columna == b.obtenerColumna())&&
		 			     					(this->opcion == b.obtenerOpcion())){
		 		sonIguales = true;

		}
	   	return sonIguales;
}
