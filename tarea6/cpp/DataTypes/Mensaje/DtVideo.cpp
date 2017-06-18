#include "DtVideo.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

DtVideo::DtVideo (IKey codigo, Fecha fecha, Hora hora, int duracion, String urlvideo) : DtMensaje (codigo, fecha, hora) {
	this->dtCodigo 	    = codigo;
	this->dtFecha 	    = new Fecha(fecha->getdia(), fecha->getmes(), fecha->getanio());
	this->dtHora 	  	= new Hora(hora->gethoras(), hora->getminutos());
	this->dtDuracion    = duracion;
	this->dtURLvideo    = urlvideo;
}

DtVideo::~DtVideo () {}

int DtVideo::getDuracion() {
	return dtDuracion;
}
String DtVideo::getURLvideo() {
	return dtURLvideo;
}