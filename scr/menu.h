#ifndef MENU_H_
#define MENU_H_

# include "mapa.h"
# include "juez.h"

typedef unsigned int uint;

class Menu {
private:
	uint dimFila;
	uint dimColumna;
	char dificultad;
	uint cantJugadores;

	/* post: asigna "fil" al atributo fila */
	void asignarFila(uint fil);

	/* post: asigna "col" al atributo columna */
	void asignarColumna(uint col);

	/* post: asigna "dif" al atributo dificultad */
	void asignarDificultad(char dif);

	/* post: asigna "cant" al atributo cantJugadores */
	void asignarCantJugadores(uint cant);

	/// interacción con user.

	/* post: pide a user las dimensiones y las asigna. */
	void pedirYAsignarDimensiones();

	/* post: pide a user la dificultad y la asigna. */
	void pedirYAsignarDificultad();

	/* post: pide a user la cantidad de jugadores y la asigna. */
	void pedirYAsignarCantJugadores();

	/* Post: devuelve la cantidad de filas */
	uint obtenerFila();

	/* Post: devuelve la cantidad de columnas */
	uint obtenerColumna();

	/* Post: devuelve la dificultad de la partida */
	char obtenerDificultad();

	/* Post: devuelve la cantidad de jugadores de la partida */
	uint obtenerCantJugadores();
	

	/* Pre: Se llamò al mètodo pedirOpcionesDeJuegoAUser().
	 * Post: Crea un objeto mapa con los datos ya obtenidos del usuario, y pasa su puntero a un nuevo objeto juez.*/
	void crearAmbiente();
	
	/* Pre:
	* Post: pide opciones por pantalla al usuario.*/
	void pedirOpcionesDeJuegoAUser();


public:
	
	/* Constructor
	 * post: crea un objeto menu, crea un objeto mapa pidiendo las opciones por pantalla al usuario y pasa su puntero a
	 * un nuevo objeto juez.*/
	Menu();


};

#endif /* MENU_H_ */
