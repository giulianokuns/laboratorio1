#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Imagen.h"

using namespace std;

Imagen::Imagen (IKey codigo, Fecha fecha, Hora hora, string formato, int tamanio, string textmulti, string urlpicture) : Mensaje (codigo, fecha, hora) {
	this->dtCodigo 	   = codigo;
	this->dtFecha 	   = fecha;
	this->dtHora 	   = hora;
	this->dtFormato    = formato;
	this->dtTamanio    = tamanio;
	this->dtTextMulti  = textmulti;
	this->dtURLpicture = urlpicture;
}

Imagen::~Imagen () {}

string Imagen::getFormato() {
	return formato;
}
int Imagen::getTamanio() {
	return tamanio;
}
string Imagen::getTextMulti()  {
	return textMulti;
}
string Imagen::getURLpicture()  {
	return URLpicture;
}

ostream& operator<<(ostream& os, const Imagen& mens_img) {  
	string codigo = new string (mens_img.getodigo());	
	
    os 	<< "Código: " 	 	<< codigo 					  	<< '\n' 
   		<< "Fecha: " 		<< mens_img.getfechaMensaje() 	<< '\n' 
   		<< "Hora: " 		<< mens_img.gethoraMensaje()  	<< '\n'
   		<< "Duración: " 	<< mens_img.getFormato()  		<< '\n'
   		<< "Tamaño: " 		<< mens_img.getTamanio()  		<< '\n'
   		<< "Texto: " 		<< mens_img.getTextMulti()  	<< '\n'
   		<< "URL: " 			<< mens_img.getURLpicture(); 
    return os;  
}