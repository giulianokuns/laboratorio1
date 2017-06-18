#include "../../../h/DataTypes/Mensaje/DtMensaje.h"

DtMensaje::DtMensaje (string dtcodigo, Fecha &dtfecha, Hora &dthora) {
	this->dtCodigo 	= dtcodigo;
	this->dtFecha 	= dtfecha;
	this->dtHora 	= dthora;
}

string DtMensaje::getCodigo() const {
	return dtCodigo;
}

Fecha DtMensaje::getFecha() const {
	return dtFecha;
}

Hora DtMensaje::getHora() const {
	return dtHora;
}