


#include "diseniador.h"
#include "constantes.h"

Diseniador::Diseniador(unsigned int filas, unsigned int columnas){
	
	this-> cantidadFilas = filas;
	this-> cantidadColumnas = columnas;
	
	unsigned int alto = calcularAlto(this->cantidadFilas);
	unsigned int ancho = calcularAncho(this->cantidadColumnas);

	this-> disenio.SetSize(ancho,alto);

	disenio.WriteToFile(archivoDeJuego);

	this->llenarMapaBloqueado();
	this->llenarEsquinas();
	this->llenarBordes();

	disenio.WriteToFile(archivoDeJuego);

}

BMP Diseniador::obtenerDisenio(){
	return this->disenio;
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
