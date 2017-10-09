#ifndef MENU_H_
#define MENU_H_

typedef unsigned int uint;

class Menu {
private:
	uint fila;
	uint columna;
	char dificultad;
	int cantJugadores;


	/* constructor
	 * post: crea un objeto menu, inicializa todos sus atributos en cero.*/
	Menu();

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

	/// Inicializar matriz

	/* Pre: recibe una matriz bidimensional
	 * Post: la inicializa.*/
	// void crearAmbiente(char matriz[][]);


public:

	/* Post: devuelve la cantidad de filas */
	uint obtenerFila();

	/* Post: devuelve la cantidad de columnas */
	uint obtenerColumna();

	/* Post: devuelve la dificultad de la partida */
	char obtenerDificultad();

	/* Post: devuelve la cantidad de jugadores de la partida */
	uint obtenerCantJugadores();

};

#endif /* MENU_H_ */
