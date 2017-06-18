#include <iostream>
#include <cstring>
#include <string.h>

#include "../../../h/DataTypes/Mensaje/DtVideo.h"

using namespace std;

DtVideo::DtVideo (IKey codigo, Fecha fecha, Hora hora, int duracion, string urlvideo) {
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
string DtVideo::getURLvideo() {
	return dtURLvideo;
}