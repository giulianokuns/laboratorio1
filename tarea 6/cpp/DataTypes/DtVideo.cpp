#include "DtVideo.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

DtVideo::DtVideo (string codigo, Fecha fecha, Hora hora, int duracion, string urlvideo) : DtMensaje (codigo, fecha, hora) {
	this->dtCodigo 	    = codigo;
	this->dtFecha 	    = fecha;
	this->dtHora 	  	= hora;
	this->dtDuracion    = duracion;
	this->dtURLvideo    = urlvideo;
}

DtVideo::~DtVideo () {}

int DtVideo::getDuracion() {
	return dtDuracion;
}
string DtVideo::getURLvideo() {
	return dtURLvideo;
}

void DtVideo::setDuracion (int duracion) {
	this->dtDuracion = duracion;
}
void DtVideo::setURLvideo (string url) {
	this->dtURLvideo = url;
}