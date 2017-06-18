#include "../../../h/DataTypes/Mensaje/DtMensaje.h"

DtMensaje::DtMensaje(string dtcodigo, Fecha &fecha, Hora &hora) {
	this->dtCodigo 	= dtcodigo;
	this->dtFecha 	= new Fecha(fecha->getdia(), fecha->getmes(), fecha->getanio());					
	this->dtHora  	= new Hora(hora->gethoras(), hora->getminutos());
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