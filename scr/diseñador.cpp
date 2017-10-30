#include "diseniador.h"


Diseniador::Diseniador(BMP baseMapa, unsigned int filas, unsigned int columnas){
	
	this->aDiseniar = baseMapa;
	
this->llenarMapaBloqueado(baseMapa);
this->llenarEsquinas(baseMapa);
this->llenarBordes(baseMapa);

}

void Diseniador::llenarEsquinas(){

	llenarEsquinaSuperiorDerecha();
	llenarEsquinaSuperiorIzquierda();
	llenarEsquinaInferiorDerecha();
	llenarEsquinaInferiorIzquierda();

}
void llenarEsquinaSuperiorDerecha(){}
void llenarEsquinaSuperiorIzquierda(){}
void llenarEsquinaInferiorDerecha(){}
void llenarEsquinaInferiorIzquierda(){}

void Diseniador::llenarBordes(){

	llenarBordeSuperior();
	llenarBordeInferior();
	llenarBordeIzquierdo();
	llenarBordeDerecho();

}
void llenarBordeSuperior(){

	for(int i= 0; (i<this->cantColumnas)*2; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
					1+BORDES+(i*BORDES),1+BORDES+(this->cantFilas*CELDAS));
		}

}
void llenarBordeInferior(){

	for(int i= 0; (i<this->cantColumnas)*2; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
					1+BORDES+(i*BORDES),1+BORDES);
		}
}
void llenarBordeIzquierdo(){

	for(int i= 0; i<this->cantFilas; i++){

		RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
				1,1+BORDES+(i*BORDES));
	}

}
void llenarBordeDerecho(){

	for(int i= 0; i<this->cantFilas; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
					1+BORDES+(this->dimColumna*CELDAS),1+BORDES+(i*BRODES));
		}
}

void Diseniador::llenarMapaBloqueado(){

	for(int i=0; i<this->dimFila; i++){

		for(int j=0; j<this->dimColumna; i++){

			RangedPixelToPixelCopy(ARcasillasBloqueadas,1,16,16,1,basemapa,
					(BORDES+1)+(i*CASILLAS),(BORDES+1)+(i+CASILLAS))
		}
	}


}

void llenarEsquinaSuperiorDerecha(){
	
	RangedPixelToPixelCopy(ARcasillasBloqueadas,1,16,16,1,basemapa,
						(BORDES+1)+(i*CASILLAS),(BORDES+1)+(i+CASILLAS))
}
void llenarEsquinaSuperiorIzquierda(){
	
	
}
void llenarEsquinaInferiorDerecha(){
	
	
}
void llenarEsquinaInferiorIzquierda(){
	
	
}
