#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Video.h"

using namespace std;

Video::Video (IKey *codigo, Fecha *fecha, Hora *hora, int duracion, string urlvideo) {
	this->setcodigo(codigo);
	this->setfechaMensaje(fecha);
	this->sethoraMensaje(hora);
	this->duracion  	= duracion;
	this->URLvideo    	= urlvideo;
}

Video::~Video () {}

int Video::getDuracion() {
	return duracion;
}
string Video::getURLvideo() {
	return URLvideo;
}

ostream& operator<<(ostream& os, const Video& mens_video) {  
	string codigo = new string (mens_video.getodigo());	
	
    os 	<< "Código: " 	 	<< codigo 					  	<< '\n' 
   		<< "Fecha: " 		<< mens_video.getfechaMensaje() << '\n' 
   		<< "Hora: " 		<< mens_video.gethoraMensaje()  << '\n'
   		<< "Duración: " 	<< mens_video.getDuracion()  	<< '\n'
   		<< "URL: " 			<< mens_video.getURLvideo(); 
    return os;  
}