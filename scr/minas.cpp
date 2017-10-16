#include "minas.h"
#include "minero.h"
const char MINA 'X';


Minas::Minas(uint dimFilas, uint dimColumnas, uint dificultad){
    
    Minero minero(dimFilas , dimColumnas , dificultad);
    Mina* puntero = minero.sembrarMinas();
    this->minasAlmacenadas = puntero;
}
char Minas::calcularValorDeCasilla(uint filaCasilla, uint columnaCasilla){
    char valor = '0';
    minasAlmacenadas->iniciarCursor();
    do{
       Mina minaActual = minasAlmacenadas->ObtenerCursor();
       if(minaActual.estaJuntoAMina(filaCasilla , columnaCasilla)){
           valor ++;
       }
    }
    while(minasAlmacenadas->avanzarCursor() &&  !minaActual.esMina(filaCasilla, columnaCasilla))
    if (minaActual.esMina(filaCasilla, columnaCasilla)){
        valor = MINA;
    }  
    return valor;
}
