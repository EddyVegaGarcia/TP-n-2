BMP Diseñador::diseña(BMP baseMapa){
this->diseñador.llenarMapaBloqueado(baseMapa);
this->diseñador.llenarEsquinas(baseMapa);
this->diseñador.llenarBordes(baseMapa);
return baseMapa;
}
void Diseñador::llenarEsquinas(baseMapa){

	llenarEsquinaSuperiorDerecha(baseMapa);
	llenarEsquinaSuperiorIzquierda(baseMapa);
	llenarEsquinaInferiorDerecha(baseMapa);
	llenarEsquinaInferiorIzquierda(baseMapa);

}
void llenarEsquinaSuperiorDerecha(BMP baseMapa){}
void llenarEsquinaSuperiorIzquierda(BMP baseMapa){}
void llenarEsquinaInferiorDerecha(BMP baseMapa){}
void llenarEsquinaInferiorIzquierda(BMP baseMapa){}

void Diseñador::llenarBordes(baseMapa){

	llenarBordeSuperior(baseMapa);
	llenarBordeInferior(baseMapa);
	llenarBordeIzquierdo(baseMapa);
	llenarBordeDerecho(baseMapa);

}
void llenarBordeSuperior(BMP baseMapa){

	for(int i= 0; (i<this->dimColumna)*2; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,(BORDES+1+(i*BORDES),1);
		}

}
void llenarBordeInferior(BMP baseMapa){

	for(int i= 0; (i<this->dimFila)*2; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
					BORDES+1+(i*BORDES),BORDES+1(CASILLAS*this->dimFila),);
		}
}
void llenarBordeIzquierdo(BMP baseMapa){

	for(int i= 0; i<this->dimFila; i++){

		RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,1,(BORDES+1+(BORDES*i)));
	}

}
void llenarBordeDerecho(BMP baseMapa){

	for(int i= 0; i<this->dimFila; i++){

			RangedPixelToPixelCopy(##,1,16,16,1,##baseMapa,
					BORDES+1+((this->dimFila)*CASILLAS),BORDES+1+(CASILLAS+i));
		}
}

void Diseñador::llenarMapaBloqueado(BMP &baseMapa){

	for(int i=0; i<this->dimFila; i++){

		for(int j=0; j<this->dimColumna; i++){

			RangedPixelToPixelCopy(ARcasillasBloqueadas,1,16,16,1,basemapa,
					(BORDES+1)+(i*CASILLAS),(BORDES+1)+(i+CASILLAS))
		}
	}


}
