#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "DtSimple.h"
#include "DtMensaje.h"

using namespace std;

DtSimple::DtSimple (IKey codigo, Fecha fecha, Hora hora, String text_simple) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 = codigo;
	this->dtFecha 	 = fecha;
	this->dtHora 	 = hora;
	this->dtTextSimp = text_simple;
}

DtSimple::~DtSimple () {}

String  DtSimple::getTextSimp() {
	return dtTextSimp;
}
