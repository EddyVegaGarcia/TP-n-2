#ifndef DISENIADOR_H_
#define DISENIADOR_H_

# include "constantes.h"

# include "EasyBMP.h"
# include "EasyBMP_BMP.h"
# include "EasyBMP_DataStructures.h"
# include "EasyBMP_VariousBMPutilities.h"

class Diseniador{

private:

	BMP disenio;
	unsigned int numeroDeImpresion;
	unsigned int cantidadFilas;
	unsigned int cantidadColumnas;


public:

	Diseniador();
	//post: crea un objeto Diseniador que contiene el disenio basico del mapa

	void crearDisenioBase();

	void modificarCantidadDeFilas(uint filas);

	void modificarCantidadDeColumnas(uint columnas);

	//post devuelve el disenio basandose en los tamanios de fila y columna recibidos
	BMP obtenerDisenio();

	void cambiarEnBMP(char valor, uint fila, uint columna);

	void escribirDisenio();

private:


	void llenarMapaBloqueado();
	void llenarEsquinas();
	void llenarBordes();

	void llenarEsquinaSuperiorDerecha();
	void llenarEsquinaSuperiorIzquierda();
	void llenarEsquinaInferiorDerecha();
	void llenarEsquinaInferiorIzquierda();

	void llenarBordeSuperior();
	void llenarBordeInferior();
	void llenarBordeIzquierdo();
	void llenarBordeDerecho();

	unsigned int calcularAncho(unsigned int dimColumnas);
	uint calcularAlto(unsigned int dimFilas);

};

#endif /*DISENIADOR_H_*/
