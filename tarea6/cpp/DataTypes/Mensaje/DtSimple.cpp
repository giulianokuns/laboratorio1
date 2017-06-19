#include <iostream>
#include "../../../h/DataTypes/Mensaje/DtSimple.h"
#include "../../../h/DataTypes/Mensaje/DtMensaje.h"

using namespace std;

DtSimple::DtSimple (string codigo, Fecha *fecha, Hora *hora, string text_simple) {
	this->setCodigo(codigo);
	this->setFecha(fecha);
	this->setHora(hora);
	this->dtTextSimp = text_simple;
}

//DtSimple::~DtSimple () {}

string DtSimple::getTextSimp() const{
	return dtTextSimp;
}