#include "DtImagen.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

DtImagen::DtImagen (string codigo, Fecha fecha, Hora hora, string formato, int tamanio, string textmulti, string urlpicture) : DtMensaje (codigo, fecha, hora) {
	this->dtCodigo 	   = codigo;
	this->dtFecha 	   = fecha;
	this->dtHora 	   = hora;
	this->dtFormato    = formato;
	this->dtTamanio    = tamanio;
	this->dtTextMulti  = textmulti;
	this->dtURLpicture = urlpicture;
}

DtImagen::~DtImagen () {}

string DtImagen::getFormato() {
	return dtFormato;
}
int DtImagen::getTamanio() {
	return dtTamanio;
}
string DtImagen::getTextMulti()  {
	return dtTextMulti;
}
string DtImagen::getURLpicture()  {
	return dtURLpicture;
}

void DtImagen::setFormato (string formato) {
	this->dtFormato = formato;
}
void DtImagen::setTamanio (int tamanio) {
	this->dtTamanio = tamanio;
}
void DtImagen::setTextMulti (string text_multi) {
	this->dtTextMulti = text_multi;
}
void DtImagen::setURLpicture (string url) {
	this->dtURLpicture = url;
}	