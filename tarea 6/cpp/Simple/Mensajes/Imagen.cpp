#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Imagen.h"

using namespace std;

Imagen::Imagen (String codigo, Fecha fecha, Hora hora, String formato, int tamanio, String textmulti, String urlpicture) : Mensaje (codigo, fecha, hora) {
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