

#include "destapador.h"
#include "constantes.h"

using namespace std;

		
//constructor
Destapador::Destapador (mapa* mapaActual)
{

  this->mapa = mapaActual;
  this->fila = 0
  this->columna = 0
  
  
  
}

//metodos publicos
int Destapador::destapar(int filaJugada, int columnaJugada) 
{
	int puntaje = 0;
	this->fila =  filaJugada;
 	this->columna = columnaJugada;
	
	if(!mapa->estaDestapadaLaCasilla(this->fila , this->columna )){
		mapa->agregarCasillaDestapada(this->fila, this->columna);
		char valorCasilla = mapa->obtenerValorCasilla();
		if(valorCasilla = VACIO)
		{
			destaparPandemia();
		}
		else
		{
			puntaje  = destaparCasillaNoVacia(valorCasilla, *puntaje);
		}
	}
	return  puntaje;
}


//metodos privadas
int Destapar::destaparPandemia()
{
	

void epidemia(char tablaMinada[][ancho],char tablaBloqueada[][ancho],int fila, int columna,int &contadorCeldas){
	//si hay un cero, desbloquea los alrededores hasta encontrarse con un numero distinto de cero (recursiva)
  
  //tablaMinada es la matriz completa y tablaBloqueada es la matriz que interactua con el usuario, la funcion
  //recibe ambas y luego una posicion representada por Fila Columna, chequea los alrededores de fila columna
  //contadorCeldas no se usa en este trabajo CREO.

	if(tablaBloqueada[fila-1][columna-1]=='*' || tablaBloqueada[fila-1][columna-1]=='B'){
		tablaBloqueada[fila-1][columna-1]=tablaMinada[fila-1][columna-1];
		--contadorCeldas;

		if(tablaMinada[fila-1][columna-1]=='0'){

			if(fila-1 !=0 &&tablaMinada[fila-2][columna-1]!='x' && tablaBloqueada[fila-2][columna-1]=='*')
				expandir(tablaMinada,tablaBloqueada,fila-1,columna,contadorCeldas);

			if(columna-1 !=0 &&tablaMinada[fila-1][columna-2]!='x' && tablaBloqueada[fila-1][columna-2]=='*')
				expandir(tablaMinada,tablaBloqueada,fila,columna-1,contadorCeldas);

			if(columna !=ancho && tablaMinada[fila-1][columna]!='x' && tablaBloqueada[fila-1][columna]=='*')
				expandir(tablaMinada,tablaBloqueada,fila,columna+1,contadorCeldas);

			if(fila !=largo && tablaMinada[fila][columna-1]!='x' && tablaBloqueada[fila][columna-1]=='*')
				expandir(tablaMinada,tablaBloqueada,fila+1,columna,contadorCeldas);

		}
	}
}
 
}

int Destapar::destaparCasillaNoVacia(char valorCasilla)
{
	
	int puntaje = 0;
  	
	if(valorCasilla == MINA)
	{
		puntaje = PERDIO_PARTIDA;	
	}
	
	return puntaje;
	
	
}
