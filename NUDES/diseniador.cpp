#include "diseniador.h"
#include "constantes.h"

Diseniador::Diseniador(){
	this-> cantidadFilas = 0;
	this-> cantidadColumnas = 0;
	this-> numeroDeImpresion = 0;
}

void Diseniador::crearDisenioBase(){

	unsigned int alto = calcularAlto(this->cantidadFilas);
	unsigned int ancho = calcularAncho(this->cantidadColumnas);

	this-> disenio.SetSize(ancho,alto);

	this->llenarMapaBloqueado();
	this->llenarEsquinas();
	this->llenarBordes();

	this->escribirDisenio();
}

void Diseniador::modificarCantidadDeFilas(uint filas){

	this->cantidadFilas = filas;

}

void Diseniador::modificarCantidadDeColumnas(uint columnas){

	this->cantidadColumnas= columnas;

}

BMP Diseniador::obtenerDisenio(){
	return this->disenio;
}

void Diseniador::escribirDisenio(){

	unsigned int digito = 0;
	this->numeroDeImpresion++;

	char nombreDeImpresion[] = "mapa_000";
/*

	if (numeroDeImpresion < 10){
		nombreDeImpresion[7] = (char)numeroDeImpresion;
	}else if(numeroDeImpresion > 100){
		digito = numeroDeImpresion/100;
		nombreDeImpresion[5] = (char)digito;
		digito = (numeroDeImpresion-(digito*100))/10;
		nombreDeImpresion[6] = (char)digito;
		digito = numeroDeImpresion % 10;
		nombreDeImpresion[7] = (char)digito;
	}else{
		digito = numeroDeImpresion / 10;
		nombreDeImpresion[6] = (char)digito;
		digito = numeroDeImpresion % 10;
		nombreDeImpresion[7] = (char)digito;
	}
*/
	disenio.WriteToFile(nombreDeImpresion);
}

void Diseniador::cambiarEnBMP(char valor, uint fila, uint columna){

	BMP tipoDeCasilla;

	if(valor == BANDERA){
		tipoDeCasilla.ReadFromFile(archivoBandera);
	}
	else if (valor == MINA){
		tipoDeCasilla.ReadFromFile(archivoMina);
	}
	else if (valor == '0'){
		tipoDeCasilla.ReadFromFile(archivoVacio);
	}
	else if (valor == '1'){
		tipoDeCasilla.ReadFromFile(archivo1);
	}
	else if (valor == '2'){
		tipoDeCasilla.ReadFromFile(archivo2);
	}
	else if (valor == '3'){
		tipoDeCasilla.ReadFromFile(archivo3);
	}
	else if (valor == '4'){
		tipoDeCasilla.ReadFromFile(archivo4);
	}
	else if (valor == '5'){
		tipoDeCasilla.ReadFromFile(archivo5);
	}
	else if (valor == '6'){
		tipoDeCasilla.ReadFromFile(archivo6);
	}
	else if (valor == '7'){
		tipoDeCasilla.ReadFromFile(archivo7);
	}
	else if (valor == '8'){
		tipoDeCasilla.ReadFromFile(archivo8);
	}
	else if (valor == DESMARCAR){
		tipoDeCasilla.ReadFromFile(archivoBloqueado);
	}

	RangedPixelToPixelCopy(tipoDeCasilla,0,15,15,0,disenio,
			BORDES+((columna-1)*CELDAS),BORDES+((fila-1)*CELDAS));
}

unsigned int Diseniador::calcularAncho(unsigned int dimColumnas){

	 unsigned int ancho = 0;
	 ancho = (CELDAS * dimColumnas) + (2 * BORDES);
	 return ancho;

}

unsigned int Diseniador::calcularAlto(unsigned int dimFilas){

	unsigned int alto =0;
	alto = (CELDAS * dimFilas) + (2 * BORDES);
	return alto;

}

void Diseniador::llenarEsquinas(){

	llenarEsquinaSuperiorDerecha();
	llenarEsquinaSuperiorIzquierda();
	llenarEsquinaInferiorDerecha();
	llenarEsquinaInferiorIzquierda();

}


void Diseniador::llenarBordes(){

	llenarBordeSuperior();
	llenarBordeInferior();
	llenarBordeIzquierdo();
	llenarBordeDerecho();

}
void Diseniador::llenarBordeSuperior(){


	BMP dibujoNorte;
	dibujoNorte.ReadFromFile(archivoN);


	for(uint i= 0; i<this->cantidadColumnas*2; i++){
			RangedPixelToPixelCopy(dibujoNorte,0,7,7,0,this->disenio,
					BORDES+(i*BORDES),0);
	}
	
}
void Diseniador::llenarBordeInferior(){

	BMP dibujoSur;
	dibujoSur.ReadFromFile(archivoS);

	for(uint i= 0; i<this->cantidadColumnas*2; i++){

			RangedPixelToPixelCopy(dibujoSur,0,7,7,0,disenio,
					BORDES+(i*BORDES),BORDES+(this->cantidadFilas*CELDAS));
	}
}
void Diseniador::llenarBordeIzquierdo(){

	BMP dibujoOeste;
	dibujoOeste.ReadFromFile(archivoO);

	for(uint i= 0; i<this->cantidadFilas*2; i++){

		RangedPixelToPixelCopy(dibujoOeste,0,7,7,0,disenio,
				0,BORDES+(i*BORDES));
	}

}
void Diseniador::llenarBordeDerecho(){

	BMP dibujoEste;
	dibujoEste.ReadFromFile(archivoE);

	for(uint i= 0; i<this->cantidadFilas*2; i++){

			RangedPixelToPixelCopy(dibujoEste,0,7,7,0,disenio,
					BORDES+(this->cantidadColumnas*CELDAS),BORDES+(i*BORDES));
		}
}

void Diseniador::llenarMapaBloqueado(){

	BMP dibujoBloqueado;
	dibujoBloqueado.ReadFromFile(archivoBloqueado);

	for(uint i=0; i<this->cantidadFilas; i++){

		for(uint j=0; j<this->cantidadColumnas; j++){

			RangedPixelToPixelCopy(dibujoBloqueado,0,15,15,0,disenio,
					BORDES+(j*CELDAS),BORDES+(i*CELDAS));
		}
	}


}

void Diseniador::llenarEsquinaSuperiorDerecha(){
	
	BMP dibujoNoreste;
	dibujoNoreste.ReadFromFile(archivoNE);

	RangedPixelToPixelCopy(dibujoNoreste,0,7,7,0,disenio,
						BORDES+(this->cantidadColumnas*CELDAS),0);
}
void Diseniador::llenarEsquinaSuperiorIzquierda(){
	

	BMP dibujoNoroeste;
	dibujoNoroeste.ReadFromFile(archivoNO);

	RangedPixelToPixelCopy(dibujoNoroeste,0,7,7,0,disenio,
			0,0);
	
}
void Diseniador::llenarEsquinaInferiorDerecha(){
	
	BMP dibujoSuroeste;
	dibujoSuroeste.ReadFromFile(archivoSE);

	RangedPixelToPixelCopy(dibujoSuroeste,0,7,7,0,disenio,
			BORDES+(this->cantidadColumnas*CELDAS),BORDES+(this->cantidadFilas*CELDAS));
}
void Diseniador::llenarEsquinaInferiorIzquierda(){
	
	BMP dibujoSureste;
	dibujoSureste.ReadFromFile(archivoSO);

	RangedPixelToPixelCopy(dibujoSureste,0,7,7,0,disenio,
			0,BORDES+(this->cantidadFilas*CELDAS));
}
