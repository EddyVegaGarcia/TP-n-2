/*
 * NO FORMA PARTE DEL PROGRAMA, SON LINEAS DE CODIGO UTILIZADAS
 * PARA PODER DEBUGEAR EL PROGRAMA MAS FACILMENTE
 *
 *
	//PARA IMPRIMIR LA LISTA DE JUGADAS (sin sus paralelas)
	bool termino = false;
	std::cout<<"adentro de la lista estan:"<<std::endl;
	NodoGrafo<JugadaLight*>* jugadaActualARecorrer = this->jugadas->obtenerPunteroNodoPrimero();
	while(!termino){
	JugadaLight* jugada = jugadaActualARecorrer->obtenerDato();
	std::cout<<jugada->obtenerFila()<<" "<<jugada->obtenerColumna()<<std::endl;
	if (jugadaActualARecorrer->obtenerSiguiente() == NULL)
		termino = true;
	else jugadaActualARecorrer = jugadaActualARecorrer->obtenerSiguiente();
	}

	//PARA IMPRIMIR EL DATO ACTUAL AL QUE APUNTA EL GRAFO
	JugadaLight* JActual=this->jugadas->obtenerDatoActual();
	std::cout<<"Dato actual en el grafo: "<<JActual->obtenerFila()<<" "<<JActual->obtenerColumna()<<std::endl;

	//PARA IMPRIMIR LA LISTA DE BANDERAS
	Lista<Bandera>* banderas = this->tableroDeJuego->obtenerPunteroBanderas();
	banderas->iniciarCursor();
	Bandera actual;
	std::cout<<"lista de banderas: "<<std::endl;
	while(banderas->avanzarCursor()){
		actual = banderas->obtenerCursor();
		std::cout<<"fila: "<<actual.obtenerFila()<<" columna: "<<actual.obtenerColumna()<<"Se destapo: "<<std::endl;
	}
	//PARA IMPRIMIR LA LISTA DE CASILLAS DESTAPADAS
	Lista<Casilla>* casillasDestapadas = this->tableroDeJuego->obtenerPunteroCasillas();
	Casilla casillaActual;
	std::cout<<"lista de destapadas: "<<std::endl;
		while(casillasDestapadas->avanzarCursor()){
			casillaActual = casillasDestapadas->obtenerCursor();
			std::cout<<"fila: "<<casillaActual.obtenerFila()<<" columna: "<<casillaActual.obtenerColumna()<<" Se destapo: "<<std::endl;
		}
 */
