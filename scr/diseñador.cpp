#ifndef DISENIADOR_H_
#define DISENIADOR_H_

#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"


class Diseniador{

private:
	
	BMP aDiseniar;
	unsigned int cantidadFilas;
	unsigned int cantidadColumnas;

void llenarMapaBloqueado();
void llenarEsquinas();
void llenarBordes();

void llenarBordeSuperior();
void llenarBordeInferior();
void llenarBordeIzquierdo();
void llenarBordeDerecho();

void llenarEsquinaSuperiorDerecha();
void llenarEsquinaSuperiorIzquierda();
void llenarEsquinaInferiorDerecha();
void llenarEsquinaInferiorIzquierda();

public:


Diseniador(BMP baseMapa,unsigned int filas,unsigned int columnas);

};

#endif /* DISENIADOR_H_ */
