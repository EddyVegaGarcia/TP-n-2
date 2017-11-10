#include "diseniador.h"
#include "constantes.h"

Diseniador::Diseniador(unsigned int filas, unsigned int columnas){
	
	this-> cantidadFilas = filas;
	this-> cantidadColumnas = columnas;
	
	unsigned int alto = calcularAlto(this->cantidadFilas);
	unsigned int ancho = calcularAncho(this->cantidadColumnas);

	this-> disenio.SetSize(ancho,alto);

	this->llenarMapaBloqueado();
	this->llenarEsquinas();
	this->llenarBordes();

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


	for(uint i= 0; i< (this->cantidadColumnas*2); i++){
			RangedPixelToPixelCopy(dibujoNorte,1,8,8,1,this->disenio,
					1+BORDES+(i*BORDES),1+BORDES);
	}
	
}
void Diseniador::llenarBordeInferior(){

	BMP dibujoSur;
	dibujoSur.ReadFromFile(archivoS);

	for(uint i= 0; i<(this->cantidadColumnas*2); i++){

			RangedPixelToPixelCopy(dibujoSur,1,8,8,1,disenio,
					1+BORDES+(this->cantidadFilas*CELDAS), 1+BORDES+(i*BORDES));
	}
}
void Diseniador::llenarBordeIzquierdo(){

	BMP dibujoOeste;
	dibujoOeste.ReadFromFile(archivoO);

	for(uint i= 0; i<this->cantidadFilas; i++){

		RangedPixelToPixelCopy(dibujoOeste,1,8,8,1,disenio,
				1,1+BORDES+(i*BORDES));
	}

}
void Diseniador::llenarBordeDerecho(){

	BMP dibujoEste;
	dibujoEste.ReadFromFile(archivoE);

	for(uint i= 0; i<this->cantidadFilas; i++){

			RangedPixelToPixelCopy(dibujoEste,1,8,8,1,disenio,
					1+BORDES+(this->cantidadColumnas*CELDAS),1+BORDES+(i*BORDES));
		}
}

void Diseniador::llenarMapaBloqueado(){

	BMP dibujoBloqueado;
	dibujoBloqueado.ReadFromFile(bloqueado);

	for(uint i=0; i<this->cantidadFilas; i++){

		for(uint j=0; j<this->cantidadColumnas; i++){

			RangedPixelToPixelCopy(dibujoBloqueado,1,16,16,1,disenio,
					1+BORDES+(i*CELDAS),1+BORDES+(this->cantidadFilas*CELDAS));
		}
	}


}

void Diseniador::llenarEsquinaSuperiorDerecha(){
	
	BMP dibujoNoreste;
	dibujoNoreste.ReadFromFile(archivoNE);

	RangedPixelToPixelCopy(dibujoNoreste,1,8,8,1,disenio,
						1+BORDES+(this->cantidadColumnas*CELDAS),1+BORDES+(this->cantidadFilas*CELDAS));
}
void Diseniador::llenarEsquinaSuperiorIzquierda(){
	

	BMP dibujoNoroeste;
	dibujoNoroeste.ReadFromFile(archivoNO);

	RangedPixelToPixelCopy(dibujoNoroeste,1,8,8,1,disenio,
			1,1+BORDES+(this->cantidadFilas*CELDAS));
	
}
void Diseniador::llenarEsquinaInferiorDerecha(){
	
	BMP dibujoSuroeste;
	dibujoSuroeste.ReadFromFile(archivoSO);

	RangedPixelToPixelCopy(dibujoSuroeste,1,8,8,1,disenio,
			1+BORDES+(this->cantidadColumnas*CELDAS),1);
}
void Diseniador::llenarEsquinaInferiorIzquierda(){
	
	BMP dibujoSureste;
	dibujoSureste.ReadFromFile(archivoSE);

	RangedPixelToPixelCopy(dibujoSureste,1,8,8,1,disenio,
			1,1);
}
