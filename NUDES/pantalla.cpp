/*
 * pantalla.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: marcela
 */
char pedirOpcionPasadoFuturo (){
    
   char opcionDeUsuario;

    std::cout<<"VOLVER AL PASADO 'deshacer' (P) || ";
		std::cout<<"VOLVER AL FUTURO 'rehacer' (F) || "<<std::endl;
		std::cout<<"Ya no realizar JUGADA ESPECIAL (N) : "<<std::endl;

		std::cin>>opcionDeUsuario;
    
    return opcionDeUsuario;
 }
