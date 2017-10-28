# include "mapa.h"

Mapa::Mapa(int filaRecibida, int columnaRecibida, char dificultadRecibida){

	this-> dimFila = filaRecibida;
	this-> dimColumna = columnaRecibida;
	this-> dificultad = DificultadRecibida;
	
	
	//no faltan declararlos antes?? y poner lista<>* ??
	crearListaMinasYAsignarPuntero();	
	crearListaCasillasYAsignarPuntero();
	crearListaBanderasYAsignarPuntero();
	
	Minero minero(dimFila,dimColumna,dificultad,pMinas);
	minero.sembrarMinas();
}

void Mapa::crearListaMinasYAsignarPuntero(){
	//Aquí los asteriscos
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

Lista<Casilla>* Mapa::obtenerPunteroCasillas(){
	return this-> pCasillasDestapadas;
}

Lista<Bandera>* Mapa::obtenerPunteroBanderas(){
	return this-> pBanderas;
}


void Mapa::mostrarMapa(){

	vector = new char[this->dimColumna];
	
	for(int i = 0; i < dimFila; i++ ){
		llenarVectorFila(i + 1, vector);
		mostrarVector(vector);
	}
		
}
	
void llenarVectorFila(unsigned int fila, char* vector[]){
	llenarVectorDeNoMostrado(vector);
	llenarVectorDeCasillasDestapadas(fila, vector);
	llenarVectorDeBanderas(fila, vector);
	
}
	
void llenarVectorDeNoMostrado(char* vector[]){
	for(int i = 0; i< this-> dimColumna; i++)
		vector[i] = '*';
}

	
void llenarVectorDeCasillasDestapadas(unsigned int fila,char* vector[]){

	this-> pCasillasDestapadas -> iniciarCursor();

	Casilla casillaActual;
		
	int casillasAsignadas = 0;
	while(this->pCasillasDestapadas->avanzarCursor() && casillasAsignadas =<this->dimFila){

		casillaActual = pCasillasDestapadas->obtenerCursor();

		if (casillaActual.obtenerFila() == fila){
			vector[casillaActual.obtenerColumna - 1] = casillaActual.obtenerValor();
			casillasAsignadas ++;
		}
	}	
}
void llenarVectorDeBanderas(unsigned int fila,char* vector[]){
	
	this->pBanderas->iniciarCursor();
	
	Bandera banderaActual;
	
	int banderasAsignadas = 0;
	
	while(this->pBanderas->avanzarCursor() && banderasAsignadas =< this->dimFila){
	
		banderaActual = pBanderas->obtenerCursor();
		
		if(banderaActual.obtenerColumna() == fila){
		
			vector[banderaActual.obtenerColumna - 1] = '9';
			banderasAsignadas++;
		}
	}
}
void mostrarVector(char* vector[]){
	
	for (unsigned int i = 0; i< this->columna; i++){

			if(vector[i] == 9)
				std::cout<<Bandera<<;
			else if (vector[i] == 0) 
				std::cout<<'*';
			else 
				std::cout<< vector[i];
			std::endl;
	}
}
/*Método que estaba en "Minas" (un poco cambiado), xq "Minas" es una clase que no existe más.*/
char Mapa::calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla){
	char valor = '0';
	pMinas->iniciarCursor();
	
	Mina minaActual;
	if (pMinas->avanzarCursor)
		minaActual = pMinas->ObtenerCursor();

	
	//MIs OJOS!!!!!! XD hay que revisar acá
	if (minaActual.esMina(filaCasilla, columnaCasilla)){
		valor = MINA;
	} else {
		while(pMinas->avanzarCursor() && !minaActual.esMina(filaCasilla, columnaCasilla) && valor < '9'){
			Mina minaActual = pMinas->obtenerCursor();
			if(minaActual.estaJuntoAMina(filaCasilla , columnaCasilla))
				valor++;
		}
	
	return valor;
}

void Mapa::agregarCasillaDestapada(int filaRecibida,int columnaRecibida,char valorRecibido){ // modificando
	Casilla casillaPorAgregar(filaRecibida, columnaRecibida, valorRecibido);
	this -> pMinas -> agregar(casillaPorAgregar);
}

//pre: lista casillas no vacia
//post: devuelve valor de la ultima casilla
char Mapa::obtenerValorCasilla(){
	valor=this->calcularValorDeCasilla(filaRecibida,columnaRecibida);
	return valor;
}
	
void Mapa::colocarMarca(int filaRecibida,int columnaRecibida){
	Bandera banderaAColocar(filaRecibida, columnaRecibida);
	this -> pBanderas -> agregar(banderaAColocar);
}

//////////////////////////////////////////////////////////
/////// Métodos en construccin ///////////////////////////
//////////////////////////////////////////////////////////

/* en marcador dicen if validarMarca (o sea si está en la lista de banderas) entonces removerMarca.
* Se estaría recorriendo dos veces. Si yo ya encontré la posición cuando me preguntaron si estaba o no, debería poder
* llamar al remover marca ya con la posicin para no hacerlo buscar de nuevo.*/
void Mapa::removerMarca(uint filaRecibida, uint columnaRecibida){
	pBanderas->remover(posicion);
}
	
/* Propongo que este método vea si está y si está la remueva.
* De esa forma ya tiene la posción y no se recorre dos veces. Habría que cambiarle una línea al marcador.*/
bool Mapa::validarMarca(unsigned int fila, unsigned int columna){
	bool seEncuentra=seEncuentraEnListaDeBanderas(fila, columna);
	if (seEncuentra) {remover(fila, columna)};
	return seEncuentra;
}	

bool Mapa::seEncuentraEnListaDeBanderas(uint &fila, uint &columna){
	return (seEncuentraEnLista('b', fila, columna));
}

/* Busca en una de las tres listas, según indicado x parámetro, y si encuentra asigna la fila y columna.*/
bool Mapa::seEncuentraEnLista(char lista, uint &fila, uint &columna){
	if (lista=='b'){
		Lista<Bandera>* pLista=pBanderas;
		Bandera elementoActual;
	}
	else if (lista=='c'){
		Lista<Casilla>* pLista=pCasillasDestapadas;
		Casilla elementoActual;
	}
	else {// lista es 'm'
		Lista<Mina>* pLista=pMinas;
		Mina elementoActual;
	}
	
	bool seEncuentra=false;
	
	/* elementoActual tiene fila y columna. Buscar comparando elemento->obtenerFila() con la fila q se pasó x parámetro*/
	/*por ejemplo
	* plista->iniciarCursor();
	* while (pLista->avanzarCursor() &&
	* Pero no s si lo quieren hacer secuenciaaaal o cómo. Tengo sueño, hasta mañana ^_^ */
	
	return seEncuentra;
}

/*validarMina, estaDestapadaLaCasilla, Hay que buscar en las listas*/
bool Mapa::validarMina(unsigned int fila, unsigned int columna){
	
}

bool Mapa::estaDestapadaLaCasilla(unsigned int fila, unsigned int columna){
}
