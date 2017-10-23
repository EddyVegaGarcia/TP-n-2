# include "mapa.h"

Mapa::Mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){

	this-> dimFila = filaRecibida;
	this-> dimColumna = columnaRecibida;
	this-> dificultad = DificultadRecibida;
	
	crearListaMinasYAsignarPuntero();	
	crearListaCasillasYAsignarPuntero();
	crearListaBanderasYAsignarPuntero();
	
	Minero minero(dimFila,dimColumna,dificultad,pMinas);
	minero.sembrarMinas();
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


Lista<Mina>* Mapa::obtenerPunteroMinas(){
	return this-> pMinas
}

Lista<Casilla>* Mapa::obtenerPunteroMinas(){
	return this-> pCasillasDestapadas;
}

Lista<Bandera>* Mapa::obtenerPunteroBanderas(){
	return this-> pBanderas;
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

/*Método que estaba en "Minas" (un poco cambiado), xq "Minas" es una clase que no existe más.*/
char Mapa::calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla){
	char valor = '0';
	pMinas->iniciarCursor();
	
	Mina minaActual;
	if (pMinas->avanzarCursor)
		minaActual = pMinas->ObtenerCursor();
	
	if (minaActual.esMina(filaCasilla, columnaCasilla)){
		valor = MINA;
	} else {
		while(pMinas->avanzarCursor() && !minaActual.esMina(filaCasilla, columnaCasilla) && valor < '9'){
			Mina minaActual = pMinas->ObtenerCursor();
			if(minaActual.estaJuntoAMina(filaCasilla , columnaCasilla))
				valor++;
		}
	
	return valor;
}

/* esto tiene que ser char, calculo el valor acá, no tiene sentido pasarselo a otro método que solo lo devuelva
* antes habían dicho de separalo en dos pero xq un método la iba a agregar, se iba a calcular el valor
* y dsp otro método iba a obtener ese valor. Ahora calculamos el valor acá, ya se agrega con el valor calculado,
* tiene sentido que este método sea char si ya tiene el valor que va a devolver.*/
char Mapa::agregarCasillaDestapada(int filaRecibida,int columnaRecibida){
	char valor='0';
	valor=this->calcularValorDeCasilla(filaRecibida,columnaRecibida);
	Casilla casillaPorAgregar(filaRecibida, columnaRecibida, valor);
	this -> pMinas -> agregar(casillaPorAgregar);
	return valor;
}

//pre: lista casillas no vacia
//post: devuelve valor de la ultima casilla
/* Ahora que agregarCasillaDestapada devuelve char, este método sobra.*/
char Mapa::obtenerValorCasilla(){
	*Casilla punteroCasilla = this -> pMinas -> obtenerPuntero();
	return *punteroCasilla;
/*(Arriba es "Casilla*"). (Sería punteroCasilla->obtenerValor(), para q dev char. Igual ya lo puede hacer el otro método.*/
}
	
void Mapa::colocarMarca(int filaRecibida,int columnaRecibida){
	Bandera banderaAColocar(filaRecibida, columnaRecibida);
	this -> pBanderas -> agregar(banderaAColocar);
}

//////////////////////////////////////////////////////////
/////// Métodos en construccin ///////////////////////////
//////////////////////////////////////////////////////////

/* De alguna forma se debería llamar al remover ya con la posición.*/

/* en destapador dicen if validarMarca (o sea si está en la lista de banderas) entonces removerMarca.
* Se estaría recorriendo dos veces. Si yo ya encontré la posición cuando me preguntaron si estaba o no, debería poder
* llamar al remover marca ya con la posicin para no hacerlo buscar de nuevo.*/
void Mapa::removerMarca(uint filaRecibida, uint columnaRecibida){
	uint posicion;
	posicion=obtenerPosicionDeMarca(pBanderas, filaRecibida, columnaRecibida); // ya debería tener la posición
	pBanderas->remover(posicion);
}

uint Mapa::obtenerPosicionDeMarca(Lista<Bandera>* pBanderas, uint filaRecibida, uint columnaRecibida){
}
	

/*validarMina, estaDestapadaLaCasilla, validarMarca. Hay que buscar en las listas*/
bool Mapa::validarMina(unsigned int fila, unsigned int columna){
}

bool Mapa::estaDestapadaLaCasilla(unsigned int fila, unsigned int columna){
}
	
bool Mapa::validarMarca(unsigned int fila, unsigned int columna){
}
