#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "DtImagen.h"

using namespace std;

DtImagen::DtImagen (String codigo, Fecha fecha, Hora hora, String formato, int tamanio, String textmulti, String urlpicture) : DtMensaje (codigo, fecha, hora) {
	this->dtCodigo 	   = codigo;
	this->dtFecha 	   = fecha;
	this->dtHora 	   = hora;
	this->dtFormato    = formato;
	this->dtTamanio    = tamanio;
	this->dtTextMulti  = textmulti;
	this->dtURLpicture = urlpicture;
}

DtImagen::~DtImagen () {}

String DtImagen::getFormato() {
	return dtFormato;
}
int DtImagen::getTamanio() {
	return dtTamanio;
}
String DtImagen::getTextMulti()  {
	return dtTextMulti;
}
String DtImagen::getURLpicture()  {
	return dtURLpicture;
}