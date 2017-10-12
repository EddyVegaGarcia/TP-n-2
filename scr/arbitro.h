


#ifndef ARBITRO_H_
#define ARBITRO_H_

typedef char jugador;

class Arbitro{

private:

	char* listaJugadores; //podria ser *string, tendriamos que ver bien eso

public:
	
	//constructor default, apunta a una lista de un solo jugador
	Arbitro();
	
	//constructor con parámetro
	Arbitro(int cantidadJugadores);
	
	//pre: jugador no repetido
	//post: 
	void asignarJugadores;
	
	//pre:
	//post: avanza el turno al jugador siguiente
	void avanzarJugador();
	
	//pre:
	//post: verifica si el respectivo jugador gano la partida
	bool haGanado(Jugador aVerificar);
	
	//pre:
	//post: muestra por pantalla al jugador en turno
	void mostrarJugador;
	
	//pre:
	//post: elimina al jugador en turno
	void eliminarJugador;

};



#endif /* ARBITRO_H_ */
