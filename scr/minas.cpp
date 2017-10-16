#include "minas.h"
#include "minero.h"
#include "lista.h"
const char MINA 'X';


Minas::Minas(uint dimFilas, uint dimColumnas, uint dificultad){
    
    Minero minero(dimFilas , dimColumnas , dificultad);
    lista<Mina>* puntero = minero.sembrarMinas();
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
    while(minasAlmacenadas->avanzarCursor() &&  !minaActual.esMina(filaCasilla, columnaCasilla) && valor < '9')
    if (minaActual.esMina(filaCasilla, columnaCasilla)){
        valor = MINA;
    }  
    return valor;
}
