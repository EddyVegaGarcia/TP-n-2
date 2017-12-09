# include "mapa.h"


Mapa::Mapa(uint filaRecibida, uint columnaRecibida, char dificultadRecibida){

	this-> dimFila = filaRecibida;
	this-> dimColumna = columnaRecibida;
	this-> dificultad = dificultadRecibida;

	crearListaMinasYAsignarPuntero();
	crearListaCasillasYAsignarPuntero();
	crearListaBanderasYAsignarPuntero();

	Minero minero(dimFila,dimColumna,dificultad,pMinas);
	minero.sembrarMinas();

	diseniador.modificarCantidadDeFilas(filaRecibida);
	diseniador.modificarCantidadDeColumnas(columnaRecibida);
	diseniador.crearDisenioBase();
}

Mapa::~Mapa(){

	delete pMinas;
	delete pCasillasDestapadas;
	delete pBanderas;
}

uint Mapa::obtenerFila(){
	return this->dimFila;
}
uint Mapa::obtenerColumna(){
	return this->dimColumna;
}
char Mapa::obtenerDificultad(){
	return this->dificultad;
}

uint Mapa::obtenerTamanioDeLaListaDeMinas(){
	return (uint)this->pMinas->contarElementos();
}

uint Mapa::obtenerCantidadDeCasillasOcultas(){
	uint casillasTotales= (this->dimFila)*(this->dimColumna);
	uint casillasYaDestapadas=(uint)pCasillasDestapadas->contarElementos();
	return casillasTotales-casillasYaDestapadas;
}

 unsigned int calcularAncho(unsigned int dimColumnas){

	 unsigned int ancho = 0;
	 ancho = (CELDAS * dimColumnas) + (2 * BORDES);
	 return ancho;

 }

unsigned int calcularAlto(unsigned int dimFilas){

	unsigned int alto =0;
	alto = (CELDAS * dimFilas) + (2 * BORDES);
	return alto;

}




void Mapa::crearListaMinasYAsignarPuntero(){

	this->pMinas= new Lista<Mina>;
}

void Mapa::crearListaCasillasYAsignarPuntero(){

	this->pCasillasDestapadas= new Lista<Casilla>;
}

void Mapa::crearListaBanderasYAsignarPuntero(){

	this->pBanderas= new Lista<Bandera>;
}


Lista<Mina>* Mapa::obtenerPunteroMinas(){
	return this-> pMinas;
}

Lista<Casilla>* Mapa::obtenerPunteroCasillas(){
	return this-> pCasillasDestapadas;
}

Lista<Bandera>* Mapa::obtenerPunteroBanderas(){
	return this-> pBanderas;

}

void Mapa::llenarMapaBanderas(Lista<Bandera>* banderas){

	banderas->iniciarCursor();
	while(banderas->avanzarCursor()){

		Bandera banderaActual;
		banderaActual = banderas->obtenerCursor();

		if(!banderaActual.seDestapoEnTablero()){
			this->diseniador.cambiarEnBMP(BANDERA, banderaActual.obtenerFila(),
				                          banderaActual.obtenerColumna());

		}
	}

}

void Mapa::llenarMapaCasillasDestapadas(Lista<Casilla>* casillas){

       casillas->iniciarCursor();
       while(casillas->avanzarCursor()){
			Casilla casillaActual;
			casillaActual = casillas->obtenerCursor();
			if(!casillaActual.seDestapoEnTablero()){
				char valor;
				valor = casillaActual.obtenerValor();
				this->diseniador.cambiarEnBMP(valor, casillaActual.obtenerFila(),
											  casillaActual.obtenerColumna());
			}
	   }
}
void Mapa::mostrarMapa(){


	this->diseniador.crearDisenioBase();
	llenarMapaBanderas(this->pBanderas);
	llenarMapaCasillasDestapadas(this->pCasillasDestapadas);

	this->diseniador.escribirDisenio();
}

char Mapa::calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla){
	char valor = '0';
	pMinas->iniciarCursor();

	Mina minaActual;

	do{
		minaActual = pMinas->obtenerCursor();
		if(minaActual.estaJuntoAMina(filaCasilla,columnaCasilla))
			valor++;
	}while(pMinas->avanzarCursor() && !minaActual.esMina(filaCasilla,columnaCasilla) && (valor<'9'));

	if(minaActual.esMina(filaCasilla,columnaCasilla)){

		valor = MINA;
	}

	return valor;
}

void Mapa::agregarCasillaDestapada(int filaRecibida,int columnaRecibida,char valorRecibido){
	Casilla casillaPorAgregar(filaRecibida, columnaRecibida, valorRecibido);
	this -> pCasillasDestapadas -> agregar(casillaPorAgregar);
}

char Mapa::obtenerValorCasilla(int filaRecibida,int columnaRecibida){
	char valor=this->calcularValorDeCasilla(filaRecibida,columnaRecibida);
	return valor;
}

void Mapa::colocarMarca(int filaRecibida,int columnaRecibida){
	Bandera banderaAColocar(filaRecibida, columnaRecibida);
	this -> pBanderas -> agregar(banderaAColocar);
}

bool Mapa::removerYDevolverSiHabiaMarca(unsigned int fila, unsigned int columna){
	uint posicion=0;

	Buscador<Bandera> buscador(this->pBanderas);
	bool seEncuentra=buscador.buscar(fila, columna, posicion);

	if (seEncuentra){
		pBanderas->remover(posicion);
		this->diseniador.cambiarEnBMP(DESMARCAR,fila,columna);
    }

	return seEncuentra;
}

bool Mapa::validarMina(unsigned int fila, unsigned int columna){

	uint posicion=0;
	Buscador<Mina> buscador (this->pMinas);
	bool seEncuentra=buscador.buscar(fila, columna, posicion);
	return seEncuentra;

}

bool Mapa::estaDestapadaLaCasilla(unsigned int fila, unsigned int columna){
	uint posicion=0;
	Buscador<Casilla> buscador(this->pCasillasDestapadas);
	bool seEncuentra=buscador.buscar(fila, columna, posicion);
	return seEncuentra;
}

void Mapa::eliminarCasillaDestapada(unsigned int fila, unsigned int columna){

	unsigned int posicion = 0;

	Buscador<Casilla> buscador(this->pCasillasDestapadas);
	bool seEncuentra = buscador.buscar(fila,columna,posicion);

	if (seEncuentra){
		this->pCasillasDestapadas->remover(posicion);
		this->diseniador.cambiarEnBMP(DESMARCAR,fila,columna);
	}
}

void Mapa::eliminarCasillasDestapadasDesde(unsigned int fila, unsigned int columna){

	unsigned int posicion = 0;
	unsigned int cantidadABorrar = 0;

	Buscador<Casilla> buscador(this->pCasillasDestapadas);
	bool seEncuentra = buscador.buscar(fila,columna,posicion);

	cantidadABorrar = this->pCasillasDestapadas->contarElementos()-posicion+1;
	Casilla casillaABorrar;

	if (seEncuentra){
		for(unsigned int i=0;i<cantidadABorrar;i++){

			casillaABorrar = pCasillasDestapadas->obtener(posicion);
			this->pCasillasDestapadas->remover(posicion);
			this->diseniador.cambiarEnBMP(DESMARCAR,casillaABorrar.obtenerFila(),casillaABorrar.obtenerColumna());
		}

	}
}
