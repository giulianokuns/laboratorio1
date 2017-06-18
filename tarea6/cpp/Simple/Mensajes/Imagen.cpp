#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Imagen.h"

using namespace std;

Imagen::Imagen (IKey codigo, Fecha fecha, Hora hora, String formato, int tamanio, String textmulti, String urlpicture) : Mensaje (codigo, fecha, hora) {
	this->dtCodigo 	   = codigo;
	this->dtFecha 	   = fecha;
	this->dtHora 	   = hora;
	this->dtFormato    = formato;
	this->dtTamanio    = tamanio;
	this->dtTextMulti  = textmulti;
	this->dtURLpicture = urlpicture;
}

Imagen::~Imagen () {}

String Imagen::getFormato() {
	return formato;
}
int Imagen::getTamanio() {
	return tamanio;
}
String Imagen::getTextMulti()  {
	return textMulti;
}
String Imagen::getURLpicture()  {
	return URLpicture;
}

ostream& operator<<(ostream& os, const Imagen& mens_img) {  
	string codigo = new String (mens_img.getodigo());	
	
    os 	<< "Código: " 	 	<< codigo 					  	<< '\n' 
   		<< "Fecha: " 		<< mens_img.getfechaMensaje() 	<< '\n' 
   		<< "Hora: " 		<< mens_img.gethoraMensaje()  	<< '\n'
   		<< "Duración: " 	<< mens_img.getFormato()  		<< '\n'
   		<< "Tamaño: " 		<< mens_img.getTamanio()  		<< '\n'
   		<< "Texto: " 		<< mens_img.getTextMulti()  	<< '\n'
   		<< "URL: " 			<< mens_img.getURLpicture(); 
    return os;  
}