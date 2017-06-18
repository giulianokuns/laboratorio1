#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "../../../h/DataTypes/Mensaje/DtMensaje.h"
#include "../../../h/DataTypes/Mensaje/DtSimple.h"

using namespace std;

DtSimple::DtSimple (string codigo, Fecha fecha, Hora hora, string text_simple) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 = codigo;
	this->dtFecha 	 = fecha;
	this->dtHora 	 = hora;
	this->dtTextSimp = text_simple;
}

DtSimple::~DtSimple () {}

string  DtSimple::getTextSimp() {
	return dtTextSimp;
}
