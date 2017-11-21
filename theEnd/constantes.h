#ifndef CONSTANTES_H_
#define CONSTANTES_H_

typedef unsigned int uint;

const char VACIO = '0';
const char MINA = 'X';
const char BANDERA = 'B';

const char NADA = 'N';
const char DESMARCAR = '/';

const int PERDIO_PARTIDA = 3;
const int SE_RETIRO = 4;
const int SIGUE_JUGANDO = 0;
const int HA_GANADO = 1;
const int NO_ESTA_JUGANDO = 5;

const uint FACIL=10;
const uint MEDIO=20;
const uint DIFICIL=40;

const uint CELDAS=16;
const uint BORDES=8;
										//iniciales=
const char archivoN[] = "topblue"; 		//norte
const char archivoS[] = "bottomblue"; 	//sur
const char archivoE[] = "rightblue"; 	//este
const char archivoO[] = "leftblue"; 	//oeste

const char archivoNO[] = "topleftblue";	//noroeste
const char archivoNE[] = "toprightblue";//noreste
const char archivoSO[] = "bottomleft";	//suroeste
const char archivoSE[] = "bottomright";	//sureste

const char archivoBloqueado[] = "blockedblue";
const char archivoMina[] = "mineblue" ;
const char archivoBandera[] = "flaggedblue" ;
const char archivoVacio[] = "emptyblue" ;
const char archivo1[] = "oneblue" ;
const char archivo2[] = "twoblue" ;
const char archivo3[] = "threeblue" ;
const char archivo4[] = "fourblue" ;
const char archivo5[] = "fiveblue" ;
const char archivo6[] = "sixblue" ;
const char archivo7[] = "sevenblue" ;
const char archivo8[] = "eightblue" ;
const char archivoDeJuego[] = "currentGame";

const char archivoDePuntajes[] = "puntajes.txt";

//andy el mejor

#endif /*CONSTANTES_H_*/
