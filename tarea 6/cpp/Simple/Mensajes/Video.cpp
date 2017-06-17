#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Video.h"

using namespace std;

Video::Video (IKey codigo, Fecha fecha, Hora hora, int duracion, String urlvideo) : Mensaje (codigo, fecha, hora) {
	this->codigo 	    = codigo;
	this->fecha 	    = new Fecha(fecha->getdia(), fecha->getmes(), fecha->getanio());
	this->hora 		  	= new Hora(hora->gethoras(), hora->getminutos());
	this->duracion  	= duracion;
	this->URLvideo    	= urlvideo;
}

Video::~Video () {}

int Video::getDuracion() {
	return duracion;
}
String Video::getURLvideo() {
	return URLvideo;
}

ostream& operator<<(ostream& os, const Video& mens_video) {  
	string codigo = new String (mens_video.getodigo());	
	
    os 	<< "Código: " 	 	<< codigo 					  	<< '\n' 
   		<< "Fecha: " 		<< mens_video.getfechaMensaje() << '\n' 
   		<< "Hora: " 		<< mens_video.gethoraMensaje()  << '\n'
   		<< "Duración: " 	<< mens_video.getDuracion()  	<< '\n'
   		<< "URL: " 			<< mens_video.getURLvideo(); 
    return os;  
}