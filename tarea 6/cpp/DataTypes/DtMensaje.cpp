#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMensaje.h"

using namespace std;

int DtMensaje::getCodigo() const{
	return dtCodigo;
}

Fecha DtMensaje::getFecha() const{
	return dtFecha;
}

Hora DtMensaje::getHora() const{
	return dtHora;
}

void DtMensaje::setCodigo (int codigo) {
	this->dtCodigo = codigo;
}

void DtMensaje::setFecha (Fecha fecha) {
	this->dtFecha = fecha;
}

void DtMensaje::setHora (Hora hora) {
	this->dtHora = hora;
}
