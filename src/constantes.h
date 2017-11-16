#ifndef CONSTANTES_H_
#define CONSTANTES_H_

typedef unsigned int uint;

const char VACIO = '0';
const char MINA = 'X';
const char BANDERA = 'B';

const char NADA = 'N';

const int PERDIO_PARTIDA = 3;
const int SE_RETIRO = 4;
const int SIGUE_JUGANDO = 0;
const int HA_GANADO = 1;
const int NO_ESTA_JUGANDO = 5;

const uint FACIL=20;
const uint MEDIO=30;
const uint DIFICIL=40;

const uint CELDAS=16;
const uint BORDES=8;
											//iniciales=
const char archivoN[] = "topblue.bmp"; 		//norte
const char archivoS[] = "bottomblue.bmp"; 	//sur
const char archivoE[] = "rightblue.bmp"; 	//este
const char archivoO[] = "leftblue.bmp"; 	//oeste

const char archivoNO[] = "topleftblue.bmp";	//noroeste
const char archivoNE[] = "toprightblue.bmp";//noreste
const char archivoSO[] = "bottomleft.bmp";	//suroeste
const char archivoSE[] = "bottomright.bmp";	//sureste

const char archivoBloqueado[] = "blockedblue.bmp";
const char archivoMina[] = "mineblue.bmp" ;
const char archivoBandera[] = "flaggedblue.bmp" ;
const char archivoVacio[] = "emptyblue.bmp" ;
const char archivo1[] = "oneblue.bmp" ;
const char archivo2[] = "twoblue.bmp" ;
const char archivo3[] = "threeblue.bmp" ;
const char archivo4[] = "fourblue.bmp" ;
const char archivo5[] = "fiveblue.bmp" ;
const char archivo6[] = "sixblue.bmp" ;
const char archivo7[] = "sevenblue.bmp" ;
const char archivo8[] = "eightblue.bmp" ;
const char archivoDeJuego[] = "currentGame.bmp";

const char archivoDePuntajes[] = "puntajes.txt";

// pongan sus constanteessssss :)

#endif /*CONSTANTES_H_*/
