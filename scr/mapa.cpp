# include "mapa.h"
# include "constantes.h"

Mapa::Mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){

	this-> dimFila = filaRecibida;
	this-> dimColumna = columnaRecibida;
	this-> dificultad = dificultadRecibida;
	
	crearListaMinasYAsignarPuntero();	
	crearListaCasillasYAsignarPuntero();
	crearListaBanderasYAsignarPuntero();
	
	Minero minero(dimFila,dimColumna,dificultad,pMinas);
	minero.sembrarMinas();
	this->baseMapa = crearBMP(dimFila, dimColumna);
	
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
	return this->pMinas->contarElementos();
}

uint Mapa::obtenerCantidadDeCasillasOcultas(){
	long int casillasTotales=this->dimFila()*this->dimColumna();
	int casillasYaDestapadas=pCasillasDestapadas->contarElementos();
	return casillasTotales-casillasYaDestapadas;
}



BMP Mapa::crearBMP(unsigned int dimFila, unsigned int dimColumna){
	 unsigned int ancho = 0;
	 unsigned int alto = 0;
	ancho = calcularAncho(dimColumna);
	alto = calcularAlto(dimFila);

	BMP mapaVacio();
	mapaVacio.setSize(ancho, alto);
	Diseñador diseñador(this->baseMapa);
	this->baseMapa = diseñador.diseñarMapaVacio();

}
 unsigned int calcularAncho(unsigned int dimColumnas){

	 unsigned int ancho = 0;
	 ancho = (CASILLAS * dimColumnas) + (2 * BORDES);
	 return ancho;

 }

unsigned int calcularAlto(unsigned int dimFilas){

	unsigned int alto =0;
	alto = (CASILLAS * dimFilas) + (2 * BORDES);
	return alto;

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
	return this-> pMinas;
}

Lista<Casilla>* Mapa::obtenerPunteroCasillas(){
	return this-> pCasillasDestapadas;
}

Lista<Bandera>* Mapa::obtenerPunteroBanderas(){
	return this-> pBanderas;
}
					       
void Mapa::ponerImagenEnMapa(archivoimagen.BMP, mapa, uint fila, uint columna){
 /* Mati aca te deje para que hagas nada mas esto, te pasa por parametro el archivo de la imagen el mapa
 * base la fila y columna ya lo unico que tienes que hacer es lo tuyo que copie de ese archivo al otro y 
 * las cuentas de las posiciones y ya.
 */

}				       
void Mapa::cambiarEnBMP(BMP mapa,char valor, uint fila, uint columna){
	if(valor == BANDERA){
	        ponerImagenEnMapa(archivoBandera, mapa, uint fila, uint columna);
	}
	else if (valor == VACIO){
		ponerImagenEnMapa(archivoVacio, mapa, uint fila, uint columna);
	}
	else if (valor == MINA){
		ponerImagenEnMapa(archivoMina, mapa, uint fila, uint columna);
	}
	else if (valor == '1'){
		ponerImagenEnMapa(archivo1, mapa, uint fila, uint columna);
	}
	else if (valor == '2'){
		ponerImagenEnMapa(archivo2, mapa, uint fila, uint columna);
	}
	else if (valor == '3'){
		ponerImagenEnMapa(archivo3, mapa, uint fila, uint columna);
	}
	else if (valor == '4'){
		ponerImagenEnMapa(archivo4, mapa, uint fila, uint columna);
	}
	else if (valor == '5'){
		ponerImagenEnMapa(archivo5, mapa, uint fila, uint columna);
	}
	else if (valor == '6'){
		ponerImagenEnMapa(archivo6, mapa, uint fila, uint columna);
	}
	else if (valor == '7'){
		ponerImagenEnMapa(archivo7, mapa, uint fila, uint columna);
	}
	else if (valor == '8'){
		ponerImagenEnMapa(archivo8, mapa, uint fila, uint columna);
	}

}
					      
void llenarMapaBanderas(Lista<Bandera>* banderas, BMP mapa){}
	banderas->iniciarCursor;
	while(banderas->avanzarCursor()){
		Bandera banderaActual();
		banderaActual = banderas->obtenerCursor();
		if(!banderaActual->seDestapoEnTablero()){
			cambiarEnBMP(this->baseMapa, BANDERA, banderaActual->obtenerFila,
				                          banderaActual->obtenerColumna);
			
		}  
	   }		     
void llenarMapaCasillasDestapadas(Lista<Casilla>* casillas, BMP mapa){
       casillas->iniciarCursor;
       while(casillas->avanzarCursor()){
		Casilla casillaActual();
		casillaActual = casillas->obtenerCursor();
		if(!casillaActual->seDestapoEnTablero()){
			char valor;
			valor = casillaActual->obtenerValor();
			cambiarEnBMP(this->baseMapa, valor, casillaActual->obtenerFila(),
				                          casillaActual->obtenerColumna());
			
		}  
	   }
}
void Mapa::mostrarMapa(){
	llenarMapaBanderas(this->pCasillasDestapadas, this->mapaBase);
	llenarMapaCasillasDestapadas(this->pBanderas,this->mapaBase);
	
	
}


/*Método que estaba en "Minas" (un poco cambiado), xq "Minas" es una clase que no existe más.*/
char Mapa::calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla){
	char valor = '0';
	pMinas->iniciarCursor();
	
	Mina minaActual;
	if (pMinas->avanzarCursor())
		minaActual = pMinas->ObtenerCursor();

	
	//MIs OJOS!!!!!! XD hay que revisar acá
	if (minaActual.esMina(filaCasilla, columnaCasilla)){
		valor = MINA;
	} else {/*jajaja sí, no se entiende un carajo ;D*//*<'9' xq 8 es la máxima cantidad de bombas que puede tener alrededor*/
		while(pMinas->avanzarCursor() && !minaActual.esMina(filaCasilla, columnaCasilla) && valor < '9'){
			Mina minaActual = pMinas->obtenerCursor();
			if(minaActual.estaJuntoAMina(filaCasilla , columnaCasilla))
				valor++;
		}
	}
	return valor;
}

void Mapa::agregarCasillaDestapada(int filaRecibida,int columnaRecibida,char valorRecibido){ // modificando
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

bool Mapa::removerYDevolverSiHabiaMarca(unsigned int fila, unsigned int columna){ // validarYRemoverMarcaSiHay(this->fila , this->columna)
	uint posicion=0;

	Buscador buscador(this->pBanderas);
	bool seEncuentra=buscador.buscar(fila, columna, posicion);

	if (seEncuentra)
		pBanderas->remover(posicion);

	return seEncuentra;
}

bool Mapa::validarMina(unsigned int fila, unsigned int columna){

	Buscador buscador(this->pMinas);
	bool seEncuentra=buscador.buscar(fila, columna);
	return seEncuentra;

}

bool Mapa::estaDestapadaLaCasilla(unsigned int fila, unsigned int columna){
	Buscador buscador(this->pCasillasDestapadas);
	bool seEncuentra=buscador.buscar(fila, columna);
	return seEncuentra;
}
