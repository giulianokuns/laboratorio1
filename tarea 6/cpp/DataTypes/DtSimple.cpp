#include "DtSimple.h"
#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

using namespace std;

DtSimple::DtSimple (String codigo, Fecha fecha, Hora hora, String text_simple) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 = codigo;
	this->dtFecha 	 = fecha;
	this->dtHora 	 = hora;
	this->dtTextSimp = text_simple;
}

DtSimple::~DtSimple () {}

String  DtSimple::getTextSimp() {
	return dtTextSimp;
}
