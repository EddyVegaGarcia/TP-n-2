#ifndef MENU_H_
#define MENU_H_

# include "mapa.h"
# include "juez.h"

# include "pantalla.h"
# include "constantes.h"

class Menu {
private:
	uint dimFila;
	uint dimColumna;
	char dificultad;
	uint cantJugadores;
	
	
	/* Pre: Recibe una fila dentro del rango válido.
  	 * Post: Asigna la fila pasada como parámetro al Menu.*/
	void asignarFila(uint fila);

	/* Pre: Recibe una columna dentro del rango válido.
	 * Post: Asigna la columna pasada como parámetro al Menu.*/
	void asignarColumna(uint columna);


	/* Pre: Recibe una dificultad válida, es decir, "F" (fácil), "M" (media) o "D" (difícil).
	 * Post: Asigna la dificultad pasada como parámetro al Menu.*/
	void asignarDificultad(char dificultad);

	/* Pre: Recibe una cantidad de jugadores.
	 * Post: Asigna la cantidad de jugadores pasada como parámetro al Menu.*/
	void asignarCantJugadores(uint cantJugadores);

	/// interacción con user.

	/* post: pide a user las dimensiones del tablero de juego y las asigna. */
	void pedirYAsignarDimensiones();

	/* post: pide a user la dificultad y la asigna. */
	void pedirYAsignarDificultad();

	/* post: pide a user la cantidad de jugadores y la asigna. */
	void pedirYAsignarCantJugadores();

	/* Post: devuelve la cantidad de filas del tablero de juego.*/
	uint obtenerFila();

	/* Post: devuelve la cantidad de columnas del tablero de juego.*/
	uint obtenerColumna();

	/* Post: devuelve la dificultad de la partida.*/
	char obtenerDificultad();

	/* Post: devuelve la cantidad de jugadores de la partida.*/
	uint obtenerCantJugadores();
	
	/* Post: pide opciones por pantalla al usuario.*/
	void pedirOpcionesDeJuegoAUser();


public:
	
	/* Post: Crea un objeto Menu, crea un objeto mapa pidiendo las opciones por pantalla al usuario y pasa su puntero a
	 * un nuevo objeto Juez.*/
	Menu();

	void menuPrincipal();

	/* Pre: Se llamò al mètodo pedirOpcionesDeJuegoAUser().
	 * Post: Crea un objeto Mapa con los datos ya obtenidos del usuario, y pasa su puntero a un nuevo objeto Juez.*/
	void crearAmbiente();
	
};

#endif /* MENU_H_ */
