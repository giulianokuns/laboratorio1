#include "DtSimple.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

DtSimple::DtSimple (string codigo, Fecha fecha, Hora hora, string text_simple) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 = codigo;
	this->dtFecha 	 = new Fecha(fecha->getdia(), fecha->getmes(), fecha->getanio());
	this->dtHora 	 = new Hora(hora->gethoras(), hora->getminutos());
	this->dtTextSimp = text_simple;
}

DtSimple::~DtSimple () {}

string  DtSimple::getTextSimp() {
	return dtTextSimp;
}
