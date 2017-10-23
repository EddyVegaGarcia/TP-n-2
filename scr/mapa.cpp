# include "mapa.h"
# include "lista.h"


Mapa::Mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){

	this-> dimFila = filaRecibida;
	this-> dimColumna = columnaRecibida;
	this-> dificultad = DificultadRecibida;
	
	crearListaMinasYAsignarPuntero();	
	crearListaCasillasYAsignarPuntero();
	crearListaBanderasYAsignarPuntero();
	
	Minero minero;
	minero.sembrarMinas(this->pMinas);
}

void Mapa::crearListaMinasYAsignarPuntero(){
	Lista<Mina> minas;
	this->pMinas=&minas;
}

void Mapa::crearListaCasillasYAsignarPuntero(){
	Lista<Casilla> casillasDestapadas;
	this->pCasillasDestapadas=&casillasDestapadas;
}

void Mapa::crearListaBanderasYAsignarPuntero(){
	Lista<Bandera> banderas;
	this->pBanderas=&banderas;
}	

void Mapa::mostrarMapa(){

	vector = new unsigned int[this->dimColumna];
	for (unsigned int i=0; i< this->columna; i++)
		vector[i] = 0;

	for (unsigned int i=1; i<= this-> dimFila; i++){

		this-> pCasillasDestapadas -> iniciarCursor();
		
		
		Casilla casillaActual;
		while(this-> pcasillasDestapadas ->avanzarCursor()){

			casillaActual = pCasillasDestapadas -> obtener();

			if (casillaActual.obtenerFila() == i)
				vector[casillaActual.obtenerColumna] = casillaActual.obtenerValor();
		}
		
		this-> pBanderas -> iniciarCursor();
		Bandera banderaActual;
		while(this-> pBanderas ->avanzarCursor()){

			banderaActual = pBanderas -> obtener();

			if (banderaActual.obtenerFila == i)
				vector[banderaActual.obtenerColumna-1] = 9; //9 para la bandera.

		}
		
		// acá habría que ordenar el vector, justo antes de imprimirlo.

		for (unsigned int i = 0; i< this->columna; i++)

			if(vector[i] == 9)
				std::cout<<Bandera<<;
			else if (vector[i] == 0) 
				std::cout<<'*':
			else 
				std::cout<< vector[i];
			std::endl;
	}

void Mapa::agregarCasillaDestapada(int filaRecibida,int colRecibida){

	this-> pMinas-> agregar(pMinas->ultimo); // no se puede hacer pMinas->ultimo
	// ultimo es atributo privado (y no hay metodo obtenerUltimo), qué quieren hacer, agregar el último elemento     a dónde?
	// no sé qué quisieron hacer. Sería así:
	
	/* Casilla casillaPorAgregar;
	* casillaPorAgregar.asignarFila(filaRecibida);
	* casillaPorAgregar.asignarColumna(columnaRecibida);
	* this -> pMinas -> agregar(casillaPorAgregar);
	*/
}

//pre: lista casillas no vacia
//post: devuelve valor de la ultima casilla
char Mapa::obtenerValorCasilla(){

	*Casilla punteroCasilla = this -> pMinas -> obtenerPuntero();
	return *punteroCasilla;

}

Lista<Mina>* Mapa::obtenerPunteroMinas(){
	return this-> pMinas
}

Lista<Casilla>* Mapa::obtenerPunteroMinas(){
	return this-> pCasillasDestapadas;
}

Lista<Bandera>* Mapa::obtenerPunteroBanderas(){
	return this-> pBanderas;

}

bool Mapa::validarMina(unsigned int fila, unsigned int columna){

}
